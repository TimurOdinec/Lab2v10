// Lab2v10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// примечания:
// Эта функция (strcpy) считается небезопасной из-за отсутствия проверки границ 
// и может привести к переполнению буфера. (На самом деле strcpy печально известен эксплойтами переполнения,
//  и все программисты его избегают - или, по крайней мере, должны этого избегать). 
// Совет состоит в том, чтобы использовать безопасную функцию, которая учитывает размер целевого буфера, 
// чтобы избежать переполнения. Вы также можете использовать strncpy (НО с осторожностью!). 
// С вашим кодом проблем нет, то есть функции будут работать так, как вы говорите, 
// но попробуйте указать в качестве входных данных буфер, размер которого превышает размер целевого буфера. 
// Функция переполнит целевой буфер.
// 
// ссылки:
// унарные и бинарные операторы
// https://ravesli.com/urok-39-arifmeticheskie-operatory/
// конструктор копирования
// https://ravesli.com/urok-141-konstruktor-kopirovaniya/
// указатели
// https://ravesli.com/urok-80-ukazateli-vvedenie/
// перегрузка операторов
// https://ravesli.com/urok-134-peregruzka-operatorov-cherez-metody-klassa/
// 
//  
// ЗАДАНИЕ
// 10. Реализовать класс String для работы со строками символов. 
// Перегрузить оператор «-» (минус) так, чтобы определить, насколько одна строка длиннее  другой.
// (бинарный оператор оператор) 
// Предоставить конструктор копирования.
//
// Функция operator может быть использована для расширения области приложения следующих операторов: 
// «+», «-», «*», «%», «&», «|» и т.д. 
// Операторы, которые не могут быть перегружены: 
// «.», «.*», «::», «?:», sizeof и typeid.
// 
// 1.у строк должна быть длина
// 2.strA - strB = кол-во символов 
//

#include "String.h"
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Lab2v10 \n";

    //массивы char для создания объектов String
    char arrFirst[] = "TEST";
    char arrSecond[] = "TE";

    std::cout << "###################################################" << std::endl;
    //прямая инициализация объекта
    String strThird("TEST");
    std::cout << "строка: ";
    strThird.viewString();
    std::cout << "длина строки: " << strThird.getLengthString() << std::endl;
    //инициализация объекта копированием
    String strFourth(arrSecond);
    std::cout << "строка: ";
    strFourth.viewString();
    std::cout << "длина строки: " << strFourth.getLengthString() << std::endl;
    //перегруженный оператор "-"
    int overloadDifferenceLengthStr = strThird - strFourth;
    std::cout << "overloadDifferenceLengthStr (-) = " << overloadDifferenceLengthStr << std::endl;
    //перегруженный оператор "="
    strThird = strFourth;
    std::cout << "overloadAssignmentOperator : thirdStr = ";
    strThird.viewString();
    std::cout << " fourthStr = ";
    strFourth.viewString();
    //инициализация объекта прямая и инициализация объекта с конструктором копирования
    String strSixth("CONSTRCOPY");
    String strSeventh(strSixth);
    strSixth.viewString();
    strSeventh.viewString();
    std::cout << "###################################################" << std::endl;
    //динамическое выделение памяти
    String* strFirst = new String(arrFirst);
    strFirst->viewString();
    String* strSecond = new String(arrSecond);
    strSecond->viewString();
    std::cout << "строка: " << strFirst->getString() << std::endl;
    int lengthStrF = strFirst->getLengthString();
    std::cout << "длина строки: " << lengthStrF << std::endl;
    std::cout << "строка: " << strSecond->getString() << std::endl;
    int lengthStrS = strSecond->getLengthString();
    std::cout << "длина строки: " << lengthStrS << std::endl;
    int differenceLengthStr = 0;
    differenceLengthStr = strFirst->getLengthString() - strSecond->getLengthString();
    std::cout << "differenceLengthStr = " << differenceLengthStr << std::endl;
    overloadDifferenceLengthStr = *strFirst - *strSecond;
    std::cout << "overloadDifferenceLengthStr = " << overloadDifferenceLengthStr << std::endl;
    std::cout << "###################################################" << std::endl;

    return 0;
}

