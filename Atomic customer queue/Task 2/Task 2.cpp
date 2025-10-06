#include "Timer.h"       
#include <chrono>         
#include <iostream>       
#include <mutex>         
#include <thread>        
#include <vector>     
#include <cstdlib>        // Для функции rand()
#include <ctime>          // Для функции time()
#include <stdexcept>      // Для исключений

// Глобальные мьютексы для синхронизации доступа к общим ресурсам
std::once_flag f;  // Флаг для однократного выполнения кода (вывод заголовка)
std::mutex m1;     // Мьютекс для инициализации таймера и консольных параметров
std::mutex m2;     // Мьютекс для вывода ID потока
std::mutex m3;     // Мьютекс для отрисовки прогресс-бара
std::mutex m4;     // Мьютекс для вывода времени выполнения


static void ProgressBar(int numberThreadsNow)
{
    int progressBar = 10;      // Начальная позиция прогресс-бара по оси X
    int total = 29;            // Конечная позиция прогресс-бара (длина)
    int PositionForTime = 30;  // Позиция для вывода времени выполнения

    // Выполнить один раз для всех потоков
    std::call_once(f, []() {
        std::cout << "# " << "ID\t\t" << "Progress\t" << "Time\n" << std::endl;
        });

    // Блокировка для безопасной инициализации таймера и консольных параметров
    m1.lock();
    Timer t;                  // Создание таймера для измерения времени выполнения
    consol_parameter con_p;   
    m1.unlock();

    // Блокировка для вывода номера и ID потока
    m2.lock();
    con_p.SetPosition(0, numberThreadsNow + 1);  // Установка курсора в начало строки потока
    std::cout << numberThreadsNow + 1 << " " << std::this_thread::get_id() << "\t";
    m2.unlock();

    // Цикл отрисовки прогресс-бара
    while (progressBar < total)
    {
        // Пауза
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Блокировка для безопасной отрисовки
        m3.lock();
        con_p.SetPosition(progressBar, numberThreadsNow + 1); 
        std::cout << char(219);  // Вывод символа

        try  //если я правильно понял посыл задания
        {
            // Симуляция случайной ошибки с вероятностью ~13%
            if (rand() % 100 < 13)
            {
                throw std::runtime_error("Случайная ошибка в потоке");
            }

            // Нормальная отрисовка прогресс-бара
            con_p.SetPosition(progressBar, numberThreadsNow + 1);
            std::cout << char(219);  // Вывести символ прогресс-бара (█)
        }
        catch (const std::exception& e)
        {
            // Обработка ошибки - отображение красным цветом
            con_p.SetPosition(progressBar, numberThreadsNow + 1);
            std::cout << "\033[31m" << char(219) << "\033[0m";  // Красный цвет для ошибки
        }

        // Пауза для красивой картинки
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        ++progressBar;
        m3.unlock();
    }

    
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    // Блокировка для вывода времени выполнения
    m4.lock();
    con_p.SetPosition(PositionForTime, numberThreadsNow + 1);  // Установить позицию для времени
    t.print();
    m4.unlock();
}


int main()
{

    // Инициализация генератора случайных чисел
    srand(time(nullptr));

    int count = 5;  // Количество потоков для создания

    // Создание вектора для хранения потоков
    std::vector<std::thread> Threads(count);

    // Запуск всех потоков
    for (size_t i = 0; i < count; i++)
    {
        
        Threads[i] = std::thread(ProgressBar, i);
    }

    // Ожидание завершения всех потоков
    for (auto& i : Threads)
    {
        i.join(); 
    }

    std::cout << "\n\n\n" << std::endl;
}