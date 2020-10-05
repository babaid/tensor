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

#include<array>
#include<iostream>
#include<assert.h>
#include<vector>


/*Marray is the basic multidimensional array structure wich is the base of all tensor objects. It is part of the tensor_core namespace
Based on Variadic templates and std::array;
You can use it basically as the STL array container except it provides easy to use multi...Dimensionensional capabilitie1, ,2 ,3 s,.4, 5, 6},{7, 8, 9}
The use of it:
	
	tensor_core::<int, 3, 3> mat = {{1, ,2 ,3 },{4, 5, 6},{7, 8, 9}}; //creates a 3x3 raw matrix
	mat[0][1] = 10; //element-access */
namespace tensor_core {
	template<typename T, size_t ...Dimension> struct marray;
	template<typename T, size_t First>
	struct marray <T, First>{

		//typedef T type[First];
		//type* data = new type;



		//typedef T type[First];
		//type data;
		typedef typename std::array<T, First> ActualArray;
		ActualArray data;
		T& operator[](size_t i) { return data[i]; }
		T& at(size_t i) { return data.at(i); }

	};

	template<typename T, size_t First, size_t ...Last>
	struct marray<T, First, Last...> {

		
		typedef typename marray<T, Last...> SubArray;
		//typedef typename marray<T, Last...>::type SubArray;
		
		
		//typedef SubArray type[First];
		//SubArray* data = new type;
		
		std::array<SubArray, First> data;
		SubArray& operator[](size_t i) { return data[i]; }
		SubArray& at(size_t i) { return data.at(i); }
	};





	

}
namespace dtensor {

	template<typename T, size_t ...Dimension> class tensor;
	/*Tensor is the base of all tensor-like objects such us matrices, vectors, or higher dimensional types.
	*The use of tensor is pretty simple:
	*	tensor<double, 2, 2, 2> tens; //A 3D tensor with size 2x2x2
	*
	* I still need to implement a loop wich iterates over every element of a tensor.
	I have to decide between a variadic template with recursion, or maybe something simpler such as the help of a counter vector.
	*
	*
	*/
	template<typename T, size_t ...Dimension>
	class tensor
	{
	public:
		tensor() = default;
		tensor(tensor_core::marray<T, Dimension...>);
		virtual tensor<T, Dimension...>& operator=(const tensor<T, Dimension...>&);
		virtual ~tensor() = default;

		/*//Tensor operators
		virtual tensor<T,Dimension...> operator+(const tensor<T, Dimension...>&) const;
		virtual tensor<T, Dimension...> operator-(const tensor<T, Dimension...>&) const;
		//Element-wise operators
		virtual tensor<T,Dimension...> operator+(const T&) const;
		virtual	tensor<T,Dimension...> operator-(const T&) const;
		virtual tensor<T, Dimension...> operator*(const T&) const;
		virtual tensor<T, Dimension...> operator/(const T&) const;

		*/

	protected:
		tensor_core::marray<T, Dimension...> _data;
	private:
		std::vector<size_t> dimensions{ Dimension... };

	};







	template<typename T, size_t ...Dimension>
	inline tensor<T, Dimension...>::tensor(tensor_core::marray<T, Dimension...> base_array) : _data(base_array)
	{

	}

	template<typename T, size_t ...Dimension>
	inline tensor<T, Dimension...>& tensor<T, Dimension...>::operator=(const tensor<T, Dimension...>& rval)
	{
		tensor<T, Dimension...> temp;
		temp._data = rval._data;
		return temp;

	}


}
