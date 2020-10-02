#include "include/tensor.h"
#include<iostream>
int main()
{
	
	const size_t t = 2;
	std::array<size_t, 2> b{ 2, 2 };
	tensor<int, 2> a(b); 
	
	a = a + a;
	
	std::cout << (a.at(2, 1))<< std::endl;
}