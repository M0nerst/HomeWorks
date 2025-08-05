#include "FileName.h"

SmartArray::SmartArray(const int sizeOfArray)
{
	sizeOfArray_ = sizeOfArray;

	std::cout << this << " - Создание SmartArray::SmartArray(int SizeOfArray)";
	smArray_ = new int[sizeOfArray] {};

	//заполняем массив значениями равными индексам
	for (int i = 0; i < sizeOfArray; i++)
	{
		smArray_[i] = i;
	}
	std::cout << std::endl;
};

SmartArray::~SmartArray()
{
	delete[] smArray_;
	std::cout << this << " - Уничтожение SmartArray::~SmartArray()\n\n";
};

// To print smartArray
void SmartArray::smartArrayPrint()
{
	for (int i = 0; i < sizeOfArray_; i++)
		std::cout << smArray_[i] << " ";

	std::cout << std::endl;
};

void SmartArray::smartArrayPushBack(const int addingElement)
{
	if (countForPushBack_ >= sizeOfArray_)
	{
		throw std::out_of_range("PushBack - Out_of_range");
	}
	else
	{
		smArray_[countForPushBack_] = addingElement;
		++countForPushBack_;
	}
};

int SmartArray::smartArrayGetElement(const int gettingElementByIndex)
{
	if ((gettingElementByIndex >= sizeOfArray_) || (gettingElementByIndex < 0))
	{
		throw std::out_of_range("GetElement - Out_of_range");
	}
	else
	{
		return smArray_[gettingElementByIndex];
	}
};