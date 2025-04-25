#include "HeadingOfNumbers.h"  //мои функции
#include <cmath>  //для вычисления корня


double addition(double firstNumber, double secondNumber)
{
	return firstNumber + secondNumber;
};

double subtraction(double firstNumber, double secondNumber)
{
	return firstNumber - secondNumber;
};

double multiplication(double firstNumber, double secondNumber)
{
	return firstNumber * secondNumber;
};

double division(double firstNumber, double secondNumber)
{
	return firstNumber / secondNumber;
};

double exponentiation(double firstNumber, double secondNumber)
{
	return std::pow(firstNumber, secondNumber);        //а есть возможность без подключения библиотек проводить такие расчёты? 
};