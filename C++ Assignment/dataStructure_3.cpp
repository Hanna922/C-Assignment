#include <iostream>
#include <numeric>
using namespace std;

template <class T> class Chain;

template <class T>
class ChainNode {
	friend class Chain<T>;
private:
	T data;
	ChainNode<T>* link;
};

template <class T>
class Chain {
private:
	ChainNode<T>* first;
	ChainNode<T>* last;
public:
	Chain() { first = 0, last = 0; }; //(1) constructor initializing first to 0
	~Chain(); //(2)
	//Chain manipulation operations
	void insertFront(T data); //(3)
	void insertBack(T data); //(4)
	T front(); //(5)
	T back(); //(6)
	T get(int i); //(7)
	void deleteFront(); //(8)
	void deleteBack(); //(9)
	void insert(T data, int index); //(10)
	void remove(int index); //(11)
	
	class ChainIterator { //(12)
	private:
		ChainNode<T>* current;
	public:
		//typedefs required by C++ for a forward iterator omitted

		//constructor
		ChainIterator(ChainNode<T>* startNode = 0) {
			current = startNode;
		}

		//dereferencing operators
		T& operator*() const {
			return current->data;
		}
		T* operator->() const {
			return &current->data;
		}

		//increment
		ChainIterator& operator++() { //preincrement
			current = current->link;
			return *this;
		}
		ChainIterator operator++(int) { //postincrement
			ChainIterator old = *this;
			current = current->link;
			return old;
		}

		//equality testing
		bool operator != (const ChainIterator right) const {
			return current != right.current;
		}
		bool operator == (const ChainIterator right) const {
			return current == right.current;
		}
	};
	
	ChainIterator begin() { return ChainIterator(first); }
	ChainIterator end() { return ChainIterator(0); }
};

class Number {
private:
	int num;
public:
	Number(int n = 0) : num(n) {
		cout << "Number(int n = 0)" << endl;
	}
	Number& operator = (const Number& ref) {
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	operator int() {
		return num;
	}
	void ShowNumber() {
		cout << num << endl;
	}
};

template<class T>
Chain<T>::~Chain() {
	delete first, last;
}

template<class T>
void Chain<T>::insertFront(T data) {
	ChainNode<T>* newNode = new ChainNode<T>;
	if (this->first == NULL) {
		this->first = newNode;
		newNode->link = NULL;
		this->last = newNode;
	}
	else {
		newNode->link = this->first;
		this->first = newNode;
	}
	newNode->data = data;
}

template<class T>
void Chain<T>::insertBack(T data) {
	ChainNode<T>* newNode = new ChainNode<T>;
	if (this->first == NULL) {
		this-> first = newNode;
		this->last = newNode;
	}
	else {
		this->last->link = newNode;
		this->last = newNode;
	}
	newNode->data = data;
	newNode->link = NULL;
}

template<class T>
T Chain<T>::front() {
	return this->first->data;
}

template<class T>
T Chain<T>::back() {
	return this->last->data;
}

template<class T>
T Chain<T>::get(int index) {
	ChainNode<T>* x = this->first;
	for (int i = 0; i < index; i++) {
		x = x->link;
	}
	return x->data;
}

template<class T>
void Chain<T>::deleteFront() {
	ChainNode<T>* x = this->first;
	this->first = x->link;
	delete x;
}

template<class T>
void Chain<T>::deleteBack() {
	ChainNode<T>* x = first;
	ChainNode<T>* y = first;
	while (x->link != NULL) {
		y = x;
		x = x->link;
	}
	last = y;
	last->link = NULL;
	delete x, y;
}

template<class T>
void Chain<T>::insert(T data, int index) {
	ChainNode<T>* newNode = new ChainNode<T>;
	ChainNode<T>* x = first;
	for (int i = 0; i < index; i++) {
		x = x->link;
	}
	newNode->data = data;
	newNode->link = x->link;
	x->link = newNode;
}

template<class T>
void Chain<T>::remove(int index) {
	ChainNode<T>* x = first;
	ChainNode<T>* y = first;
	for (int i = 0; i < index; i++) {
		x = x->link;
	}
	for (int j = 0; j < index - 1; j++) {
		y = y->link;
	}
	y->link = x->link;
	delete x, y;
}

int main() {
	Number num1 = 1;
	Number num2 = 2;
	Number num3 = 3;
	Number num4 = 4;
	Number num5 = 5;
	Number num6 = 6;
	Number num7 = 7;
	Number num8 = 8;
	Number num9 = 9;
	Chain<Number> chain;
	chain.insertFront(num1);
	chain.insertBack(num2);
	chain.insertBack(num3);
	chain.insertBack(num4);
	chain.insertBack(num5);
	chain.insertBack(num6);
	chain.insertBack(num7);
	chain.insertBack(num8);
	chain.insertBack(num9); //test1

	Chain<Number>::ChainIterator yi = chain.begin();
	
	cout << "test2 : ";
	for (yi = chain.begin(); yi != chain.end(); ++yi) {
		cout << *yi << " ";
	}
	
	cout << endl << "test3,4 : ";
	chain.insertFront(0);
	for (yi = chain.begin(); yi != chain.end(); ++yi) {
		cout << *yi << " ";
	}

	cout << endl << "test5,6 : ";
	chain.insertBack(10);
	for (yi = chain.begin(); yi != chain.end(); ++yi) {
		cout << *yi << " ";
	}

	cout << endl << "test7 : ";
	cout << chain.front();
	
	cout << endl << "test8 : ";
	cout << chain.back();
	
	cout << endl << "test9 : ";
	cout << chain.get(2);

	cout << endl << "test10,11 : ";
	chain.deleteFront();
	for (yi = chain.begin(); yi != chain.end(); ++yi) {
		cout << *yi << " ";
	}

	cout << endl << "test12,13 : ";
	chain.deleteBack();
	for (yi = chain.begin(); yi != chain.end(); ++yi) {
		cout << *yi << " ";
	}

	cout << endl << "test14,15 : ";
	chain.insert(100, 2);
	for (yi = chain.begin(); yi != chain.end(); ++yi) {
		cout << *yi << " ";
	}

	cout << endl << "test16,17 : ";
	chain.remove(6);

	int Sum = accumulate(chain.begin(), chain.end(), 0);
	cout << Sum << endl;
	
	return 0;
}