#ifndef INPUT_EXCEPTION_H
#define INPUT_EXCEPTION_H

#include <exception>
using std::exception;

class InputException {

	public:
		const char* what() {
			return "O valor inserido é inválido! Tente novamente.";
		}

};

#endif