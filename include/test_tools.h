#ifndef TEST_TOOLS_H
#define TEST_TOOLS_H

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
	T max = MAX;
	srand(time(NULL));
	T *v = new T[k];
	for (int i = 0; i < k; i++) {
		v[i] = randomize(max);
	}
	return v;
}

template<>
string* vectorSorter(int k) {
	srand(time(NULL));
	string *v = new string[k];
	for (int i = 0; i < k; i++) {
		//v[i] = randomize(max);
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