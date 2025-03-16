
#include <iostream>

struct bank {
	int account_number;
	std::string name_account;
	double money;
};

void increment_money(bank& b) {
	std::cout << "Введите новую сумму:";
	std::cin >> b.money;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	bank b;
	std::cout << "Введите номер счёта:";
	std::cin >> b.account_number;

	std::cout << "Введите имя владельца:";
	std::cin >> b.name_account;

	std::cout << "Введите сумму:";
	std::cin >> b.money;

	increment_money(b);

	std::cout << "Ваш счёт:" << b.name_account << ", " << b.account_number << ", " << b.money << std::endl;

	return 0;

}
