#include <iostream>

enum class Months {
    Jan = 1,
    Feb,
    Marth,
    April,
    May,
    June,
    Jule,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec,
    exit = 0
};

int main(int argc, char** atgv) {
    setlocale(LC_ALL, "Russian");
    int m1;

    do {

        std::cout << "Введите номер месяца: ";
        std::cin >> m1;
        Months m = static_cast<Months>(m1);


        switch (m) {
        case Months::Jan:
            std::cout << "Январь" << std::endl;
            break;
        case Months::Feb:
            std::cout << "Февраль" << std::endl;
            break;
        case Months::Marth:
            std::cout << "Март" << std::endl;
            break;
        case Months::April:
            std::cout << "Апрель" << std::endl;
            break;
        case Months::May:
            std::cout << "Май" << std::endl;
            break;
        case Months::June:
            std::cout << "Июнь" << std::endl;
            break;
        case Months::Jule:
            std::cout << "Июль" << std::endl;
            break;
        case Months::Aug:
            std::cout << "Август" << std::endl;
            break;
        case Months::Sep:
            std::cout << "Сентябрь" << std::endl;
            break;
        case Months::Oct:
            std::cout << "Октябрь" << std::endl;
            break;
        case Months::Nov:
            std::cout << "Ноябрь" << std::endl;
            break;
        case Months::Dec:
            std::cout << "Декабрь" << std::endl;
            break;
        default: std::cout << "Некорретное число " << std::endl;
            break;
        case Months::exit:
            std::cout << "До свидания!" << std::endl;
            break;

        }

        
    } while (m1 != 0);


    if (m1 == 0) {
        return 0;
    }

  
   
}