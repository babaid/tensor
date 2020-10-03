/*************************************************************************************
 * Tensor - A library written in modern C++ to get work done with tensors.           *
 * Copyright (C) 2020 Dezsoe Babai <de.babai2000@gmail.com>							 *
 *                                                                                   *
 * This file is part of tensor.                                                      *
 *                                                                                   *
 * Tensor is free software; you can redistribute it and/or modify it under the       *
 * terms of the GNU General Public License as published by the Free Software         *
 * Foundation; either version 2 of the License, or (at your option) any later        *
 * version.                                                                          *
 *                                                                                   *
 * Tensor is distributed in the hope that it will be useful, but WITHOUT ANY         *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A   *
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.          *
 *************************************************************************************/
#pragma once
#include "tensor.h"


	template<typename T>
	class vector : public tensor<T, 2>
	{
	public:
		vector();
		vector(size_t);
		vector(const vector&) = default;
		vector(vector&&) = default;

		vector<T> operator+(const vector<T>&) const;
		vector<T>& operator=(const vector<T>&);
		//
		T& at(size_t);

		//Linear algebra functionality

		T norm();
		T dot();
		T norm_inf();


	};

	template<typename T>
	inline vector<T>::vector(): tensor<T, 2>{{0, 1}}
	{
	}

	template<typename T>
	inline vector<T>::vector(size_t len) : tensor<T, 2>{ {len, 1} }
	{

	}

	template<typename T>
	inline vector<T> vector<T>::operator+(const vector<T>& right) const
	{
		assert(this->shape_ == right.shape_);
		vector<T> temp(*this);
		for (auto elem = std::make_pair(temp.data.begin(), right.data.begin()); elem.first != temp.data.end(); ++elem.first, ++elem.second)
		{
			*elem.first += *elem.second;
		}

		return temp;
	}

	template<typename T>
	inline vector<T>& vector<T>::operator=(const vector<T>& rhs)
	{
		assert(this->shape_ == rhs.shape_);
		this->data = rhs.data;
		return *this;
		
	}

	template<typename T>
	inline T& vector<T>::at(size_t i)
	{
		typename std::list<T>::iterator it = this->data.begin();
		std::advance(it, i - 1);
		return *it;
	}

	template<typename T>
	inline T vector<T>::norm()
	{
		;
	}
