
#include <iostream>
#include <algorithm>  
#include <map>        
#include <set>        

// Функция для вывода результатов подсчета частоты символов
void print(std::multimap<int, char, std::greater<int>>& map1, std::string& symbols) {
    std::cout << "[IN]: " << symbols << "\n";
    std::cout << "[OUT]: " << "\n";
    for (const auto& m : map1) 
    {
        std::cout << m.second << " : " << m.first << "\n";
    }
}

int main()
{
    // Исходная строка для анализа
    std::string symbols{ "123555Helllo world!!!!!" };
    int repet = 0;  // Переменная для хранения количества повторений символа

    std::multimap<int, char, std::greater<int>> map1;

     std::set<char> set1;

    // Заполняем set уникальными символами из исходной строки
    for (int i = 0; i < symbols.size(); i++) {
        set1.insert(symbols[i]);
    }

    // Для каждого уникального символа подсчитываем его частоту в исходной строке
    for (const auto& i : set1) 
    {
        repet = std::count(symbols.begin(), symbols.end(), i);
        map1.emplace(repet, i);
    }

    print(map1, symbols);

    return 0;
}
