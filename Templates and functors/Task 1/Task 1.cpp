
#include <iostream>
#include <vector>

// Шаблонная функция для возведения одного числа в квадрат
template<class T>
T squaring(T num) {
    return num * num;
}

// Перегруженная шаблонная функция для возведения в квадрат всех элементов вектора
template<class T>
std::vector<T> squaring(std::vector<T> arr) {
    // Проходим по всем элементам вектора
    for (int i = 0; i < arr.size(); i++) {
        // Возводим каждый элемент в квадрат
        arr[i] *= arr[i];
    }
    return arr;
}

// Шаблонная функция для вывода результата возведения числа в квадрат
// Выводит исходное значение и результат
template<class T>
void print_squaring(T num) {
    std::cout << "[IN]: " << num << "\n";
    std::cout << "[OUT]: " << squaring(num) << std::endl;
}

// Перегруженная шаблонная функция для вывода результата возведения вектора в квадрат
template<class T>
void print_squaring(std::vector<T> arr) {
    // Выводим исходный вектор
    std::cout << "[IN]: ";
    for (T n : arr) {
        std::cout << n << " ";
    }

    // Выводим результат - вектор с элементами в квадрате
    std::cout << "\n[OUT]: ";
    for (T n : squaring(arr)) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Исходное число для возведения в квадрат
    int num = 4;

    // Исходный вектор для возведения элементов в квадрат
    std::vector<int> arr{ -1, 4, 8 };

    // Выводим результат возведения числа в квадрат: 4^2 = 16
    print_squaring(num);

    // Выводим результат возведения элементов вектора в квадрат: {1, 16, 64}
    print_squaring(arr);
}
