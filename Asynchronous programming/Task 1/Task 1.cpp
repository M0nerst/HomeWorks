#include <iostream>
#include <cstdlib>
#include <vector>
#include <future>

// Функция для генерации вектора с 10 уникальными случайными числами от 0 до 9
void VecArrayGen(std::vector<int>& vec) {
    srand(time(0)); // Инициализация генератора случайных чисел

    // Генерируем 10 уникальных чисел
    while (vec.size() < 10) {
        int num = rand() % 10; 
        // Проверяем уникальность
        if (find(vec.begin(), vec.end(), num) == vec.end()) {
            vec.push_back(num);
        }
    }
}

// Асинхронная функция для поиска индекса минимального элемента
void FindMinNum(const std::vector<int> vec, int i, std::promise<int> prom)
{
    int minNum = i;

    // Ищем минимальный элемент в диапазоне [i+1, vec.size())
    for (int j = i + 1; j < vec.size(); j++)
    {
        if (vec[j] < vec[minNum])
        {
            minNum = j; // Обновляем индекс минимального элемента
        }
    }

    prom.set_value(minNum);
};

void SortArray(std::vector<int>& vec)
{
    // Сортировка выбором: на каждой итерации находим минимум и ставим его на текущую позицию
    for (int i = 0; i < vec.size() - 1; i++)
    {
        // Создаем promise для получения результата из асинхронной задачи
        std::promise<int> prom;

        // Получаем future, связанный с promise - через него получим результат
        std::future<int> future_res = prom.get_future();

        // Запускаем асинхронную задачу поиска минимума
        auto asyncFindMinNum = std::async(std::launch::async, FindMinNum, vec, i, std::move(prom));

        // Получаем результат через future
        // get() блокирует текущий поток до готовности результата
        int minNum = future_res.get();

        // Меняем местами текущий элемент с найденным минимальным
        if (vec[i] != vec[minNum])
        {
            std::swap(vec[i], vec[minNum]);
        }
    }
};

// Вспомогательная функция для вывода элементов вектора
void printVec(const std::vector<int> vec)
{
    for (const auto& i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}




int main()
{
    setlocale(LC_ALL, "ru");

    std::vector<int> vec;

    // Генерируем вектор
    VecArrayGen(vec);

    std::cout << "До сортировки: ";
    printVec(vec);

    // Выполняем асинхронную сортировку
    SortArray(vec);

    std::cout << "После сортировки: ";
    printVec(vec);
}