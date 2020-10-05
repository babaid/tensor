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
#include "exceptions/exceptions.h"

/*matrix is the type of matrices, matrix is an element of the namespace dtensor.
*
* Just like the tensor objects, it has a very similar syntax:
*	dtensor::matrix<double, 2, 4> mat; //An uninitilized 2x4 matrix.
* 
* The dtensor namespace also contains a huge amount of functions dealing with matrices. Or at least it will.
* TODO: kronecker prod. for matrices, various norms, different initializing functions like Rand({range...}), Zeros(), Diag({args...})
*/
template<typename T, size_t M, size_t N>
class matrix : public tensor<T, M, N>
{
	public:
	matrix() = default;
	matrix(tensor_core::marray <T, M, N> mat):tensor<T, M, N>{mat} {}
	matrix(matrix<T, M, N>&&) = default;
	matrix(matrix<T, M, N>&) = default;
	~matrix() = default;

	

	T& operator[](size_t);
	T& operator()(size_t, size_t);
	//matrix<T> kron(matrix<T>&, matrix<T>&) override;


};










template<typename T, size_t M, size_t N>
inline T& matrix<T, M, N>::operator[](size_t a)
{
	if (a > M * N) throw(std::out_of_range("Out_of_range: You tried to access a matrix of size M*N. Index was out of range."));
	size_t cnt = 0; 
	for (size_t i = 0; i < M; ++i)
	{
		for (size_t j = 0; j < N; ++j)
		{
			++cnt;
			if (cnt == a) return this->_data[i][j];
			else continue;
		}
	}
	
}
template<typename T, size_t M, size_t N>
inline T& matrix<T, M, N>::operator()(size_t i, size_t j)
{
	if (i > M || j > N || i == 0 || j == 0) throw(std::out_of_range("Out_of_range: Your indices are out of Range. Pay attention to the dimensions of your matrix."));
	
	
	return this->_data[i-1][j-1];
	// TODO: hier return-Anweisung eingeben
}
