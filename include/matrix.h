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
class matrix : public tensor<T, 2>
{
	public:
	matrix() = default;
	matrix(size_t, size_t);
	matrix(matrix<T>&&) = default;
	matrix(matrix<T>&) = default;
	
	static matrix<T>& kron(matrix<T>&, matrix<T>&);
	T& operator()(size_t, size_t);
	
};


//Constructors
template<typename T>
inline matrix<T>::matrix(size_t, size_t) : tensor<T, 2>{ {m, n} }
{
}

template<typename T>
inline matrix<T>& matrix<T>::kron(matrix<T>&, matrix<T>&)
{
	// TODO: hier return-Anweisung eingeben
}

//Access operator
template<typename T>
inline T& matrix<T>::operator()(size_t i, size_t j)
{
	assert(!data.empty());
	typename std::list<T>::iterator it = data.begin();
	std::advance(it, (i - 1) * shape_[1] + j - 1);
	return *it;
}
