#ifndef ALLOC_EXCEPTION_H
#define ALLOC_EXCEPTION_H

#include <exception>
using std::exception;

class AllocException {

	public:
		const char* what() {
			return "O tamanho do vetor excedeu a memória do sistema";
		}

};

#endif