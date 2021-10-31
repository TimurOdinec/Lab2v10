#pragma once

class String
{
private:
	char* pointerStr;		//указатель на char-массив символов
	int lengthStr;			//длина строки
public:
	String();				//конструктор
	String(const char *);	//конструктор с параметрами
	String(const String &);	//конструктор копирования
	~String();				//деструктор
	
	char* getString();		//метод получения строки
	int getLengthString();	//метод получения длины строки
	void viewString();		//метод вывода строки в консоль (cout<<)

	String& operator = (const String&);						//перегруженный оператор присваивания
	friend int operator - (const String&, const String&);	//перегруженный оператор "-"
};

