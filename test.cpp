#include "include/t_vector.h"
#include<iostream>
using namespace tensor_core;

int main()
{
	try {
		dtensor::vector<int, 2> a;
		a(1) = 1;
		a(2) = 2;
		dtensor::vector<int, 4> b = dtensor::kron(a, a);
		for (size_t i = 1; i <= 4; ++i) std::cout << b(i) << std::endl;
		
	
	}
	
	catch (std::out_of_range& orr)
	{
		std::cout << orr.what();
	}
	
}