
#include <iostream>

#include "FileName.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    SmartArray sArr1(5);
    sArr1.smartArrayPushBack(3);
    sArr1.smartArrayPushBack(11);
    sArr1.smartArrayPushBack(111);
    sArr1.smartArrayPushBack(1111);
    sArr1.smartArrayPushBack(11111);

    sArr1.smartArrayPrint();
    std::cout << std::endl;
    std::cout << "***********************************" << std::endl;
    std::cout << std::endl;
    SmartArray sArr2(5);
    sArr2.smartArrayPushBack(22222);
    sArr2.smartArrayPushBack(2222);
    sArr2.smartArrayPushBack(222);
    sArr2.smartArrayPushBack(22);
    sArr2.smartArrayPushBack(6);
  

    sArr2.smartArrayPrint();


    SmartArray sArr3(sArr1);
    sArr3.smartArrayPrint();

    SmartArray sArr4 = sArr2;
    //sArr2.smartArrayPushBack(18);
    sArr4.smartArrayPrint();

    //std::cout << "**************В 1 массиве должны быть 1*********************" << std::endl;
    //std::cout << "**************В 2 массиве должны быть 2*********************" << std::endl;
    //std::cout << "**************В 3 массиве должны быть 1*********************" << std::endl;

    std::cout << std::endl;
    sArr4 = sArr3;
 
    sArr4.smartArrayPrint();
    std::cout << std::endl;

    std::cout << "**************Сам в себя*********************" << std::endl;
    std::cout << std::endl;
    sArr4 = sArr4;

    std::cout << std::endl;
    std::cout << "***********************************" << std::endl;

}