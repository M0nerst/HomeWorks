
#include <iostream>
#include <string>
#include <vector>
#include <map>

class SqlSelectQueryBuilder 
{
public:

    SqlSelectQueryBuilder() = default;

 
    SqlSelectQueryBuilder& AddColumn(const std::string& column) 
    {
        columns_.push_back(column);
        return *this;
    }

  
    SqlSelectQueryBuilder& AddFrom(const std::string& table) 
    {
        from_ = table;
        return *this;
    }

  
    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept 
    {
        for (const auto& pair : kv) {
            AddWhere(pair.first, pair.second);
        }
        return *this;
    }

   
    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) 
    {
        where_conditions_.emplace_back(column + "=" + value);
        return *this;
    }

   
    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept 
    {
        for (const auto& column : columns) {
            AddColumn(column);
        }
        return *this;
    }

   
    std::string BuildQuery() 
    {
        std::string query = "SELECT ";

        // Если колонки не указаны, выбираем все (*)
        if (columns_.empty()) 
        {
            query += "* ";
        }
        else 
        {
            // Добавляем перечисление колонок через запятую
            for (const auto& column : columns_) 
            {
                query += column + ", ";
            }
            // Удаляем последнюю запятую и пробел
            query.pop_back();
            query.pop_back();
        }

        // Добавляем таблицу из FROM
        query += " FROM " + from_;

        // Добавляем условия WHERE, если они есть
        if (!where_conditions_.empty()) 
        {
            query += " WHERE ";
            // Объединяем условия через AND
            for (size_t i = 0; i < where_conditions_.size(); ++i) 
            {
                query += where_conditions_[i];
                if (i < where_conditions_.size() - 1) 
                {
                    query += " AND ";
                }
            }
        }

        // Добавляем точку с запятой в конце запроса
        query += ";";

        return query;
    }

private:
    std::vector<std::string> columns_;           
    std::string from_;                           
    std::vector<std::string> where_conditions_;  
};


int main() {
    
    setlocale(LC_ALL, "ru");

    // Создаем объект строителя запросов
    SqlSelectQueryBuilder query_builder;

    // Добавляем колонки name и phone
    query_builder.AddColumn("name").AddColumn("phone");

    // Указываем таблицу students
    query_builder.AddFrom("students");

    // Добавляем условия WHERE: id=42 и name=John
    query_builder.AddWhere({ {"id", "42"}, {"name", "Mike"} });

    // Строим финальный запрос
    std::string query = query_builder.BuildQuery();

    // Эталонный запрос для сравнения
    std::string example = "SELECT name, phone FROM students WHERE id=42 AND name=Mike;";

    // Проверяем корректность сформированного запроса
    if (query == example) 
    {
        std::cout << "Запрос сформирован корректно." << std::endl;
    }
    else 
    {
        std::cout << "Ошибка в формировании запроса." << std::endl;
        std::cout << "Ожидалось: " << example << std::endl;
        std::cout << "Получено:  " << query << std::endl;
    }

    return 0;
}
