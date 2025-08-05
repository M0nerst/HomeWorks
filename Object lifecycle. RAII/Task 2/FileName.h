#pragma once

#include <iostream>
#include <string>

class SmartArray
{
private:
	int* smArray_ = 0;
	int countForPushBack_ = 0;
	int sizeOfArray_ = 0;

public:
	SmartArray(const int sizeOfArray);
	~SmartArray();

	void smartArrayPrint();
	void smartArrayPushBack(const int addingElement);
	int smartArrayGetElement(const int gettingElementByIndex);

	SmartArray(const SmartArray& other);
	SmartArray& operator=(const SmartArray& other);
};