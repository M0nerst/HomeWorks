#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>
#include <string>
#include <vector>
#pragma execution_character_set("utf-8")


class DataBase {
private:

public:
    DataBase(std::string conn_string = "host=127.0.0.1 port=5432 dbname=lessionfive user=postgres password=M0ner$t26") : conn{ conn_string } {
        std::cout << "База даных подключена!" << std::endl;
        creating_table();
    }


    void creating_table() {
        try {
            w.exec("CREATE TABLE IF NOT EXISTS Clients ("
                "id SERIAL PRIMARY KEY, "
                "first_name TEXT NOT NULL, "
                "last_name TEXT NOT NULL, "
                "email TEXT UNIQUE NOT NULL); "

                "CREATE TABLE IF NOT EXISTS Phone ("
                "phone_number TEXT UNIQUE NOT NULL,"
                "client_id INT NOT NULL REFERENCES Clients(id));");

            w.commit();
            std::cout << "Таблица создана!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка при создании таблиц: " << e.what() << std::endl;
        }
    }
    

    void client_list() {
        try {
            pqxx::result c = w.exec_params("SELECT DISTINCT * "
                "FROM Clients "
                "ORDER BY Clients.id");
            w.commit();

            for (auto row : c) {
                c_id = row["id"].as<int>();
                first_name = row["first_name"].as<std::string>();
                last_name = row["last_name"].as<std::string>();
                email = row["email"].as<std::string>();
                std::cout << "\n" << c_id << ": " << first_name << " " << last_name << ", " << email << std::endl;

                pqxx::result p = w.exec_params("SELECT DISTINCT phone_number "
                    "FROM Phone "
                    "WHERE client_id = $1", c_id);
                w.commit();

                for (auto row1 : p) {
                    phone = row1["phone_number"].as<std::string>();
                    std::cout << "(" << phone << "), ";
                }
                std::cout << std::endl;
            
            }
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка при получении списка клиентов: " << e.what() << std::endl;
        }
    }
    

    void add_new_client(std::string first_name, std::string last_name, std::string email, std::string phone) {
        try {
            w.exec_params("INSERT INTO Clients (first_name, last_name, email) "
                "VALUES ($1, $2, $3) RETURNING id", first_name, last_name, email);
            w.commit();
            std::cout << "Клиент " << first_name << " " << last_name << " (" << email << ") " << " был добавлен" << std::endl;
            add_phone(email, phone);
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка при добавлении клиента: " << e.what() << std::endl;
        }
    }
       

    void add_phone(std::string email, std::string phone_num) {
        try {
            w.exec_params("INSERT INTO Phone (phone_number, client_id) "
                "VALUES ($1, (SELECT id FROM Clients WHERE email = $2))", phone_num, email);
            w.commit();
            std::cout << "Клиенту с э.почтой " << email << " был добавлен телефон: " << phone_num << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка при добавлении телефона: " << e.what() << std::endl;
        }
    }
        

    void updata_client(std::string email, std::string first_name, std::string last_name, std::string new_email) {
       
        try {
            w.exec_params("UPDATE Clients SET first_name = $1, last_name = $2, email = $3 WHERE email = $4", first_name, last_name, new_email, email);
            w.commit();
            std::cout << "Данные клиента с э.почтой " << email << " были изменены на:" << std::endl;
            std::cout << first_name << " " << last_name << " " << new_email << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка при обновлении клиента: " << e.what() << std::endl;
        }
    }
       

    void clear_phone_list(std::string email) {
        try {
            w.exec_params("DELETE FROM Phone "
                "WHERE client_id IN "
                "(SELECT id FROM Clients WHERE email = $1)", email);
            w.commit();
            std::cout << "Все телефоны клиента с э.почтой " << email << " были удалены!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка при удалении телефонов: " << e.what() << std::endl;
        }
    }
        

