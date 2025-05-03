
#include <iostream>


#define MODE 1
#if !defined MODE
#error The MODE must be defined
#endif

int main()
{
    setlocale(LC_ALL, "Russian"); 
    system("chcp 1251");
    system("cls");

#ifdef MODE

    #if MODE == 0
        std::cout << "Работаю в режиме тренировки" << std::endl;

    #elif MODE == 1
        std::cout << "Работаю в боевом режиме" << std::endl;
        double FirstNumber = 0;
        double SecondNumber = 0;
        double add();
        {
            std::cout << "Введите число 1: "; std::cin >> FirstNumber;

            std::cout << std::endl;
            std::cout << "Введите число 2: "; std::cin >> SecondNumber;

            std::cout << std::endl;
            std::cout << "Результат сложения:" << FirstNumber + SecondNumber;
        }
     

    #else
        std::cout << "Неизвестный режим. Завершение работы" << std::endl;
    #endif 

#endif





        return 0;
}
