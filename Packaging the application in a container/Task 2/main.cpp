#define MODE 1

#ifdef MODE

#if MODE == 1
int add(int a, int b)
{
	return a + b;
}
#endif

#include <iostream>

using namespace std;

int main(int argc, char** argv) {

#if MODE == 0
	cout << "Работаю в режиме тренировки\n";
#elif MODE == 1
	cout << "Работаю в боевом режиме\n";
	int a, b;
	cout << "Введите первое число: ";
	cin >> a;
	cout << "Введите второе число: ";
	cin >> b;
	cout << "Результат сложения: " << add(a, b) << endl;
#else
	cout << "Неизвестный режим. Завершение работы\n";
#endif
	return 0;
}

#else
#error "it is necessary to define MODE"
#endif