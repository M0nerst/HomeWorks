
#include <iostream>
#include <fstream>
#include <vector>

class Observer 
{
public:
    // Виртуальные методы для обработки различных уровней сообщений
    virtual void Warning(const std::string& message) {}
    virtual void Error(const std::string& message) {}
    virtual void FatalError(const std::string& message) {}
    virtual ~Observer() = default;
};

// Управляет списком наблюдателей и уведомляет их о событиях
class Observable 
{
public:
    // Добавляет наблюдателя в список подписчиков
    void addObserver(Observer* observer) 
    {
        observers_.push_back(observer);
    }

    // Удаляет наблюдателя из списка подписчиков
    void removeObserver(Observer* observer) 
    {
        auto it = remove(observers_.begin(), observers_.end(), observer);
        observers_.erase(it, observers_.end());
    }

    // Уведомляет всех наблюдателей о предупреждении
    void warning() const 
    {
        for (auto obs : observers_) 
        {
            obs->Warning("Warning!");
        }
    }

    // Уведомляет всех наблюдателей об ошибке
    void error() const 
    {
        for (auto obs : observers_) 
        {
            obs->Error("Error!");
        }
    }

    // Уведомляет всех наблюдателей о критической ошибке
    void fatalError() const 
    {
        for (auto obs : observers_) 
        {
            obs->FatalError("Fatal Error!");
        }
    }

private:
    std::vector<Observer*> observers_;  // Список указателей на наблюдателей
};

// Наблюдатель для предупреждений
// Выводит предупреждения в консоль
class WarningObserver : public Observer 
{
public:
    // Переопределенный метод для обработки предупреждений
    void Warning(const std::string& message) override 
    {
        std::cout << "Warning: " << message << "\n";
    }
};

// Наблюдатель для ошибок
// Записывает ошибки в файл
class ErrorObserver : public Observer 
{
private:
    std::ofstream write;  // Файловый поток для записи
public:
    // Конструктор открывает файл для записи в режиме добавления
    ErrorObserver(const std::string& filename) 
    {
        write.open(filename, std::ofstream::app);
        if (!write.is_open()) 
        {
            std::cerr << "Can't open the file: " << filename << "!\n";
        }
    }

    // Деструктор закрывает файл
    ~ErrorObserver() 
    {
        if (write.is_open()) 
        {
            write.close();
        }
    }

    // Переопределенный метод для записи ошибок в файл
    void Error(const std::string& message) override 
    {
        if (write.is_open()) 
        {
            write << "Error: " << message << "\n";
        }
    }
};

// Наблюдатель для критических ошибок
// Выводит критические ошибки в консоль и записывает в файл
class FatalErrorObserver : public Observer 
{
private:
    std::ofstream write;  // Файловый поток для записи
public:
    // Конструктор открывает файл для записи в режиме добавления
    FatalErrorObserver(const std::string& filename) 
    {
        write.open(filename, std::ofstream::app);
        if (!write.is_open()) 
        {
            std::cerr << "Can't open the file: " << filename << "!\n";
        }
    }

    // Деструктор закрывает файл
    ~FatalErrorObserver() 
    {
        if (write.is_open()) 
        {
            write.close();
        }
    }

    // Переопределенный метод для обработки критических ошибок
    // Выводит сообщение и в консоль, и в файл
    void FatalError(const std::string& message) override 
    {
        std::cout << "Fatal error: " << message << "\n";
        if (write.is_open()) 
        {
            write << "Fatal error: " << message << "\n";
        }
    }
};


int main() 
{
    // Создание наблюдаемого объекта
    Observable Obs;

    // Создание наблюдателей для различных типов событий
    WarningObserver warning;                      
    ErrorObserver error("error_file.txt");        
    FatalErrorObserver fatal("fatal_file.txt");  

    // Регистрация наблюдателей в Observable
    Obs.addObserver(&warning);
    Obs.addObserver(&error);
    Obs.addObserver(&fatal);

    // Генерация событий различных типов
    Obs.warning();      // Вызовет Warning() у всех наблюдателей
    Obs.error();        // Вызовет Error() у всех наблюдателей
    Obs.fatalError();   // Вызовет FatalError() у всех наблюдателей

    return 0;
}
