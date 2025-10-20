
#include <iostream>
#include <vector>
#include <algorithm>


class counter
{
public:
    // Конструктор - инициализирует счетчики нулевыми значениями
    counter() : sum(0), count(0) {}

    // Перегруженный оператор () - вызывается для каждого элемента вектора
    // Проверяет, делится ли число на 3 без остатка
    void operator ()(int value) {
        if (value % 3 == 0) {  // Проверка кратности 3
            sum += value;       // Добавляем значение к общей сумме
            count++;            // Увеличиваем счетчик чисел, кратных 3
        }
    }

    
    // Возвращает накопленную сумму
    int get_sum() {
        return sum;
    }

    
    // Возвращает количество найденных чисел
    int get_count() {
        return count;
    }

private:
    int sum;    // Сумма всех чисел
    int count;  // Количество чисел
};


int main()
{

    std::vector<int> arr{ 4, 1, 3, 6, 25, 54 };

    // Вывод
    std::cout << "[IN]: ";
    for (int n : arr) {
        std::cout << n << " ";
    }
    std::cout << std::endl;


    // Вывод суммы чисел, кратных 3 (3 + 6 + 54 = 63)
    std::cout << "[OUT]: get_sum() = " << std::for_each(arr.begin(), arr.end(), counter()).get_sum() << std::endl;

    // Вывод количества чисел, кратных 3 (3, 6, 54 - всего 3 числа)
    std::cout << "[OUT]: get_count() = " << std::for_each(arr.begin(), arr.end(), counter()).get_count() << std::endl;

    return 0;
}
