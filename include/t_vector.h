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

enum class VectorAlign {
	Col, Row
};
namespace dtensor{
	template<typename T, size_t N>
	class vector : public tensor<T, N>
	{
	public:
		vector() noexcept = default;
		vector(tensor_core::marray<T, N> v) :_VA(VectorAlign::Col), tensor<T, N>{v} {};
		vector(const vector<T, N>&) = default;
		vector(vector<T, N>&& lval) noexcept = default;
		~vector() = default;

		vector<T, N> operator+(const vector<T, N>&) const;
		vector<T, N>& operator=(const vector<T, N>&);

		T operator*(const vector<T, N>&) const;
		T& operator()(size_t);
		

		//Linear algebra functionality

		
	protected:
		VectorAlign _VA;
	};

	template<typename T, size_t N>
	inline vector<T, N> vector<T, N>::operator+(const vector<T, N>& rval) const
	{
		vector<T, N> temp = rval;
		for (size_t i = 0; i < N; ++i)
		{
			temp._data[i] += this->_data[i];
		}
		return temp;
	}

	template<typename T, size_t N>
	inline T vector<T, N>::operator*(const vector<T, N>& lval) const
	{
		T sum=0;
		for (size_t i = 0; i < N; ++i) sum += this->_data[i] * lval._data[i];
		return sum;
	}

	template<typename T, size_t N>
	inline T& vector<T, N>::operator()(size_t i)
	{
		return this->_data[i-1];
	}
	
	
	template<typename T, size_t P, size_t Q>
	vector<T, P* Q> kron(vector<T, P>& a, vector<T, Q>& b) {
		vector<T, P* Q> temp;	
		size_t cnt = 1;
		for (size_t i = 1; i <= P ; ++i)
		{
			for (size_t j = 1; j <= Q; ++j)
			{
				temp(cnt) = a(i) * b(j);
				++cnt;
			}
		}
		return temp;
	}
}