#include <iostream>
#include <string>
using namespace std;

template<class T> class List { // список
public:
	List();
	~List();

	template<class T> void push_back(T data);
	template<class T> void pop_front();
	template<class T> void clear();
	template<class T> void push_front(T data);
	template<class T> void insert(T value, const int index);
	template<class T> void removeAt(const int index);
	template<class T> void pop_back();

	template<class T> T& List<T>::operator[](const int index); 

private:
	template<class T> class Elem {
	public:
		Elem *pn;
		T data;
		Elem(T data = T(), Elem *pn = nullptr) {
			this->data = data;
			this->pn = pn;
		}
	};
	Elem<T> *head;
	int length;
};

template<class T> List<T>::List() {
	length = 0;
	head = nullptr;
}

template<class T> void List<T>::~List() {
	clear();
}

template<class T> void List<T>::push_back(T data) {
	if (head == nullptr) { 
		head = new Elem<T>(data);
	}
	else {
		Elem<T> *temp = this->head; 
		while (temp.pn != nullptr) { 
			temp = temp.pn; 
		}
		temp.pn = new Elem<T>(data);	
	}
	length++;
}

template<class T> T& List<T>::operator[](const int index) {
	int count = 0;
	Elem<T> *temp = this->head;
	while (temp.pn != nullptr) {
		if (count == index) {
			return temp.data;
		}
		else {
			temp = temp.pn;
			count++;
		}
	}
}

template<class T> void List<T>::pop_front() {
	Elem<T>* temp = head;
	head = head->pn;
	delete temp;
	length--;
}

template<class T> void List<T>::clear() {
	while (length != 0) 
	{
		pop_front();
	}
}

template<class T> void List<T>::push_front(T data) {
	head = new Elem<T>(data, head);
	length++;
}

template<class T> void List<T>::insert(T value, const int index) {
	if (index == 0) {
		push_front(value);
	}
	else {
		Elem<T>* temp = this->head;
		for (int i = 0; i < index-1; i++)
		{
			temp = temp.pn;
		}
			Elem<T>* newElem = new Elem(value, temp.pn);
			temp.pn = newElem;
			length++;
		}
}

template<class T> void List<T>::removeAt(const int index) {
	if (index == 0) { pop_front(); }
	else {
		Elem<T>* prev = this->head;
		for (int i = 0; i < index - 1; i++) {
			prev = prev.pn;
		}
		Elem<T>* toDel = prev.pn;
		prev.pn = toDel.pn;
		delete toDel;
		length--;
	}
}

template<class T> void List<T>::pop_back() {
	removeAt(length - 1);
}


int main() {
	List<int> lst;
	lst.push_back(6);
	lst.push_back(62);
	lst.push_back(36);
	lst.push_back(90);
	cout « lst[0] « endl;
	return 0;
}