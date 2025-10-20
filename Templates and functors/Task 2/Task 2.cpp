#include <iostream>
#include <vector>


template<class T>
class table
{
public:

    // row - количество строк, col - количество столбцов
    table(int row, int col) : size_row{ row }, size_col{ col }
    {
        create_arr();
    };


    // создает копию существующей таблицы
    table(const table& other)
    {
        size_row = other.size_row;
        size_col = other.size_col;

        create_arr();

        // Копируем все элементы из исходной таблицы
        for (int i = 0; i < other.size_row; i++) 
        {
            for (int j = 0; j < other.size_col; j++) 
            {  
                arr[i][j] = other.arr[i][j];
            }
        }
    };


    // Вспомогательный класс для реализации двойной индексации table[i][j]
    // Позволяет безопасно обращаться к элементам таблицы с проверкой границ
    class proxy
    {
    public:
        // Конструктор proxy: принимает указатель на строку и количество столбцов
        proxy(T* arr, int size_col) :arr_row{ arr }, size_col{ size_col } {};

        // Перегрузка оператора [] для доступа к элементу в строке
        // Выбрасывает исключение, если индекс выходит за границы
        T& operator [](int index) {
            if (index >= size_col || index < 0) {
                throw std::out_of_range("Индекс выходит за пределы массива");
            }
            return arr_row[index];
        }
    private:
        T* arr_row;      // Указатель на строку таблицы
        int size_col = 0; // Количество столбцов
    };

    // Перегрузка оператора [] для доступа к строке таблицы
    // Возвращает объект proxy для последующего доступа к элементу в строке
    // Использование: table[i][j]
    proxy operator [] (const int index) const {
        if (index >= size_row || index < 0) {
            throw std::out_of_range("Индекс выходит за пределы массива");
        }
        return proxy(arr[index], size_col);
    };


    // Перегрузка оператора присваивания: копирует содержимое другой таблицы
    // other - таблица-источник для копирования
    table& operator = (const table& other) {
        // Проверка на самоприсваивание
        if (this != &other) {
            size_row = other.size_row;
            size_col = other.size_col;

            // Освобождаем старую память
            this->~table();

            // Создаем новый массив нужного размера
            create_arr();

            // Копируем все элементы
            for (int i = 0; i < other.size_row; i++) {
                for (int j = 0; j < other.size_col; j++) {  // ИСПРАВЛЕНО: было i++, должно быть j++
                    arr[i][j] = other.arr[i][j];
                };
            };
            return *this;
        };
        return *this;
    };


    // Функция для получения количества строк в таблице
    const int get_size_row() {
        return size_row;
    }

    // Функция для получения количества столбцов в таблице
    const int get_size_col() {
        return size_col;
    }


    // Деструктор: освобождает выделенную память
    ~table() {
        // Удаляем каждую строку
        for (int i = 0; i < size_row; i++) {
            delete[] arr[i];
        }
        // Удаляем массив указателей на строки
        delete[] arr;
    };

private:
    T** arr;           // Двумерный массив (массив указателей на строки)
    int size_row = 0;  // Количество строк
    int size_col = 0;  // Количество столбцов

    // Приватная функция для создания двумерного массива
    // Выделяет память для массива указателей и для каждой строки
    void create_arr() {
        arr = new T * [size_row] {};
        for (int i = 0; i < size_row; i++) {
            arr[i] = new T[size_col]{};
        }
    }
};



int main()
{
    setlocale(LC_ALL, "ru");

    // Создаем таблицу размером 2x3
    auto test = table<int>(2, 3);

    // Устанавливаем значение элемента [0][0]
    test[0][0] = 4;

    std::cout << std::endl;

    // Выводим значение элемента [0][0]
    std::cout << " \t" << test[0][0];

    std::cout << std::endl;
}
