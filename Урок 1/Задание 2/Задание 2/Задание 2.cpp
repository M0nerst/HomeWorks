
#include <iostream>

struct bank {
	int account_number;
	std::string name_account;
	double money;
	double new_money;
};

void increment_bank(bank& b, double new_money){

	b.money = new_money;

}

int main()
{
	setlocale(LC_ALL, "Russian");
	bank b;
	double new_money;

	std::cout << "Введите номер счёта:";
	std::cin >> b.account_number;

	std::cout << "Введите имя владельца:";
	std::cin >> b.name_account;

	std::cout << "Введите сумму:";
	std::cin >> b.money;

	std::cout << "Введите новую сумму:";  
	std::cin >> new_money;

	increment_bank(b, new_money);

	system("cls");

	std::cout << "Ваш счёт: " << b.name_account << ", " << b.account_number << ", " << b.money << std::endl;

	return 0;

}
