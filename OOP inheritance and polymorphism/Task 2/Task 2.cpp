#include <iostream>
#include <string>

class Figure
{
protected:
	std::string nameOfFigure_;
	bool haveFourSides_ = false;
	int sideLengthA_ = 0;
	int sideLengthB_ = 0;
	int sideLengthC_ = 0;
	int sideLengthD_ = 0;
	int angleA_ = 0;
	int angleB_ = 0;
	int angleC_ = 0;
	int angleD_ = 0;

public:
	Figure() = default;   //про это имелось в виду?
	std::string getNameOfFigure() const { return nameOfFigure_; }
	bool getHaveFourSides() const { return haveFourSides_; }

	int getSideLengthA() { return sideLengthA_; }
	int getSideLengthB() { return sideLengthB_; }
	int getSideLengthC() { return sideLengthC_; }
	int getSideLengthD() { return sideLengthD_; }

	int getAngleA() { return angleA_; }
	int getAngleB() { return angleB_; }
	int getAngleC() { return angleC_; }
	int getAngleD() { return angleD_; }
};


class Triangle : public Figure
{
public:
	
	Triangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
	{
		nameOfFigure_ = "Треугольник";
		sideLengthA_ = sideLengthA;
		sideLengthB_ = sideLengthB;
		sideLengthC_ = sideLengthC;
		angleA_ = angleA;
		angleB_ = angleB;
		angleC_ = angleC;
	}
};

class RightTriangle : public Triangle     //с маленькой было, потому что, Triangle основной класс, а right просто сторона, т.е. побочный.
{
public:
	RightTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, 90)
	{
		Triangle::nameOfFigure_ = "Прямоугольный треугольник";
	};
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int sideLengthA, int sideLengthB, int angleA, int angleB)
		: Triangle(sideLengthA, sideLengthB, sideLengthA, angleA, angleB, angleA)
	{
		Triangle::nameOfFigure_ = "Равнобедренный треугольник";
	};
};

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(int sideLengthA)
		: Triangle(sideLengthA, sideLengthA, sideLengthA, 60, 60, 60)
	{
		Triangle::nameOfFigure_ = "Равносторонний треугольник";
	};
};

class Quadrilateral : public Figure
{

public:
	Quadrilateral(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
	{
		nameOfFigure_ = "Четырехугольник";

		haveFourSides_ = true;

		sideLengthA_ = sideLengthA;
		sideLengthB_ = sideLengthB;
		sideLengthC_ = sideLengthC;
		sideLengthD_ = sideLengthD;

		angleA_ = angleA;
		angleB_ = angleB;
		angleC_ = angleC;
		angleD_ = angleD;
	}
};

class Rectangle : public Quadrilateral
{
public:
	Rectangle(int sideLengthA, int sideLengthB)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthA, sideLengthB, 90, 90, 90, 90)
	{
		Quadrilateral::nameOfFigure_ = "Прямоугольник";
	}
};

class Square : public Quadrilateral
{
public:
	Square(int sideLengthA)
		: Quadrilateral(sideLengthA, sideLengthA, sideLengthA, sideLengthA, 90, 90, 90, 90)
	{
		Quadrilateral::nameOfFigure_ = "Квадрат";
	}
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int sideLengthA, int sideLengthB, int angleA, int angleB)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthA, sideLengthB, angleA, angleB, angleA, angleB)
	{
		Quadrilateral::nameOfFigure_ = "Параллелограмм";
	}
};

class Rhomb : public Quadrilateral
{
public:
	Rhomb(int sideLengthA, int angleA, int angleB)
		: Quadrilateral(sideLengthA, sideLengthA, sideLengthA, sideLengthA, angleA, angleB, angleA, angleB)
	{
		Quadrilateral::nameOfFigure_ = "Ромб";
	}
};

void print_info(Figure& figure)
{
	std::cout << std::endl;
	std::cout << figure.getNameOfFigure() << ":" << std::endl;

	std::cout << "Стороны:";
	std::cout << " a = " << figure.getSideLengthA() << ", b = " << figure.getSideLengthB() << ", с = " << figure.getSideLengthC();
	if (figure.getHaveFourSides())
	{
		std::cout << ", d = " << figure.getSideLengthD() << std::endl;
	}
	else { std::cout << std::endl; }

	std::cout << "Углы:";
	std::cout << " А = " << figure.getAngleA() << ", В = " << figure.getAngleB() << ", С = " << figure.getAngleC();
	if (figure.getHaveFourSides()) { std::cout << ", D = " << figure.getAngleD() << std::endl; }
	else { std::cout << std::endl; }
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");

	Triangle Triangle1(10, 25, 33, 42, 57, 61);
	print_info(Triangle1);

	RightTriangle rightTriangle1(10, 20, 30, 40, 50);
	print_info(rightTriangle1);

	IsoscelesTriangle isoscelesTriangle1(11, 220, 330, 440);
	print_info(isoscelesTriangle1);

	EquilateralTriangle equilateralTriangle1(111);
	print_info(equilateralTriangle1);

	Quadrilateral Quadrilateral1(10, 20, 30, 40, 50, 60, 70, 80);
	print_info(Quadrilateral1);

	Rectangle Rectangle1(14, 24);
	print_info(Rectangle1);

	Square Square1(333);
	print_info(Square1);

	Parallelogram Parallelogram1(555, 666, 777, 888);
	print_info(Parallelogram1);

	Rhomb Rhomb1(11, 67, 33);
	print_info(Rhomb1);
}