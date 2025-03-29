
#include <iostream>
#include <cstring>


class Counter 
{
private:
    int counterResult_ = 0;

public:
    Counter(int initialInitValue);
    int getCounter();
    int counterPlus();
    int counterMinus();
};

Counter::Counter(int initialInitValue) 
{
    counterResult_ = initialInitValue;
};

int Counter::getCounter() 
{
    return counterResult_;
};

int Counter::counterPlus() 
{
    return ++counterResult_;
};

int Counter::counterMinus() 
{
    return --counterResult_;
};



int main()
{
    setlocale(LC_ALL, "Russian");

    system("chcp 1251");


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

    Counter userCounter(initialInitValue);

    std::cout << std::endl;

    std::string commandValue;
    bool checkCommand = false;

    
    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> commandValue;

        if (commandValue == "x" || commandValue == "х")
        {
            std::cout << "До запуска!";
            checkCommand = true;
        }
        else if (commandValue == "+")
        {
            userCounter.counterPlus();
        }
        else if (commandValue == "-")
        {
            userCounter.counterMinus();
        }
        else if (commandValue == "=")
        {
            std::cout << "Значение счетчика: " << userCounter.getCounter() << "." << std::endl;
        }
        else
        {
            std::cout << "Вы ввели неверную команду." << std::endl;
        }
    } while (!checkCommand);
}