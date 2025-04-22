#include <iostream>
#include <string>

class Figure
{
protected:
	std::string nameOfFigure = "Фигура";
	bool checkFigure = false;
	int quantityOfSides = 0;
	int sideLengthA_ = 0;
	int sideLengthB_ = 0;
	int sideLengthC_ = 0;
	int sideLengthD_ = 0;
	int angleA_ = 0;
	int angleB_ = 0;
	int angleC_ = 0;
	int angleD_ = 0;

	virtual bool metodCheckFigure() 
	{
		if (quantityOfSides == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	};


public:
	//Геттеры
	std::string getNameOfFigure() { return nameOfFigure; }

	int getSideLengthA() { return sideLengthA_; }
	int getSideLengthB() { return sideLengthB_; }
	int getSideLengthC() { return sideLengthC_; }
	int getSideLengthD() { return sideLengthD_; }

	int getAngleA() { return angleA_; }
	int getAngleB() { return angleB_; }
	int getAngleC() { return angleC_; }
	int getAngleD() { return angleD_; }

	virtual void printFigure() 
	{
		std::cout << std::endl;
		std::cout << nameOfFigure << ":" << std::endl;
		if (metodCheckFigure())
		{
			std::cout << "Правильный" << std::endl;
		}
		else { std::cout << "Неправильный" << std::endl; }

		std::cout << "Количество сторон: " << quantityOfSides << std::endl;
	}

	virtual void printSides()
	{
		std::cout << "Стороны:";
		std::cout << " a = " << sideLengthA_ << ", b = " << getSideLengthB() << ", с = " << getSideLengthC();
		std::cout << std::endl;
	}

	virtual void printAngles()
	{
		std::cout << "Углы:";
		std::cout << " А = " << getAngleA() << ", В = " << getAngleB() << ", С = " << getAngleC();
		std::cout << std::endl;
	}

};

class Triangle : public Figure
{
protected:
	bool metodCheckFigure() override 
	{
		if ((angleA_ + angleB_ + angleC_) == 180)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	
	Triangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
	{
		nameOfFigure = "Треугольник";
		sideLengthA_ = sideLengthA;
		sideLengthB_ = sideLengthB;
		sideLengthC_ = sideLengthC;
		angleA_ = angleA;
		angleB_ = angleB;
		angleC_ = angleC;
		quantityOfSides = 3;
		checkFigure = metodCheckFigure();
	}

	void printFigure() override 
	{
		Figure::printFigure();
	}

	void printSides() override
	{
		Figure::printSides();
	}

	void printAngles() override
	{
		Figure::printAngles();
	}
};

class RightTriangle : public Triangle
{
protected:
	bool metodCheckFigure() override
	{
		if (Triangle::metodCheckFigure() && (angleC_ == 90))
		{
			return true;
		}
		else
		{
			return false;
		};
	};

public:
	RightTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::nameOfFigure = "Прямоугольный треугольник";
	};
};

class IsoscelesTriangle : public Triangle
{
protected:
	bool metodCheckFigure() override
	{
		if (Triangle::metodCheckFigure() && (sideLengthA_ == sideLengthC_ && angleA_ == angleC_))
		{
			return true;
		}
		else
		{
			return false;
		};
	};

public:
	IsoscelesTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::nameOfFigure = "Равнобедренный треугольник";
	};
};

class EquilateralTriangle : public Triangle
{
private:
	bool CheckEquilateralTriangle()
	{
		if ((sideLengthA_ == sideLengthB_ && sideLengthB_ == sideLengthC_) && ((angleA_ == 60) && (angleA_ = 60) && (angleC_ = 60)))
		{
			return (sideLengthA_ == sideLengthB_ && sideLengthB_ == sideLengthC_) && (angleA_ == 60 && angleB_ == 60 && angleC_ == 60);
		}
		else
		{
			return false;
		};
	}

public:
	EquilateralTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::nameOfFigure = "Равносторонний треугольник";
	};
protected:
	bool metodCheckFigure() override
	{
		if (Triangle::metodCheckFigure() && (CheckEquilateralTriangle()))
		{
			return true;
		}
		else
		{
			return false;
		};
	};



};