    void delete_phone(std::string phone_num) {
        try {
            w.exec_params("DELETE FROM Phone WHERE phone_number = $1", phone_num);
            w.commit();
            std::cout << "Телефонный номер (" << phone_num << ") был удалён!" << std::endl;
        }
    catch (const std::exception& e) {
        std::cout << "Ошибка при удалении телефона: " << e.what() << std::endl;
    }
    }
  

    void delete_client(std::string email) {
        try {
            clear_phone_list(email);
            w.exec_params("DELETE FROM Clients WHERE email = $1", email);
            w.commit();
            std::cout << "Клиент с э.почтой " << email << " был удалён!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка при удалении клиента: " << e.what() << std::endl;
        }
    }
        
    std::vector<std::vector<std::string>> search_client(std::string query) {
        std::vector<std::vector<std::string>> results;
        try {
            pqxx::result c = w.exec_params("SELECT DISTINCT * "
                "FROM Clients "
                "LEFT JOIN  public.Phone ON public.Clients.id = public.Phone.client_id "
                "WHERE Clients.first_name = $1 OR "
                "Clients.last_name = $1 OR "
                "Clients.email = $1 OR "
                "Phone.phone_number = $1;", query);
            w.commit();

            std::cout << "Результаты поиска для запроса '" << query << "':" << std::endl;

            if (c.empty()) {
                std::cout << "Ничего не найдено." << std::endl;
                return results;
            }

            for (auto row : c) {
                c_id = row["id"].as<int>();
                first_name = row["first_name"].as<std::string>();
                last_name = row["last_name"].as<std::string>();
                email = row["email"].as<std::string>();

                std::cout << c_id << ": " << first_name << " " << last_name << ", " << email;

                std::vector<std::string> client_data;
                client_data.push_back(std::to_string(c_id));
                client_data.push_back(first_name);
                client_data.push_back(last_name);
                client_data.push_back(email);

                pqxx::result p = w.exec_params("SELECT DISTINCT phone_number "
                    "FROM Phone "
                    "WHERE client_id = $1", c_id);
                w.commit();

                std::cout << " - Телефоны: ";
                for (auto row1 : p) {
                    phone = row1["phone_number"].as<std::string>();
                    std::cout << "(" << phone << "), ";
                    client_data.push_back(phone);
                }
                std::cout << std::endl;

                results.push_back(client_data);
            }
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка при поиске клиента: " << e.what() << std::endl;
        }

        return results;
    }

   
        
    

private:
    std::string first_name;
    std::string last_name;
    std::string email;
    std::string phone;
    int c_id;

    pqxx::connection conn;

    pqxx::work w{ conn };

};


int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);


    DataBase a;
    a.add_new_client("Клиент", "Первый", "1.client@email.com", "89988072323");
    a.add_new_client("Клиент", "Второй", "2.client@email.com", "89988072331");
    a.add_new_client("Клиент", "Третий", "3.client@email.com", "89988072341");
    std::cout << std::endl;

    a.add_phone("1.client@email.com", "89988072324");
    a.add_phone("2.client@email.com", "89988072335");
    a.add_phone("3.client@email.com", "89988072326");
    std::cout << std::endl;

    a.client_list();
    std::cout << std::endl;

    a.delete_phone("89988072326");
    std::cout << std::endl;
    a.clear_phone_list("2.client@email.com");
    std::cout << std::endl;

    a.delete_client("3.3@email.com");
    std::cout << std::endl;

    a.client_list();
    std::cout << std::endl;

    a.add_new_client("Клиент", "Четвертый", "client.four@email.com", "89988072341");
    std::cout << std::endl;

    a.client_list();
    std::cout << std::endl;
   
    a.updata_client("Клиент", "Четвертый", "client.four@email.com", "client.five");
    std::cout << std::endl;

    a.client_list();
    std::cout << std::endl;


    auto result1 = a.search_client("Клиент");
    std::cout << std::endl;
    auto result2 = a.search_client("Второй");
    std::cout << std::endl;
    auto result3 = a.search_client("2.client@email.com");
    std::cout << std::endl;
    auto result4 = a.search_client("89988072323");
    std::cout << std::endl;

    std::cout << "Результаты поиска получены." << std::endl;
};
