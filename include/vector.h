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

	template<typename T, size_t N>
	class vector : public tensor<T, 1, N>
	{
	public:
		vector() = default;
		vector(tensor_core::marray<T, 1, N> v) :_VA(0), tensor<T, 1, N>{v} {};
		vector(tensor_core::marray<T, N, 1> v) :_VA(1), tensor<T, N, 1>{v} {};
		vector(const vector<T>&) = default;
		vector(vector<T>&&) = default;
		~vector() = default;

		vector<T> operator+(const vector<T>&) const;
		vector<T>& operator=(const vector<T>&);		
		T& operator()(size_t);
		size_t size();

		//Linear algebra functionality

		T norm();
		T dot(vector<T>&, vector<T>&) const;	
		vector<T> kron(const vector<T>&, const vector<T>&) override;
	protected:
		VectorAlign _VA;
	};

	
