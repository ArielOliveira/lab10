#ifndef TEST_TOOLS_H
#define TEST_TOOLS_H

#include "alloc_exception.h"

#include <new>
using std::bad_alloc;

#include <iostream>
using std::cerr;
using std::endl;

#include <cstdlib>

#define MAX 1000

double randomize(double max) {
	double randomN;
	randomN = ((double)rand()/(double)(RAND_MAX) * max);
    return randomN;
}

float randomize(float max) {
    float randomN;
        randomN = ((float)rand()/(float)(RAND_MAX) * max);
    return randomN;
}

int randomize(int max) {
    int randomN;
    do {
        randomN = rand() % max;
    } while (randomN == 0);
    return randomN;
}

template<typename T>
T* vectorSorter(int k) {
	T *v;
	AllocException exception;
	try {
		srand(time(NULL));
		T max = MAX;
		v = new T[k];
		for (int i = 0; i < k; i++) {
			v[i] = randomize(max);
		}
	} catch (bad_alloc	 &err) {
		cerr << exception.what() << endl;
		v = NULL;
	}
	
	return v;
}



template<>
string* vectorSorter(int k) {
	string *v;
	AllocException exception;
	try {
		v = new string[k];
		for (int i = 0; i < k; i++) {
			v[i] = "N/A";
		}
	} catch (bad_alloc &err) {
		cerr << exception.what() << endl;
		v = NULL;
	}
	return v;
}

template <typename T>
void printVector(T *v, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

#endif