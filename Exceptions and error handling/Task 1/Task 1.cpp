#include <iostream>
#include <string>
#include <exception>


int function(std::string anyWord, int forbiddenLength)
{
    if (forbiddenLength == anyWord.length())
    {
        throw std::exception("Вы ввели слово запретной длины!До свидания.");
    };

    return static_cast<int>(anyWord.length());

}


int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    system("cls");

    int wordLength = 0;
    int forbiddenLength = 0;
    std::string anyWord;
    bool checkForbiddenLength = false;

    do
    {
        std::cout << "Введите запретную длину: ";
        std::cin >> forbiddenLength;

        if (forbiddenLength > 0)
        {
            checkForbiddenLength = true;
        }

        if (forbiddenLength <= 0)
        {
            std::cout << "Неверная длина... Введите новую" << std::endl;
        }

        if (forbiddenLength > 55)
        {
            std::cout << "Неверная длина... Введите новую" << std::endl;  // За максимальное значение взято слово "тетрагидропиранилциклопентилтетрагидропиридопиридиновые". 
        }

    } while (!checkForbiddenLength);

    std::cout << "-------------------------" << std::endl;

    try
    {
        do
        {
            std::cout << "Введите слово: ";
            std::cin >> anyWord;

            wordLength = function(anyWord, forbiddenLength);

            std::cout << "Длина слова \"" << anyWord << "\" равна " << wordLength;
            std::cout << std::endl << "-------------------------" << std::endl;

        } while (forbiddenLength != wordLength);
    }
    catch (const std::exception& ex)
    {
        std::cout << std::endl << ex.what() << std::endl;
    }
}