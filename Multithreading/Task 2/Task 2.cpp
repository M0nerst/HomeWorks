


//Теперь каждый поток обрабатывает свою часть векторов напрямую



#include <iostream>      
#include <thread>       
#include <vector>       
#include <chrono>        
#include <functional>    // Для std::cref и std::ref


void sum_vec(const std::vector<int>& Vector1, const std::vector<int>& Vector2,
    std::vector<int>& result, int start, int end) {
    
    for (int i = start; i < end; i++) {
        result[i] = Vector1[i] + Vector2[i];
    }
}

int main()
{
       setlocale(LC_ALL, "ru");

        std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;

        std::cout << "\t\t1'000" << "\t        10'000" << "\t       100'000" << "\t     1'000'000" << "\n";
    std::cout << "-------------------------------------------------------------------------" << std::endl;

    // Определяем конфигурации для тестирования
    std::vector<int> Threads{ 1, 2, 4, 8, 16 };                   
    std::vector<int> Size_v{ 1'000, 10'000, 100'000, 1'000'000 }; 

    // Объявляем основные векторы для вычислений
    std::vector<int> v1;    
    std::vector<int> v2;     
    std::vector<int> result; // Вектор для хранения результата сложения

    // Внешний цикл: перебираем различное количество потоков
    for (auto& c_Thread : Threads) {

        std::cout << c_Thread << " потоков ";

        // Внутренний цикл: перебираем различные размеры векторов
        for (auto& c_Vector : Size_v) {

            // Подготавливаем векторы нужного размера
            v1.resize(c_Vector, 2);     
            v2.resize(c_Vector, 1);     
            result.resize(c_Vector, 0); 

            // Вычисляем размер части вектора для каждого потока
            int size_Threads = static_cast<int> (c_Vector / c_Thread);

            // Создаем контейнер для хранения потоков
            std::vector<std::thread> th;

            // Запускаем измерение времени выполнения
            auto start = std::chrono::high_resolution_clock::now();

            // Создаем и запускаем потоки
            for (int i = 0; i < c_Thread; i++) {
                // Вычисляем границы диапазона для текущего потока
                int start_idx = size_Threads * i;  // Начальный индекс
                int end_idx;                       // Конечный индекс

                // Определяем конечный индекс для текущего потока
                if (i != c_Thread - 1) {
                    // Для всех потоков кроме последнего
                    end_idx = size_Threads * (i + 1);
                }
                else {
                    // Для последнего потока (обрабатываем оставшиеся элементы)
                    end_idx = c_Vector;
                }

                // Создаем и запускаем поток с функцией sum_vec, передавая диапазон
                th.push_back(std::thread(sum_vec, std::cref(v1), std::cref(v2),
                    std::ref(result), start_idx, end_idx));
            }

            // Ожидаем завершения всех потоков
            for (auto& it : th) {
                it.join();  // Блокируем выполнение до завершения потока
            }

            // Останавливаем измерение времени
            auto stop = std::chrono::high_resolution_clock::now();

            // Вычисляем и выводим время выполнения в миллисекундах
            std::chrono::duration<double, std::milli> time = stop - start;
            std::cout.width(5);
            std::cout << "\t" << time.count() << "ms";
        }
        std::cout << std::endl;  // Переходим на новую строку после обработки всех размеров
    }
}