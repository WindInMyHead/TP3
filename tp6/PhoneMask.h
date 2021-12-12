#pragma once
#include<conio.h>
#include "MyException.h"

string EnterPhone() {
    int length = 0;
    int pospos = 0;
    int posarrays[10] = { 3,4,5,7,8,9,11,12,14,15 };
    int pos = posarrays[pospos];
    char mask[17] = "+7(***)***-**-**";
    cout << mask;
    while (length != 10) {
        int ch = _getch();
        if (ch >= '0' && ch <= '9') {
            length++;
            mask[pos] = ch;
            pospos++;
            pos = posarrays[pospos];
            cout << "\r" << mask;
        }
    }
    return mask;
}

int* EnterBday() {
    int checkBday = 0;
    int* bDay = new int[3];
    int length = 0, pospos = 0, posarrays[8] = { 0,1,3,4,6,7,8,9 }, pos = posarrays[pospos];
    string day, month, year;
    string mask = "dd/mm/yyyy";
    cout << mask;
    while (length != 8) {
        int ch = _getch();
        if (ch >= '0' && ch <= '9') {
            length++;
            mask[pos] = ch;
            pospos++;
            pos = posarrays[pospos];
            cout << "\r" << mask;
        }
    }
    cout << endl;
    day.push_back(mask[0]);
    day.push_back(mask[1]);

    month.push_back(mask[3]);
    month.push_back(mask[4]);

    year.push_back(mask[6]);
    year.push_back(mask[7]);
    year.push_back(mask[8]);
    year.push_back(mask[9]);

    bDay[0] = stoi(day);
    bDay[1] = stoi(month);
    bDay[2] = stoi(year);

    if (bDay[0] == 0 || bDay[1] == 0 || bDay[2] == 0) {
        throw MyException("Incorrect date!");
    }

    return bDay;
}