
#include <map>
#include <string>
#include <iostream>

// Симулирует тяжелую операцию получения данных
class VeryHeavyDatabase 
{
public:
    virtual ~VeryHeavyDatabase() = default;  // Виртуальный деструктор для корректного удаления производных классов

    // Получение данных по ключу (виртуальный метод для переопределения в прокси)
    virtual std::string GetData(const std::string& key) const noexcept 
    {
        return "Very Big Data String: " + key;
    }
};

// Кеширует результаты запросов для уменьшения обращений к реальной БД
class CacheProxyDB : public VeryHeavyDatabase 
{
public:
    explicit CacheProxyDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}

    // Переопределение метода GetData с кешированием
    std::string GetData(const std::string& key) const noexcept override 
    {
        // Проверяем, есть ли данные в кеше
        if (cache_.find(key) == cache_.end()) 
        {
            std::cout << "Get from real object\n";
            // Получаем данные из реальной БД и сохраняем в кеш
            cache_[key] = real_db_->GetData(key);
        }
        else 
        {
            std::cout << "Get from cache\n";
        }
        return cache_.at(key);
    }

private:
    mutable std::map<std::string, std::string> cache_;  // mutable для изменения в const методе
    VeryHeavyDatabase* real_db_;  // Указатель на реальный объект БД
};

// Возвращает тестовые данные вместо реальных (полезно для тестирования)
class TestDB : public VeryHeavyDatabase 
{
public:
    explicit TestDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}

    // Возвращает фиксированные тестовые данные
    std::string GetData(const std::string& key) const noexcept override 
    {
        return "test_data";
    }

private:
    VeryHeavyDatabase* real_db_;
};

// Позволяет выполнить только заданное количество запросов
class OneShotDB : public VeryHeavyDatabase 
{
public:
    explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots = 1)
        : real_db_(real_object), shots_(shots) {}

    // Возвращает данные только если не превышен лимит запросов
    std::string GetData(const std::string& key) const noexcept override 
    {
        if (shots_ > 0) 
        {
            shots_--;  // Уменьшаем счётчик доступных запросов
            return real_db_->GetData(key);
        }
        else 
        {
            return "error";  // Возвращаем ошибку при превышении лимита
        }
    }

private:
    VeryHeavyDatabase* real_db_;  // Указатель на реальный объект БД
    mutable size_t shots_;  // Количество оставшихся доступных запросов
};


int main()
{
    // Создание реального объекта базы данных
    auto real_db = VeryHeavyDatabase();

    // Создание прокси с кешированием
    auto cached_db = CacheProxyDB(std::addressof(real_db));

    // Создание тестового прокси
    auto test_db = TestDB(std::addressof(real_db));

    // Создание прокси с ограничением на 2 запроса
    auto limit_db = OneShotDB(std::addressof(real_db), 2);

    // Демонстрация работы кеширующего прокси
    std::cout << std::endl;
    std::cout << cached_db.GetData("key") << std::endl;  // Первый запрос - из реальной БД
    std::cout << cached_db.GetData("key") << std::endl;  // Второй запрос - из кеша

    // Демонстрация работы тестового прокси
    std::cout << "\n" << std::endl;
    std::cout << test_db.GetData("key") << std::endl;

    // Демонстрация работы прокси с ограничением запросов
    std::cout << "\n" << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;  // Запрос 1 - успешно
    std::cout << limit_db.GetData("key") << std::endl;  // Запрос 2 - успешно
    std::cout << limit_db.GetData("key") << std::endl;  // Запрос 3 - ошибка (превышен лимит)

    return 0;
}
