#ifndef ARIELSLIB_QUEUE_H
#define ARIELSLIB_QUEUE_H

#include <iostream>
#include <cstddef>


namespace edb1 {
	template<typename T>
	class MyQueue {
		private:
			T *vector;
			int max;
			int size;
			int beginning;
		public:
			MyQueue(int size);
			~MyQueue();
			bool pushBack(T data);
			bool popFront();
			T front();
	};

	template<typename T>
	MyQueue<T>::MyQueue(int max) {
		vector = new T[max];
		this->max = max;
		size = 0;
		beginning = 0;
	}

	template<typename T>
	bool MyQueue<T>::pushBack(T data) {
		if (!(size < max)) return false;
		vector[(beginning+size)%max] = data;
		size++;
		return true;
	}

	template<typename T>
	bool MyQueue<T>::popFront() {
		if (size == 0) return false;
		beginning = (beginning+1)%max;
		size--;
		return true;
	}

	template<typename T>
	T MyQueue<T>::front() {
		return vector[beginning];
	}

	template<typename T>
	MyQueue<T>::~MyQueue() {}


}

#endif