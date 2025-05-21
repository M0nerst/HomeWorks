#pragma once
#include <stdexcept>
#include "Figure.h"


class MyException : public std::domain_error
{
public:
	using std::domain_error::domain_error;
	
};