class Quadrilateral : public Figure
{
protected:
	virtual bool metodCheckFigure()
	{
		if ((angleA_ + angleB_ + angleC_ + angleD_) == 360)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	
	bool metodCheckSideLengthACiBD()
	{
		if (sideLengthA_ == sideLengthC_ && sideLengthB_ == sideLengthD_)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	
	bool metodCheckSideLengthACBD()
	{
		if (sideLengthA_ == sideLengthB_ && sideLengthB_ == sideLengthC_ && sideLengthC_ == sideLengthD_)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	
	bool metodCheckAngleabcd90()
	{
		if (angleA_ == 90 && angleB_ == 90 && angleC_ == 90 && angleD_ == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	
	bool metodCheckAngleACiBD()
	{
		if (angleA_ == angleC_ && angleB_ == angleD_)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	Quadrilateral(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
	{
		nameOfFigure = "Четырехугольник";

		quantityOfSides = 4;
		sideLengthA_ = sideLengthA;
		sideLengthB_ = sideLengthB;
		sideLengthC_ = sideLengthC;
		sideLengthD_ = sideLengthD;

		angleA_ = angleA;
		angleB_ = angleB;
		angleC_ = angleC;
		angleD_ = angleD;
	}

	void printFigure() override
	{
		Figure::printFigure();
	}

	void printSides() override
	{
		Figure::printSides();
	}

	void printAngles() override
	{
		Figure::printAngles();
	}

};

class Rectangle : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleabcd90())
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	Rectangle(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Прямоугольник";
	}
};

class Square : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleabcd90())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
public:
	Square(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Квадрат";
	}
};

class Parallelogram : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleACiBD())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Parallelogram(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Параллелограмм";
	}
};

class Rhomb : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleACiBD())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Rhomb(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Ромб";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian"); 
	system("chcp 1251");
	system("cls");

	Figure Figure1;
	Figure1.printFigure();
	Figure1.printSides();
	Figure1.printAngles();

	Triangle Triangle1(10, 20, 30, 50, 60, 70);
	Triangle1.printFigure();
	Triangle1.printSides();
	Triangle1.printAngles();

	RightTriangle rightTriangle1(10, 20, 30, 50, 60, 90);
	rightTriangle1.printFigure();
	rightTriangle1.printSides();
	rightTriangle1.printAngles();

	RightTriangle rightTriangle2(10, 20, 30, 50, 40, 90);
	rightTriangle2.printFigure();
	rightTriangle2.printSides();
	rightTriangle2.printAngles();

	IsoscelesTriangle isoscelesTriangle1(10, 20, 10, 50, 60, 90);
	isoscelesTriangle1.printFigure();
	isoscelesTriangle1.printSides();
	isoscelesTriangle1.printAngles();

	EquilateralTriangle equilateralTriangle1(30, 30, 30, 60, 60, 60);
	equilateralTriangle1.printFigure();
	equilateralTriangle1.printSides();
	equilateralTriangle1.printAngles();

	Quadrilateral Quadrilateral1(10, 20, 30, 40, 50, 60, 70, 80);
	Quadrilateral1.printFigure();
	Quadrilateral1.printSides();
	Quadrilateral1.printAngles();

	Rectangle Rectangle1(10, 20, 10, 20, 90, 90, 90, 90);
	Rectangle1.printFigure();
	Rectangle1.printSides();
	Rectangle1.printAngles();

	Square Square1(20, 20, 20, 20, 90, 90, 90, 90);
	Square1.printFigure();
	Square1.printSides();
	Square1.printAngles();

	Parallelogram Parallelogram1(20, 30, 20, 30, 30, 40, 30, 40);
	Parallelogram1.printFigure();
	Parallelogram1.printSides();
	Parallelogram1.printAngles();

	Rhomb Rhomb1(30, 30, 30, 30, 30, 40, 30, 40);
	Rhomb1.printFigure();
	Rhomb1.printSides();
	Rhomb1.printAngles();
}