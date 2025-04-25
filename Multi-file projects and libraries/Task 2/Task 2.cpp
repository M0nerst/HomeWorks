#include <iostream>
#include <cstring>
#include "Counter.h"


int main()
{
    setlocale(LC_ALL, "Russian"); 
    system("chcp 1251");
    system("cls");

    std::string checkInitialInitValue;
    int initialInitValue = 1;
    bool checkTrueInitialInitValue = false;

  
    do
    {
        std::cout << std::endl << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::cin >> checkInitialInitValue;
        std::cout << std::endl;

        if (checkInitialInitValue == "да" || checkInitialInitValue == "Да")
        {
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> initialInitValue;
            checkTrueInitialInitValue = true;
        }
        else if (checkInitialInitValue == "нет" || checkInitialInitValue == "Нет")
        {
            checkTrueInitialInitValue = true;
        }
        else
        {
            std::cout << "Вы ввели неверную команду.";
        }
    } while (!checkTrueInitialInitValue);

    Counter usedCounter(initialInitValue);

    std::cout << std::endl;

    std::string commandValue;
    bool checkCommand = false;

    
    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> commandValue;

        if (commandValue == "x"  || commandValue == "х")
        {
            std::cout << "Пока.";
            checkCommand = true;
        }
        else if (commandValue == "+")
        {
            usedCounter.counterPlus();
        }
        else if (commandValue == "-")
        {
            usedCounter.counterMinus();
        }
        else if (commandValue == "=")
        {
            std::cout << "Значение счетчика: " << usedCounter.getCounter() << "." << std::endl;
        }
        else
        {
            std::cout << "Вы ввели неверную команду." << std::endl;
        }
    } while (!checkCommand);
}