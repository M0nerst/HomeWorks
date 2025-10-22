
#include <iostream>  
#include <set>       


void print(std::set<int, std::greater<>>& set1) 
{
    std::cout << "[OUT]:" << std::endl;
    // Перебираем все элементы множества и выводим их
    // Используем const auto& для избежания копирования
    for (const auto& i : set1) 
    {
        std::cout << i << "\n";
    }
}

int main()
{
    
    std::set<int, std::greater<>> set1;
    int size;  // Количество чисел для ввода

    // Запрашиваем у пользователя количество чисел
    std::cout << "[IN]:" << std::endl;
    std::cin >> size;

    // Читаем числа и добавляем их в множество
    for (int i = 0; i < size; i++) 
    {
        int num = 0;
        std::cin >> num;
        set1.insert(num);  // Вставляем число в множество
    }


    print(set1);

    return 0;  
}
