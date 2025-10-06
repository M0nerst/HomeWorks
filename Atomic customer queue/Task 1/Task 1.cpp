
#include <iostream>  
#include <thread>
#include <mutex>
#include <functional>
#include <atomic>


std::atomic_int Cl_count = 0;


void Clients(int Cl_max) {

    while (Cl_max > Cl_count) {

        std::this_thread::sleep_for(std::chrono::seconds(1));

        Cl_count++;

        std::cout << "Добавлен новый клиент! Клиенты: " << Cl_count << std::endl;
    }
}


void Operator() {

    while (true) {

        std::this_thread::sleep_for(std::chrono::seconds(2));

        // Проверяем, есть ли клиенты для обслуживания
        if (Cl_count > 0) {

            std::cout << "Оператор завершил работу с клиентом! Клиенты: " << Cl_count << std::endl;


            Cl_count--;
        }
        else {

            std::cout << "Оператор завершил работу! Клиенты: " << Cl_count << std::endl;
            break;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "ru");

    int Cl_max = 0;

    std::cout << "Введите максимальное количество клиентов: ";
    std::cin >> Cl_max;

    // Создаем поток для функции добавления клиентов
    // Передаем параметр Cl_max в функцию Clients
    std::thread c(Clients, Cl_max);

    // Создаем поток для функции работы оператора
    std::thread o(Operator);

    // Ожидаем завершения потока добавления клиентов
    c.join();

    // Ожидаем завершения потока работы оператора
    o.join();

    return 0;
}