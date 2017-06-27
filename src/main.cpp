#include <iostream>
using std::cout;
using std::endl;
using std::getline;

#include <string>
using std::string;

#include "test_tools.h"
#include "keyboard_input.h"

#include "arielslib.h"

using namespace edb1;

enum type {
	NONE,
	INTEGER,
	FLOAT_POINT,
	DOUBLE_,
	STRING_
};

string typeS = "";

int vecSize = 0;

void *pointer = NULL;

void printVectorStatus() {
	cout << "5 - ";
	if (!pointer) cout << "Criar Vetor" << endl;
	else cout << "Destruir Vetor" << endl;

}

void printType() {
	cout << "4 - ";
	if (!typeS.empty()) cout << "Tipo de dados: " << typeS << " (Resetar)" << endl;
	else cout << "Selecionar Tipo de Dados" << endl;
}

void menu() {
	cout << "PROGRAMA DE TESTES" << endl;
	cout << "1 - Testar TADs" << endl;
	cout << "2 - Testar Ordenação (requer Vetor)" << endl;
	cout << "3 - Testar Buscas (requer Ordenação)" << endl;
	printType();
	printVectorStatus();
	cout << "6 - Exibir vetor" << endl;
	cout << "7 - Voltar" << endl;
}

void menuTAD() {
	cout << "TESTE DE TADs" << endl;
	cout << "1 - Testar Lista" << endl;
	cout << "2 - Testar Pilha" << endl;
	cout << "3 - Testar Fila" << endl;
	cout << "4 - Voltar" << endl;
}

void menuSort() {
	cout << "TESTE DE ORDENAÇÃO" << endl;
	cout << "1 - Bubble Sort" << endl;
	cout << "2 - Insertion Sort" << endl;
	cout << "3 - Selection Sort" << endl;
	cout << "4 - Merge Sort" << endl;
	cout << "5 - Quick Sort" << endl;

}

void menuType() {
	cout << "SELECIONAR TIPO" << endl;
	cout << "1 - Inteiros" << endl;
	cout << "2 - Reais (Float)" << endl;
	cout << "3 - Reais (Double)" << endl;
	cout << "4 - String (Entrada manual)" << endl;
	cout << "5 - Sair" << endl;
}

template<typename T>
void listTest(T *v, int n) {

}

void stackTest() {

}

void queueTest() {

}

void makeVector(void *v, int n) {

}

template<typename T>
bool choiceSort(int c, int n);

bool choiceTAD(int c);

bool choiceType(int c);

template<typename T>
bool choiceMenu(int c);

void menuLoop();

int main() {

	menuLoop();
	/*
	//testa merge_sort
	float *v = vectorSorter<float>(k, max);
	std::cout << "Vetor desordenado" << std::endl;
	printVector<T>((T*)pointer, k);
	std::cout << std::endl;
	//quickSort<float>(v, 0, k-1);
	//mergeSort<float>(v, k);
	//selectionSort<float>(v, k);
	//insertionSort<float>(v, k);
	bubbleSort<float>(v, k);
	std::cout << "Vetor ordenado" << std::endl;
	printVector<float>(v, k);
	std::cout << std::endl;
	*/
	
	/*
	//testa binary_search
	std::cout << "Testando binary search" << std::endl;
	for (int i = 0; i < k; i++) {
		if (binarySearch<float>(v, v[i], k-1)) {
			std::cout << "Elemento " << v[i] << " " << "encontrado." << std::endl;
		} else {
			std::cout << "Elemento " << v[i] << " " << "não encontrado." << std::endl;
		}	
	}
	*/
	
	//List<int> l;
	Stack<int> s(20);
	s.push(5);
	std::cout << s.top() << std::endl;

	MyQueue<string> q(5);
	bool what;
	what = q.pushBack("brasileirinho");
	what = q.pushBack("chinesinho");
	what = q.pushBack("americaninho");
	what = q.pushBack("xibata");
	what = q.pushBack("disgraça");
	what = q.pushBack("merda");

	cout << q.front() << endl;
	cout << what << endl;
	q.popFront();
	

	return 0;
}

template<typename T>
bool choiceTAD(int c) {
	switch(c) {
		case 1:  
			break;
		case 2:
			break;
		case 3: 
			break;
		case 4: return true;
			break;
		default: return false;
			break;
	}
	return true;
}

template<typename T>
bool choiceVector(int n) {
	T *vector = vectorSorter<T>(n);
	if (!vector) return false;
	pointer = vector;
	return true;
}

template<typename T>
void destroy() {
	if (pointer) {
		delete[] static_cast<T*>(pointer);
		pointer = NULL;
	}
}

template<typename T>
bool choiceSort(int c, int n) {
	switch(c) {
		case 1: bubbleSort<T>((T*)pointer, n);
			break;
		case 2: insertionSort<T>((T*)pointer, n);
			break;
		case 3: selectionSort<T>((T*)pointer, n);
			break;
		case 4: mergeSort<T>((T*)pointer, n);
			break;
		case 5: quickSort<T>((T*)pointer, 0, n);
			break;
		default: return false;
			break;
	}
	return true;
}

template<typename T>
bool choiceSearch() {
	
}

template<typename T>
bool choiceMenu(int c) {
	switch(c) {
		case 1: menuTAD();
				while ((!getNumber(c)) && (!choiceTAD<T>(c))) cout << "Opção Inválida!" << endl;
			break;
		case 2: if (pointer) {
					menuSort();
					while ((!getNumber(c)) && (!choiceSort<T>(c, vecSize))) cout << "Opção Inválida!" << endl;
				} else {
					cout << "Ainda sem vetor. Por favor escolha a opção 5." << endl;
				}
			break;
		case 3: 
			break;
		case 4: typeS = "";
				return true;
			break;
		case 5: if (!pointer) {
					while (vecSize < 1) {
						cout << "Informe o tamanho do vetor: ";	
						while ((!getNumber(vecSize)) && (!choiceVector<T>(vecSize))) cout << "Opção Inválida!" << endl;
					} 
				} else {
					destroy<T>();
					vecSize = 0;
				}
			break;
		case 6: if (pointer) printVector<T>((T*)pointer, vecSize);
				else cout << "Sem vetor para exibir!" << endl;
			break;
		case 7: destroy<T>();
				return true;
			break;
		default: cout << "Opção Inválida!" << endl;
			break;
	}
	return false;
}

bool choiceType(int c) {
	switch(c) {
		case INTEGER: typeS = "Inteiro";
				menu();			
				while ((!getNumber(c)) && (!choiceMenu<int>(c))) {
					menu();
				} 
			break;
		case FLOAT_POINT: typeS = "Real (Float)";
				menu();
				while ((!getNumber(c)) && (!choiceMenu<float>(c))) {
					menu();
				} 
			break;
		case DOUBLE_: typeS = "Real (Double)";
				menu();
				while ((!getNumber(c)) && (!choiceMenu<double>(c))) {
					menu();
				} 
			break;
		case STRING_:
			break;
		case 5: return true;
			break;
		default: return false;
			break;
	}
	return true;
}

void menuLoop() {
	int c = 0;
	while (c != 5) {
		menuType();
		while ((!getNumber(c)) && (!choiceType(c))) {
			cout << "Opção Inválida!" << endl; 	
			menu();
		} 
	}
}