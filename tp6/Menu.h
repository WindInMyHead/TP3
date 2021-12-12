#pragma once
#include "List.h"
#include "StrStream.h"

using namespace std;

int Menu(List list) {
	int v = 0, menu = 1;
	while (menu) {
		cout << "====Main menu====" << endl;
		cout << "1. Add object" << endl;
		cout << "2. Print list" << endl;
		cout << "3. Search by phone" << endl;
		cout << "4. Edit data" << endl;
		cout << "5. Delete object" << endl;
		cout << "6. Sort by birthday" << endl;
		cout << "7. Remove similar objects from the list" << endl;
		cout << "8. String stream task" << endl;
		cout << "0. Exit to Windows " << endl;
		cout << ">>> ";
		cin >> v;

		while (v < 0 || v > 8 || cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Incorrect entered, retry" << endl;
			cin >> v;
		}

		try {
			switch (v) {
			case 1:
			{
				++list;
				break;
			}

			case 2:
			{
				list.Print();
				break;
			}

			case 3:
			{
				list.SearchByPhone();
				break;
			}

			case 4:
			{
				list.Edit();
				break;
			}

			case 5:
			{
				--list;
				break;
			}

			case 6:
			{
				list.SortByBirthday();
				break;

			}

			case 7:
			{
				list.RemoveSimilar();
				break;
			}

			case 8:
			{
				SentenceSort();
				break;
			}

			case 0:
			{
				menu = 0;
			}

			}
		}
		catch (MyException& exception) {
			cout << exception.what() << endl;
			return Menu(list);
		}
	}
	return 0;
}
