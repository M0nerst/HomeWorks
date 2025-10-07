#include <iostream>
#include <vector>
#include <future>

// Функция для умножения элемента вектора на 2
// Параметр передается по ссылке для изменения оригинального значения
void multiplyVec(int& MultiplierVec)
{
    MultiplierVec *= 2;
}

// Рекурсивная функция для асинхронной обработки вектора
// Разделяет диапазон пополам и обрабатывает каждую половину параллельно
void For_Each_AsyncRec(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    // Вычисляем текущий размер обрабатываемого диапазона
    auto currSize = std::distance(begin, end);

    // Базовый случай рекурсии: если элементов <= 3, обрабатываем последовательно
    if (currSize <= 3)
    {
        // Применяем функцию multiplyVec к каждому элементу в диапазоне
        std::for_each(begin, end, multiplyVec);
    }
    else
    {
        // Рекурсивный случай: делим диапазон пополам для параллельной обработки
        auto mid = begin;
        std::advance(mid, currSize / 2); // Перемещаем итератор на половину расстояния

        // Запускаем асинхронную обработку первой половины [begin, mid)
        // std::async создает новую задачу, которая выполняется в отдельном потоке
        auto asRes = std::async(For_Each_AsyncRec, begin, mid);

        // Обрабатываем вторую половину [mid, end) в текущем потоке
        For_Each_AsyncRec(mid, end);

        // Ожидаем завершения асинхронной задачи (первой половины)
        asRes.get();
    }
}

// Вспомогательная функция для вывода элементов вектора
void PrintArrey(std::vector<int>& vec) {
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    // Инициализируем вектор числами от 1 до 10
    std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::cout << "Было: ";
    PrintArrey(vec);

    // Выполняем асинхронную рекурсивную обработку
    // Вектор будет разделен на части, каждая обрабатывается параллельно
    For_Each_AsyncRec(vec.begin(), vec.end());

    std::cout << "Стало: ";
    PrintArrey(vec);

    return 0;
}
