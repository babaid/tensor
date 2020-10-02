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


	template<typename T, size_t Len>
	class vector : public tensor<T, 2>
	{
	public:
		vector();
		vector(std::array<size_t, 2>);
		//
		T norm2();
		T norm_inf();


	};

	template<typename T, size_t Len>
	inline vector<T, Len>::vector(): tensor<T, 2>{{Len, 1}}
	{
	}

	template<typename T, size_t Len>
	inline vector<T, Len>::vector(std::array<size_t, 2>)
	{
	}
