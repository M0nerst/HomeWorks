
#include <iostream>
#include <string>

struct adres {
	std::string sity;
	std::string street;
	std::string house_number;
	int apartment_number;
	int index;
};

void structure_output(adres& a) {
	std::cout << "Город: " << a.street << std::endl;
	std::cout << "Улица: " << a.sity << std::endl;
	std::cout << "Номер дома: " << a.house_number << std::endl;
	std::cout << "Номер квартиры: " << a.apartment_number << std::endl;
	std::cout << "Индекс: " << a.index << std::endl;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	adres a;
	std::cout << "Введите город:";
	std::getline(std::cin, a.sity);

	std::cout << "Введите улицу:";
	std::getline(std::cin, a.street);

	std::cout << "Введите номер дома:";
	std::getline(std::cin, a.house_number); //номера домов иногда встречаются с буквами

	std::cout << "Введите номер квартиры:";
	std::cin >> a.apartment_number;

	std::cout << "Введите индекс:";
	std::cin >> a.index;

	system("cls");
	
	structure_output(a);  //вывод структуры на консоль)

	return 0;

}
