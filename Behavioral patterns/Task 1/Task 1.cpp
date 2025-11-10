
#include <iostream>
#include <fstream>

// Определяет интерфейс для всех типов логирования
class LogCommand 
{
public:
    virtual ~LogCommand() = default;


    // Должен быть переопределен в производных классах
    virtual void print(const std::string& message) = 0;
};

// Команда для логирования в консоль
class ConsoleLogCommand : public LogCommand 
{
public:
    // Переопределенный метод для вывода сообщения в консоль
    void print(const std::string& message) override 
    {
        std::cout << message << std::endl;
    }
};

// Команда для логирования в файл
class FileLogCommand : public LogCommand 
{
public:
    // Конструктор открывает файл для записи в режиме добавления
    FileLogCommand() 
    {
        m_file.open("log.txt", std::fstream::app);
        if (!m_file.is_open()) 
        {
            std::cerr << "Не удается открыть файл log.txt!" << std::endl;
        }
    }

    // Деструктор закрывает файл
    ~FileLogCommand() 
    {
        if (m_file.is_open()) 
        {
            m_file.close();
        }
    }

    // Переопределенный метод для записи сообщения в файл
    void print(const std::string& message) override 
    {
        if (m_file.is_open()) 
        {
            m_file << message << std::endl;
        }
    }

private:
    std::fstream m_file;  // Файловый поток для записи логов
};

// Принимает объект команды и сообщение для вывода
void print(LogCommand& command, const std::string& message) 
{
    command.print(message);
}


int main() 
{
    setlocale(LC_ALL, "ru");

    // Создание объектов команд для различных способов логирования
    ConsoleLogCommand consoleCommand;  
    FileLogCommand fileCommand;        

    // Демонстрация работы команд логирования
    print(consoleCommand, "Вывод сюда");
    print(fileCommand, "Вывод туда");

    return 0;
}
