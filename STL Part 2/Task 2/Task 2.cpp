
#include <iostream> 
#include <set>      
#include <list>     
#include <vector>   

// Шаблонная функция для печати элементов контейнера
template<class T>
void print_container(T& container) {
    for (const auto i : container) { // Перебираем элементы контейнера
        std::cout << i << " "; // Выводим текущий элемент
    }
    std::cout << std::endl; // Завершаем строку вывода
}

int main()
{
   
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set); // Выводим элементы набора 

    
    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list); // Выводим элементы списка

    
    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector); // Выводим элементы вектора
}