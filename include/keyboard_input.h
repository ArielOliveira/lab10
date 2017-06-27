#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include "input_exception.h"

#include <iostream>
using std::cin;
using std::cerr;
using std::endl;
using std::getline;

#include <limits>
using std::streamsize;

void cleanBuffer() {
	cin.clear(); 
    std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}

int getNumber(int &value) {
	InputException exception;
	try {
		if (!(cin >> value)) throw InputException();
	} catch(InputException &err) {
		cleanBuffer();
		cerr << exception.what() << endl;

		return 1;
	}
	return 0;
}

int getString(string &word) {
	InputException exception;
	try {
		if (!getline(cin, word, '\n')) throw InputException();
	} catch(InputException &err) {
		cleanBuffer();
		cerr << exception.what() << endl;
		
		return 1;
	}
	return 0;
}

#endif