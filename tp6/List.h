#pragma once
#include "MyException.h"
#include "Note.h"
#include <string>

typedef struct Element {
	Note* data{};
	Element* pNext = 0;
} Element;

class List : public Note {
private:
	Element* Head;
	Element* Tail;
	int count;

public:
	List();
	~List();

	List& operator--();//��������
	List& Del(int cnt);
	void Del_head();
	void DelAll();

	List& operator++();//���������� � �����
	Element* operator[](const int index);

	void AddElem(Element* elem);

	List& Edit();//�������������� ��������

	void Print();//������ ������

	List& RemoveSimilar();

	int GetCount();
	void SetCount(int);

	Element* GetHead();
	void SetHead(Element*);

	Element* GetTail();
	void SetTail(Element*);

	void SortByBirthday();

	void SearchByPhone();

	bool IsEmpty();
};

