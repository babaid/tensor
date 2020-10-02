#pragma once

#include<array>
#include<list>
#include<iostream>
#include<assert.h>



template<typename T, size_t Dim>
class tensor
{
public:

	tensor() = default;
	tensor(std::array<size_t, Dim>);

	//Element acces to 2-Dim and 3-Dim tensors

	virtual  int& at(size_t, size_t);
	virtual  int& at(size_t, size_t, size_t);

	//Tensor operators
	tensor<T, Dim> operator+(const tensor<T, Dim>&) const;
	tensor<T, Dim> operator-(const tensor<T, Dim>&) const;
	tensor<T, Dim> operator*(const tensor<T, Dim>&) const;

	//Element-wise operators
	tensor<T, Dim> operator+(const T&) const;
	tensor<T, Dim> operator-(const T&) const;
	tensor<T, Dim> operator*(const T&) const;
	tensor<T, Dim> operator/(const T&) const;

	//It is possible to pass a list to a tensor, right now you have to reshape it afterwards TODO
	void operator=(const std::list<T>& Right);

	
	
	
private:
	//Shape of the tensor and the data stored in it.
	std::array<size_t, Dim> Shape_;	
	std::list<T> data;

};

template<typename T, size_t Dim>
inline tensor<T, Dim>::tensor(std::array<size_t, Dim> shape):Shape_(shape)
{
	for (int i = 0; i < 10; ++i) data.push_back(i);
}

template<typename T, size_t Dim>
inline void tensor<T, Dim>::operator=(const std::list<T>& Right)
{
	
	if (Right.size() != this->data.size())
		assert(Right.size());
	else
		this->data = Right;
	

}

template<typename T, size_t Dim>
inline int& tensor<T, Dim>::at(size_t i, size_t j)
{
	assert(!data.empty());
	assert(Dim == 2);
	typename std::list<T>::iterator it = data.begin();
	std::advance(it, (i - 1) * Shape_[1] + j - 1);
	
	return (*it);

	
}

template<typename T, size_t Dim>
inline  int& tensor<T, Dim>::at(size_t i, size_t j, size_t k)
{
	assert(Dim == 3);
	typename std::list<T>::iterator it = data.begin();
	std::advance(it,(k-1)*Shape_[0]*Shape_[1] + Shape_[1]*(i - 1) + j - 1);
	return (*it);
}

template<typename T, size_t Dim>
inline tensor<T, Dim> tensor<T, Dim>::operator+(const tensor<T, Dim>& right) const
{
	tensor<T, Dim> temp = *this;
	assert(Shape_ == right.Shape_);
	
	for (auto elem = std::make_pair(temp.data.begin(), right.data.begin()); elem.first != temp.data.end(); ++elem.first, ++elem.second)
	{
		*elem.first += *elem.second;
	}

	return temp;
}

template<typename T, size_t Dim>
inline tensor<T, Dim> tensor<T, Dim>::operator-(const tensor<T, Dim>&) const
{
	tensor<T, Dim> temp = *this;
	assert(Shape_ == right.Shape_);

	for (auto elem = std::make_pair(temp.data.begin(), right.data.begin()); elem.first != temp.data.end(); ++elem.first, ++elem.second)
	{
		*elem.first -= *elem.second;
	}

	return temp;
}

template<typename T, size_t Dim>
inline tensor<T, Dim> tensor<T, Dim>::operator+(const T& val) const
{
	tensor<T, Dim> temp = *this;
	for (auto elem = temp.data.begin(); elem != temp.data.end(); ++elem)
		*elem += val;
	return temp;
}

template<typename T, size_t Dim>
inline tensor<T, Dim> tensor<T, Dim>::operator-(const T&) const
{
	tensor<T, Dim> temp = *this;
	for (auto elem = temp.data.begin(); elem != temp.data.end(); ++elem)
		*elem -= val;
	return temp;
}

template<typename T, size_t Dim>
inline tensor<T, Dim> tensor<T, Dim>::operator*(const T&) const
{
	tensor<T, Dim> temp = *this;
	for (auto elem = temp.data.begin(); elem != temp.data.end(); ++elem)
		*elem *= val;
	return temp;
}

template<typename T, size_t Dim>
inline tensor<T, Dim> tensor<T, Dim>::operator/(const T&) const
{
	tensor<T, Dim> temp = *this;
	for (auto elem = temp.data.begin(); elem != temp.data.end(); ++elem)
		*elem /= val;
	return temp;
}


