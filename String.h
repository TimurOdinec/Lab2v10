#pragma once

class String
{
private:
	char* pointerStr;		//��������� �� char-������ ��������
	int lengthStr;			//����� ������
public:
	String();				//�����������
	String(const char *);	//����������� � �����������
	String(const String &);	//����������� �����������
	~String();				//����������
	
	char* getString();		//����� ��������� ������
	int getLengthString();	//����� ��������� ����� ������
	void viewString();		//����� ������ ������ � ������� (cout<<)

	String& operator = (const String&);						//������������� �������� ������������
	friend int operator - (const String&, const String&);	//������������� �������� "-"
};

