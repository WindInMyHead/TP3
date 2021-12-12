#pragma once
#include "MyException.h"
#include <string>
#include <fstream>
#include <sstream>

void SentenceSort() {
    bool state = false;
	char c;
	string s;
	ifstream f;
	f.open("file.txt");
	stringstream sstr;
	sstr << f.rdbuf();
    while (!sstr.eof()) {
        sstr >> c;
        if (c == '-') state = true;
        else state = false;

        if (state && !isspace(c)) {
            cout << c;
            while (state) {
                sstr >> c;
                cout << c;
                if (sstr.peek() == ' ') cout << " ";
                if (c == '.' || c == '!' || c == '?')
                    state = false;
            }
            cout << endl;
        }
    }
}
/*
Below I have shown an example of a dialogue.If the program works correctly,
all sentences to the end of the file will be displayed on the command line.
-Hello, how are you ?
 -Fine, thanks.And you ?
-Great!My name is Lima.
  -I am Emily.It’s nice to meet you.
-It’s nice to meet you, too.
   -Are you from New York ?
-Yes, I am.Where are you from ?
  -I am from here, from Bedford.
-Oh, great.Can we be friends ?
 -Sure.
*/