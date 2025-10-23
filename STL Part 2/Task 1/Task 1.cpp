
#include <iostream>  
#include <vector>    
#include <algorithm>  

// Шаблонная функция для удаления дубликатов из вектора
template<class T>
void cleaning_elements(std::vector<T>& arr) {
    std::sort(arr.begin(), arr.end());  // Сортируем вектор
    auto last = std::unique(arr.begin(), arr.end());  // Удаляем дубликаты
    arr.erase(last, arr.end());  // Обрезаем вектор до уникальных элементов
}

// Шаблонная функция для вывода элементов вектора
template<class T>
void print(std::vector<T>& arr) {
    for (const auto n : arr) {  // Перебираем все элементы вектора
        std::cout << n << " ";  // Выводим текущий элемент
    }
    std::cout << std::endl;  // Завершаем строку вывода
}

int main() {
    // Инициализация вектора с дубликатами
    std::vector<int> arr{ 1, 1, 2, 5, 6, 1, 2, 4 };
    std::cout << "[IN]: ";  
    print(arr);  

    cleaning_elements(arr);  // Удаляем дубликаты из вектора
    std::cout << "[OUT]: ";  
    print(arr);  
}