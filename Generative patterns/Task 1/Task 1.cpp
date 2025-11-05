
#include <iostream>
#include <string>
#include <vector>

class SqlSelectQueryBuilder {
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


    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) 
    {
        where_conditions_.emplace_back(column + "=" + value);
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
            // Добавляем все указанные колонки через запятую
            for (size_t i = 0; i < columns_.size(); ++i) 
            {
                query += columns_[i];
                if (i < columns_.size() - 1) 
                {
                    query += ", ";
                }
            }
        }

        // Добавляем секцию FROM с именем таблицы
        query += " FROM " + from_;

        // Если есть условия WHERE, добавляем их
        if (!where_conditions_.empty()) 
        {
            query += " WHERE ";
            for (size_t i = 0; i < where_conditions_.size(); ++i) 
            {
                query += where_conditions_[i];
                if (i < where_conditions_.size() - 1) 
                {
                    query += " AND ";
                }
            }
            query += ";";
        }
        else 
        {
            // Если условий нет, добавляем точку с запятой в конце
            query += ";";
        }

        return query;
    }

private:
    std::vector<std::string> columns_;           
    std::string from_;                           
    std::vector<std::string> where_conditions_;  
};


int main() 
{
   setlocale(LC_ALL, "ru");

    // Создаём объект построителя запросов
    SqlSelectQueryBuilder query_builder;

    // Добавляем колонки для выборки
    query_builder.AddColumn("name").AddColumn("phone");

    // Указываем таблицу
    query_builder.AddFrom("students");

    // Добавляем условия WHERE
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    // Строим финальный запрос
    std::string query = query_builder.BuildQuery();

    // Ожидаемый результат для сравнения
    std::string example = "SELECT name, phone FROM students WHERE id=42 AND name=John;";

    // Проверяем корректность построенного запроса
    if (query == example) 
    {
        std::cout << "Запрос сформирован корректно." << std::endl;
    }
    else 
    {
        std::cout << "Ошибка в формировании запроса." << std::endl;
        std::cout << "Запрос: " << example << std::endl;
        std::cout << "Получено:  " << query << std::endl;
    }

    return 0;
}
