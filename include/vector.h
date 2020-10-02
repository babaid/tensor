#include "tensor.h"

template<typename T>
class vector : public tensor<T, 1>
{
public:

private:
	std::list<T> data;	
};