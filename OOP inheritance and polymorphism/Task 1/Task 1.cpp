#include <iostream>
#include <string>


class Figure
{
protected:
	int numberOfSides_ = 0;
	std::string nameOfFigure_;

public:
	Figure() : Figure(0, "Фигура") {};
	Figure(int numberOfSides, std::string nameOfFigure)
	{
		numberOfSides_ = numberOfSides;
		nameOfFigure_ = nameOfFigure;
	};

	int getNumberOfSides() const { return numberOfSides_; } 

	std::string getNameOfFigure() const { return nameOfFigure_; } 
};

class Triangle : public Figure
{
public:

	Triangle() : Figure(3, "Треугольник") {};

};

class Quadrilateral : public Figure
{
public:

	Quadrilateral() : Figure(4, "Четырехугольник") {};
};

void print(Figure& PF) 
{
	std::cout << PF.getNameOfFigure() << ": " << PF.getNumberOfSides() << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");

	std::cout << std::endl << "Количество сторон: " << std::endl;

	Figure Figure1;
	print(Figure1);

	Triangle Triangle1;
	print(Triangle1);

	Quadrilateral Quadrilateral1;
	print(Quadrilateral1);
};