#include "FileName.h"

SmartArray::SmartArray(int sizeOfArray)
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

void SmartArray::smartArrayPushBack(int addingElement)
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
}
SmartArray::SmartArray(SmartArray& other)
{

	this->sizeOfArray_ = other.sizeOfArray_;

	//копируем countForPushBack_ из исходного объекта
	this->countForPushBack_ = other.countForPushBack_;

	//создаем новый массив2 длинной как массив1(other) с которого копируем.
	smArray_ = new int[other.sizeOfArray_];

	//копируем элементы из массив1(other) в массив2
	for (int i = 0; i < other.countForPushBack_; i++)
	{
		this->smArray_[i] = other.smArray_[i];
	}

	std::cout << std::endl;

	std::cout << this << " - Конструктор Копирования SmartArray(const SmartArray& other)\n\n";


};

SmartArray& SmartArray::operator=(const SmartArray& other)
{
	if (this != &other)
	{
		this->sizeOfArray_ = other.sizeOfArray_;

		//копируем countForPushBack_ из исходного объекта
		this->countForPushBack_ = other.countForPushBack_;

		delete[] smArray_;

		//создаем новый массив sArr3 длинной как массив с которого копируем sArr2.
		smArray_ = new int[other.sizeOfArray_];

		//копируем элементы из sArr2 в sArr3
		for (int i = 0; i < other.countForPushBack_; i++)
		{
			this->smArray_[i] = other.smArray_[i];
		}
		std::cout << std::endl;

		std::cout << this << " - Оператор копирования SmartArray::operator=()\n\n";

		return *this;
	}
	std::cout << "Вы пытаетесь скопировaть объект сам в себя\n";

	return *this;
};