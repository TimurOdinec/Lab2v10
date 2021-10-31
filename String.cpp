#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <cstddef>
#include <string.h>
#include <iostream>

/// <summary>
/// конструктор
/// </summary>
String::String()
{
	String::lengthStr = 0;
	String::pointerStr = NULL;
}
/// <summary>
/// конструктор с параметрами
/// </summary>
/// <param name="pointerString"></param>
String::String(const char *pointerString)
{
	String::lengthStr = strlen(pointerString);
	String::pointerStr = new char[lengthStr + 1];
	strcpy(pointerStr, pointerString);
}
/// <summary>
/// конструктор копирования
/// </summary>
/// <param name="objectStr"></param>
String::String(const String &objectStr) 
{
	std::cout << "constructor copy run" << std::endl;
	String::lengthStr = objectStr.lengthStr;
	String::pointerStr = new char[lengthStr + 1];
	strcpy(pointerStr, objectStr.pointerStr);
}
/// <summary>
/// деструктор
/// </summary>
String::~String()
{
	delete []pointerStr;
}
/// <summary>
/// метод получения строки, возвращает указатель на char-массив
/// </summary>
/// <returns></returns>
char* String::getString()
{
	return pointerStr;
}
/// <summary>
/// метод получения длины строки
/// </summary>
/// <returns></returns>
int String::getLengthString()
{
	return this->lengthStr;
}
/// <summary>
/// метод вывода строки в консоль (cout<<)
/// </summary>
void String::viewString() 
{
	std::cout << this->pointerStr << std::endl;
}
/// <summary>
/// метод перегрузки унарного оператора присваивания "="
/// </summary>
/// <param name="objectStr"></param>
/// <returns></returns>
String& String::operator=(const String &objectStr)
{
	//вариант, когда объекту присваивается он сам 
	if (&objectStr == this)
	{
		return *this;
	}
	//если объекту присваивается другой объект
	delete[]String::pointerStr;
	String::lengthStr = objectStr.lengthStr;
	String::pointerStr = new char[lengthStr + 1];
	strcpy(pointerStr, objectStr.pointerStr);
	return *this;
}
/// <summary>
/// дружественный метод перегрузки бинарного оператора "-" (задание в лаб.р.)
/// </summary>
/// <param name="strFirst"></param>
/// <param name="strSecond"></param>
/// <returns></returns>
int operator - (const String& strFirst, const String& strSecond)
{
	//возвращаем кол-во символов насколько одна строка длиннее  другой
	int result = strFirst.lengthStr - strSecond.lengthStr;
	return result;
}