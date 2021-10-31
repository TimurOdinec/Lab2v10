#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <cstddef>
#include <string.h>
#include <iostream>

/// <summary>
/// �����������
/// </summary>
String::String()
{
	String::lengthStr = 0;
	String::pointerStr = NULL;
}
/// <summary>
/// ����������� � �����������
/// </summary>
/// <param name="pointerString"></param>
String::String(const char *pointerString)
{
	String::lengthStr = strlen(pointerString);
	String::pointerStr = new char[lengthStr + 1];
	strcpy(pointerStr, pointerString);
}
/// <summary>
/// ����������� �����������
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
/// ����������
/// </summary>
String::~String()
{
	delete []pointerStr;
}
/// <summary>
/// ����� ��������� ������, ���������� ��������� �� char-������
/// </summary>
/// <returns></returns>
char* String::getString()
{
	return pointerStr;
}
/// <summary>
/// ����� ��������� ����� ������
/// </summary>
/// <returns></returns>
int String::getLengthString()
{
	return this->lengthStr;
}
/// <summary>
/// ����� ������ ������ � ������� (cout<<)
/// </summary>
void String::viewString() 
{
	std::cout << this->pointerStr << std::endl;
}
/// <summary>
/// ����� ���������� �������� ��������� ������������ "="
/// </summary>
/// <param name="objectStr"></param>
/// <returns></returns>
String& String::operator=(const String &objectStr)
{
	//�������, ����� ������� ������������� �� ��� 
	if (&objectStr == this)
	{
		return *this;
	}
	//���� ������� ������������� ������ ������
	delete[]String::pointerStr;
	String::lengthStr = objectStr.lengthStr;
	String::pointerStr = new char[lengthStr + 1];
	strcpy(pointerStr, objectStr.pointerStr);
	return *this;
}
/// <summary>
/// ������������� ����� ���������� ��������� ��������� "-" (������� � ���.�.)
/// </summary>
/// <param name="strFirst"></param>
/// <param name="strSecond"></param>
/// <returns></returns>
int operator - (const String& strFirst, const String& strSecond)
{
	//���������� ���-�� �������� ��������� ���� ������ �������  ������
	int result = strFirst.lengthStr - strSecond.lengthStr;
	return result;
}