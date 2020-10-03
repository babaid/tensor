#pragma once
#include<exception>
#include<string>

class Exception : virtual public std::exception
{
public:
	Exception(const std::string& msg) : msg_(msg) {}
	~Exception() = default;

	virtual const char* what() const noexcept override
	{
		return msg_.c_str();
	}
private:
	std::string msg_;


};