#include "include/tensor.h"
#include "include/vector.h"
#include<iostream>
int main()
{
	
	const size_t t = 2;
	std::array<size_t, 2> b{ 3, 1 };
	vector<double> a(3);
	a(1) = 2;
	a = a + a ;
	
	std::cout << (a(1))<< std::endl;
}