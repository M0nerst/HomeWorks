
#include <iostream>
#include <fstream>

// Определяет уровни важности сообщений в системе логирования
enum class Type 
{
    Warning,      // Предупреждение - некритическая проблема
    Error,        // Ошибка - требует внимания
    FatalError,   // Критическая ошибка - приводит к остановке программы
    Unknown       // Неизвестный тип сообщения
};

// Инкапсулирует тип и текст логируемого сообщения
class LogMessage 
{
private:
    Type type_;           // Тип сообщения
    std::string text_;    // Текст сообщения

public:
    // Конструктор принимает тип и текст сообщения
    LogMessage(Type type, const std::string& text) : type_(type), text_(text) {}

    // Геттер для получения типа сообщения
    Type type() const 
    {
        return type_;
    }

    // Геттер для получения текста сообщения
    const std::string& message() const 
    {
        return text_;
    }
};

// Каждый обработчик либо обрабатывает сообщение, либо передает его следующему в цепочке
class LogHandler 
{
protected:
    LogHandler* nextHandler;  // Указатель на следующий обработчик в цепочке

public:
    // Конструктор принимает указатель на следующий обработчик
    LogHandler(LogHandler* handler = nullptr) : nextHandler(handler) {}

    virtual ~LogHandler() = default;

    // Метод для установки следующего обработчика в цепочке
    void setNext(LogHandler* handler) 
    {
        nextHandler = handler;
    }

    // Должен быть переопределен в производных классах
    virtual void handleMessage(const LogMessage& message) = 0;
};

// Выводит сообщения типа Warning в консоль
class Warning : public LogHandler 
{
public:
    // Обрабатывает сообщения типа Warning, выводя их в консоль
    // Остальные типы передает следующему обработчику
    void handleMessage(const LogMessage& message) override 
    {
        if (message.type() == Type::Warning) 
        {
            std::cout << "Log: " << message.message() << "\n";
        }
        else if (nextHandler) 
        {  // Проверка на nullptr перед вызовом
            nextHandler->handleMessage(message);
        }
    }
};

// Обработчик ошибок
// Записывает сообщения типа Error в файл
class Error : public LogHandler 
{
private:
    std::ofstream write;  // Поток для записи в файл

public:
    // Конструктор открывает файл для записи в режиме добавления
    Error(const std::string& filename) 
    {
        write.open(filename, std::ofstream::app);
        if (!write.is_open()) 
        {
            std::cerr << "Can't open the file: " << filename << "!\n";
        }
    }

    // Деструктор закрывает файл
    ~Error() 
    {
        if (write.is_open()) 
        {
            write.close();
        }
    }

    // Обрабатывает сообщения типа Error, записывая их в файл
    // Остальные типы передает следующему обработчику
    void handleMessage(const LogMessage& message) override 
    {
        if (message.type() == Type::Error) 
        {
            if (write.is_open()) 
            {
                write << "Log: " << message.message() << "\n";
            }
        }
        else if (nextHandler) 
        {  // Проверка на nullptr перед вызовом
            nextHandler->handleMessage(message);
        }
    }
};

// Обработчик критических ошибок
// Генерирует исключение при получении сообщения типа FatalError
class FatalError : public LogHandler 
{
public:
    // Обрабатывает сообщения типа FatalError, генерируя исключение
    // Остальные типы передает следующему обработчику
    void handleMessage(const LogMessage& message) override 
    {
        if (message.type() == Type::FatalError) 
        {
            throw std::runtime_error(message.message());
        }
        else if (nextHandler) 
        {  // Проверка на nullptr перед вызовом
            nextHandler->handleMessage(message);
        }
    }
};

// Обработчик неизвестных сообщений
// Выводит сообщения типа Unknown в консоль
class Unknown : public LogHandler 
{
public:
    // Обрабатывает сообщения типа Unknown, выводя их в консоль
    void handleMessage(const LogMessage& message) override 
    {
        if (message.type() == Type::Unknown) 
        {
            std::cout << "Log: " << message.message() << "\n";
        }
        else if (nextHandler) 
        {  // Проверка на nullptr перед вызовом
            nextHandler->handleMessage(message);
        }
    }
};

int main() 
{
    // Создание тестовых сообщений различных типов
    LogMessage log1(Type::Error, "Error!");
    LogMessage log2(Type::Warning, "Warning!");
    LogMessage log3(Type::Unknown, "Unknown message!");
    LogMessage log4(Type::FatalError, "Fatal error, program closed!");

    // Создание обработчиков для каждого типа сообщения
    FatalError fatalErrorHandler;
    Error errorHandler("file.txt");
    Warning warningHandler;
    Unknown unknownHandler;

    // Построение цепочки обработчиков
    // Порядок: FatalError -> Error -> Warning -> Unknown
    fatalErrorHandler.setNext(&errorHandler);
    errorHandler.setNext(&warningHandler);
    warningHandler.setNext(&unknownHandler);

    // Обработка сообщений через цепочку обработчиков
    fatalErrorHandler.handleMessage(log1);  // Будет записано в файл
    fatalErrorHandler.handleMessage(log2);  // Будет выведено в консоль

    // Обработка критической ошибки в блоке try-catch
    // так как она генерирует исключение
    try 
    {
        fatalErrorHandler.handleMessage(log3);  // Будет выведено в консоль
        fatalErrorHandler.handleMessage(log4);  // Генерирует исключение
    }
    catch (const std::exception& e) 
    { 
        std::cout << e.what() << std::endl;
    }

    return 0;
}
