#include <iostream>
#include <cstring>
#include "HeadingOfNumbers.h"


int main()
{
    setlocale(LC_ALL, "Russian"); 
    system("chcp 1251");
    system("cls");

    double firstNumber = 0;
    double secondNumber = 0;
    int operationSelection = 0;
    std::string nameOfOperation;
    bool checkingValue = false;
    bool checkingNumber = false;
    
    do{
        std::cout << "Введите первое число: ";
        while (!(std::cin >> firstNumber))
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Необходимо именно число." << std::endl;
            std::cout << "Итак, первое число: ";
        }

        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout << "Введите второе число: ";
        while (!(std::cin >> secondNumber))
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ты сможешь!" << std::endl;
            std::cout << "Итак, второе число: ";
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        checkingNumber = true;
    } while (!checkingNumber);


    do
    {
        std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
        std::cin >> operationSelection;

       

        if (operationSelection == 4 && secondNumber == 0  || operationSelection == 3 && secondNumber == 0)
        {
            std::cout << "Что, в школе не учился?" << std::endl;
        }
        else if (firstNumber == 0 && operationSelection == 4)
        {
            std::cout << "Я тоже об этом подумал :)" << std::endl;                      //Тут же можно множество шуток придумать с числом "0", можно я не буду их все прописывать?
        }
        else if (operationSelection <= 5 && operationSelection >= 1)
        {
            checkingValue = true;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Как сложно попасть по нужным цифрам xD" << std::endl;
        }        
    } while (!checkingValue);

    switch (operationSelection)
    {
    case(1):
    {
        nameOfOperation = "плюс";
        break;
    }
    case(2):
    {
        nameOfOperation = "минус";
        break;
    }
    case(3):
    {
        nameOfOperation = "умножить";
        break;
    }
    case(4):
    {
        nameOfOperation = "разделить";
        break;
    }
    case(5):
    {
        nameOfOperation = "в степени";
        break;
    }
    };

    std::cout << firstNumber << " " << nameOfOperation << " " << secondNumber << " = ";

    if (operationSelection == 1)
    {
        std::cout << addition(firstNumber, secondNumber);
    }
    else if (operationSelection == 2)
    {
        std::cout << subtraction(firstNumber, secondNumber);
    }
    else if (operationSelection == 3)
    {
        std::cout << multiplication(firstNumber, secondNumber);
    }
    else if (operationSelection == 4)
    {
        std::cout << division(firstNumber, secondNumber);
    }
    else
    {
        std::cout << exponentiation(firstNumber, secondNumber);
    };

};