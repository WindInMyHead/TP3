#pragma once
#include "MyException.h"

class Note{
private:
	string name;
	string phone;
	int* bDay;
public:
	Note() { };
	Note(string name,string phone, int* bday);
	void SetName(string);
	string GetName();

	void SetPhone(string);
	string GetPhone();

	void SetBday(int*);
	int* GetBday();

	void Print();
};

