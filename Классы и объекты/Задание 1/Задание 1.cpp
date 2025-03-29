
#include <iostream>
#include <iomanip>
#include <conio.h>


class Calculator 
{
private:
    double num1 = 1;
    double num2 = 1;

public:
    double add()
    {
        return num1 + num2;
    }

    double multiply()
    {
        return num1 * num2;
    }

    double subtract_1_2()
    {
        return num1 - num2;
    }

    double subtract_2_1()
    {
        return num2 - num1;
    }

    double divide_1_2()
    {
        return num1 / num2;
    }

    double divide_2_1()
    {
        return num2 / num1;
    }

    bool set_num1(double num_1)
    {
        if (num_1 != 0)
        {
            num1 = num_1;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool set_num2(double num_2)
    {
        if (num_2 != 0)
        {
            num2 = num_2;
            return true;
        }
        else
        {
            return false;
        }
    }
};


void printResult(double result)
{
    std::cout << result << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian"); 

    double num_1 = 0;
    double num_2 = 0;

    Calculator result;

    while (true) 
    {
        std::cout << std::endl; 

        do //Проверка num1 равенства нулю
        {
            std::cout << "Введите num1: ";
            std::cin >> num_1;
            if (!result.set_num1(num_1))
            {
                std::cout << "Неверный ввод! " << std::endl;
            };
        } while (!result.set_num1(num_1));

        do //Проверка num2 равенства нулю
        {
            std::cout << "Введите num2: ";
            std::cin >> num_2;
            if (!result.set_num2(num_2))
            {
                std::cout << "Неверный ввод! " << std::endl;
            };
        } while (!result.set_num2(num_2));

        result.add(); //Используем метод из класса Calculator
        std::cout << std::endl << "num1 + num2 = "; //Печатаем в консоль
        printResult(result.add()); //Печатаем результат в консоль

        result.multiply();
        std::cout << "num1 * num2 = ";
        printResult(result.multiply());

        result.subtract_1_2();
        std::cout << "num1 - num2 = ";
        printResult(result.subtract_1_2());

        result.subtract_2_1();
        std::cout << "num2 - num1 = ";
        printResult(result.subtract_2_1());

        result.divide_1_2();
        std::cout << "num1 / num2 = ";
        printResult(result.divide_1_2());

        result.divide_2_1();
        std::cout << "num2 / num1 = ";
        printResult(result.divide_2_1());

        std::cout << std::endl;

        std::cout << "Нажмите любую клавишу, чтобы продолжить или закройте программу\n";
        _getch();

    }
}
