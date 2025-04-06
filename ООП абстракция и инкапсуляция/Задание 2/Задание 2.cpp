
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

class Adress 
{
private:
    std::string NameCity_;
    std::string NameStreet_;
    int NumberHouse_ = 0;
    int NumberApartment_ = 0;
    std::string FullAdress_;

public:

    Adress(std::string NameCity, std::string NameStreet, int NumberHouse, int NumberApartment)
    {
        NameCity_ = NameCity;
        NameStreet_ = NameStreet;
        NumberHouse_ = NumberHouse;
        NumberApartment_ = NumberApartment;
    }

    std::string createAdress2Out()
    {
        FullAdress_ = NameCity_ + ", " + NameStreet_ + ", " + std::to_string(NumberHouse_)
            + ", " + std::to_string(NumberApartment_);
        return FullAdress_;
    };
};

enum class codeCommit
{
    fileInOpenError, fileOutOpenError
};


int printArrayForClassObjects(std::string* arrayForClassObjects, const int quantityAdresses)
{
    std::ofstream fileOut("C:\\Users\\even2\\OneDrive\\Рабочий стол\\Основные решения\\ООП абстракция и инкапсуляция\\Задание 2\\out.txt", std::ios_base::trunc);

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

    for (int i = 0; i < quantityAdresses; i++)
    {
        fileOut << i + 1 << ". " << arrayForClassObjects[i] << std::endl;
    }
    fileOut.close();
};


void addressSort(std::string* arrayForClassObjects, const int quantityAdresses)
{
    bool swapped = false;
    do {
        swapped = false;
        std::string tmp;

        for (int i = quantityAdresses - 1; i > 0; --i)
        {
            if (arrayForClassObjects[i - 1] > arrayForClassObjects[i])
            {
                tmp = arrayForClassObjects[i];
                arrayForClassObjects[i] = arrayForClassObjects[i - 1];
                arrayForClassObjects[i - 1] = tmp;
                swapped = true;
            }
        }
    } while (swapped);
}


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
    system("chcp 1251");

    std::ifstream fileIn("C:\\Users\\even2\\OneDrive\\Рабочий стол\\Основные решения\\ООП абстракция и инкапсуляция\\Задание 2\\in.txt"); // Открываем файл и проверяем удалось ли открыть
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
        arrayForClassObjects[i] = adress.createAdress2Out();

    };
    fileIn.close();

    addressSort(arrayForClassObjects, quantityAdresses); 
    printArrayForClassObjects(arrayForClassObjects, quantityAdresses); 
    deleteTextArr(arrayForClassObjects, quantityAdresses); 

    std::cout << "Результат работы программы смотри в файле out.txt" << std::endl;
}