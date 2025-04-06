#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <windows.h>
#include <filesystem>




class Adress {
	private:
		std::string NameCity_;
		std::string NameStreet_;
		int NumberHouse_ = 0;
		int NumberApartament_ = 0;
		std::string FullAdres_;

	public:
		Adress(std::string NameCity, std::string NameStreet, int NumberHouse, int NumberApartament) {
			NameCity_ = NameCity;
			NameStreet_ = NameStreet;
			NumberHouse_ = NumberHouse;
			NumberApartament_ = NumberApartament;
		}

		std::string AdressCreate() {
			FullAdres_ = NameCity_ + ", " + NameStreet_ + ", " +
				std::to_string(NumberHouse_) + ", " + std::to_string(NumberApartament_);
			return FullAdres_;
		}

};

enum class codeCommit
{
    fileInOpenError, fileOutOpenError
};



int printArrayForClassObjects(std::string* arrayForClassObjects, const int quantityAdresses)
{
    std::ofstream fileOut("C:\\Users\\even2\\OneDrive\\Рабочий стол\\Основные решения\\ООП абстракция и инкапсуляция\\Задание 1\\out.txt");


    if (fileOut.is_open())
    {
        std::cout << "Файл out.txt успешно открыт." << std::endl;
    }
    else
    {
        std::cout << "Ошибка открытия файла" << std::endl;
        return static_cast<int>(codeCommit::fileOutOpenError);
    }

    fileOut << "Всего количество адресов: " << quantityAdresses << std::endl << std::endl;

    fileOut << "Адреса:" << std::endl;

    for (int i = quantityAdresses - 1; i >= 0; i--)
    {
        fileOut << quantityAdresses - i << ". " << arrayForClassObjects[i] << std::endl;
    }
    fileOut.close();
};


std::string* createTextArr(const int quantityAdresses)
{
    std::string* TextArr = new std::string[quantityAdresses]{};

    return TextArr;
}


void deleteTextArr(std::string* TextArr, const int quantityAdresses)
{
    delete[] TextArr;
    TextArr = nullptr;
}

int main()
{
    setlocale(LC_ALL, "Russian"); 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream fileIn("C:\\Users\\even2\\OneDrive\\Рабочий стол\\Основные решения\\ООП абстракция и инкапсуляция\\Задание 1\\in.txt"); // Открываем файл и проверяем удалось ли открыть
    if (!fileIn)
    {
        std::cout << "Ошибка открытия файла in.txt." << std::endl;
        return static_cast<int>(codeCommit::fileInOpenError);
    }
    else
    {
        std::cout << "Файл in.txt успешно открыт." << std::endl;
    }

    int quantityAdresses = 0;
    std::string NameCity = {};
    std::string NameStreet = {};
    int NumberHouse = 0;
    int NumberApartment = 0;

    fileIn >> quantityAdresses; 

    std::string* arrayForClassObjects = createTextArr(quantityAdresses); 

    for (int i = 0; i < quantityAdresses; i++) 
    {
        fileIn >> NameCity >> NameStreet >> NumberHouse >> NumberApartment;
        Adress adress(NameCity, NameStreet, NumberHouse, NumberApartment);
        arrayForClassObjects[i] = adress.AdressCreate();

    };
    fileIn.close();



    printArrayForClassObjects(arrayForClassObjects, quantityAdresses);
    deleteTextArr(arrayForClassObjects, quantityAdresses);

    std::cout << "Результат работы программы смотри в файле out.txt" << std::endl;
}