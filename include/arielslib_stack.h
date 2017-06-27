#ifndef ARIELSLIB_STACK_H
#define ARIELSLIB_STACK_H

#include <iostream>

namespace edb1 {

	template<typename T>
	class Stack {
		private:
			T *vector;
			int max;
			int size;
		public:
			Stack(int size);
			~Stack();
			int getSize();
			bool push(T element);
			bool pop();
			T top();

	};

	template<typename T>
	int Stack<T>::getSize() {
		return this->size;
	}

	template<typename T>
	Stack<T>::Stack(int max) {
		vector = new T[max];
		this->max = max;
		size = 0;
	}

	template<typename T>
	bool Stack<T>::push(T element) {
		if (!(size < max)) return false;
		vector[size] = element;
		size++;
		return true;
		
	}

	template<typename T>
	bool Stack<T>::pop() {
		if (size > 0) {
			size--;
			return true;
		}
		return false;
	}

	template<typename T>
	T Stack<T>::top() {
		return vector[size-1];
	}

	template<typename T>
	Stack<T>::~Stack() {}

}


#endif