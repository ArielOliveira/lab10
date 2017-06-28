#ifndef ARIELSLIB_LIST_H
#define ARIELSLIB_LIST_H

#include <iostream>
using std::cout;
using std::endl;

namespace edb1 {

	template<typename T>
	class List {
		private:
			struct Node {
				T data;
				Node *next;
				Node *previous;
			};
			int size;
			typename List<T>::Node *head;
			typename List<T>::Node *tail;
			void connect(typename List<T>::Node *inserted, typename List<T>::Node *sentry);
			void findNode(int index, typename List<T>::Node *&sentry);
		public:
			List();
			~List();

			void insertAtHead(T data);
			void insertAtTail(T data);
			bool insertAt(int index, T data);

			bool removeAtHead();
			bool removeAtTail();
			bool removeAt(int index);

			T getData(int index);

			void deleteList();
			void printList();
	};

	template <typename T>
	List<T>::List() {
		size = 0;
		head = new typename List<T>::Node;
		tail = new typename List<T>::Node;

		head->next = tail;
		tail->previous = head;
	}
	
	template <typename T>		
	List<T>::~List() {
		//deleteList();
	}
	
	template <typename T>
	void List<T>::insertAtHead(T data) {
		typename List<T>::Node *inserted = new typename List<T>::Node();
		inserted->data = data;
		inserted->next = NULL;
		inserted->previous = NULL;
		typename List<T>::Node *h = this->head;

		h->next->previous = inserted;
		inserted->next = h->next;

		h->next = inserted;
		inserted->previous = h;

		this->size++;
	}

	template <typename T>
	void List<T>::insertAtTail(T data) {
		typename List<T>::Node *inserted = new typename List<T>::Node();
		inserted->data = data;
		inserted->next = NULL;
		inserted->previous = NULL;
		typename List<T>::Node *t = this->tail;

		t->previous->next = inserted;
		inserted->previous = t->previous;

		t->previous = inserted;
		inserted->next = t;

		this->size++;
	}

	template <typename T>
	bool List<T>::insertAt(int index, T data) {
		if (index > size || index < 0) return false;

		typename List<T>::Node *inserted = new typename List<T>::Node();
		inserted->data = data;
		inserted->next = NULL;
		inserted->previous = NULL;
		typename List<T>::Node *sentry;

		findNode(index, sentry);
		connect(inserted, sentry);
		size++;

		return true;
	}
	
	template <typename T>
	bool List<T>::removeAtHead() {
		if (head->next == tail) return false;

		typename List<T>::Node *tmp = head->next;
		head->next = tmp->next;
		tmp->next->previous = head;
		delete tmp;

		return true;
	}
	
	template <typename T>
	bool List<T>::removeAtTail() {
		if (tail->previous == head) return false;

		typename List<T>::Node *tmp = tail->previous;
		tail->previous = tmp->previous;
		tmp->previous->next = tail;
		delete tmp;

		return true;
	}

	template <typename T>
	bool List<T>::removeAt(int index) {
		if (index > size || index < 0) return false;

		typename List<T>::Node *sentry;

		findNode(index, sentry);
		typename List<T>::Node *tmp = sentry->next;
		tmp->previous = sentry->previous;
		tmp->previous->next = tmp;
		delete sentry;

		return true;
	}

	template <typename T>
	T List<T>::getData(int index) {
		typename List<T>::Node *sentry;
		if (index <= size && index > 0) {
			findNode(index, sentry);
		} else {
			std::cout << "Impossível encontrar elemento. Posição fora da lista" << std::endl;
		}
			return sentry->data;
	}

	template <typename T>
	void List<T>::printList() {
		typename List<T>::Node *runner = head;
		while((runner = runner->next)) {
			std::cout << runner->data << std::endl;
		}
	}
	
	template <typename T>
	void List<T>::deleteList() {
		typename List<T>::Node *sentry = head->next;
		while ((sentry->next != NULL)) {
			sentry = sentry->next;
			delete sentry->previous;
		}
		delete head;
		delete tail;
	}
	
	template <typename T>
	void List<T>::connect(typename List<T>::Node *inserted, typename List<T>::Node *sentry) {
		inserted->previous = sentry->previous;
		sentry->previous->next = inserted;
		inserted->next = sentry;
		sentry->previous = inserted;
	}

	template <typename T>
	void List<T>::findNode(int index, typename List<T>::Node *&sentry) {
		if (index > size/2) {
			sentry = tail->previous;
			for (int count = size; count > index; count--) {
			sentry = sentry->previous;
			}
		}
	}

}


#endif