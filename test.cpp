#include "include/matrix.h"
#include<iostream>
using namespace tensor_core;

int main()
{
	
	marray<int, 2, 2> x;
	int cnt = 1;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			x[i][j] = cnt;
			cnt++;
		}
	}
	marray<int, 1, 10> a;
	matrix<int, 2, 2> b(x);
	try {
		std::cout << b[5];
	}
	catch (std::out_of_range& orr)
	{
		std::cout  << orr.what();
	}
}