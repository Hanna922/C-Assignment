#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <random>
using namespace std;

std::random_device rd;
std::mt19937 gen(rd());

class Bizcard {
private:
	char* name;
	char* address;
	long long int office_phone;
	long long int mobile_phone;
public:
	Bizcard() {};
	Bizcard(const char* name, const char* address, long long int office_phone, long long int mobile_phone);
	Bizcard(const Bizcard& copy);
	Bizcard& operator=(const Bizcard& ref);
	~Bizcard();
	void ShowInfo();
};

Bizcard::Bizcard(const char* name, const char* address, long long int office_phone, long long int mobile_phone) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);
	this->office_phone = office_phone;
	this->mobile_phone = mobile_phone;
}

Bizcard::Bizcard(const Bizcard& copy) {
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
	address = new char[strlen(copy.address) + 1];
	strcpy(address, copy.address);
	this->office_phone = copy.office_phone;
	this->mobile_phone = copy.mobile_phone;
}

Bizcard& Bizcard::operator=(const Bizcard& ref)
{
	delete[] name;
	delete[] address;
	name = new char[strlen(ref.name) + 1];
	address = new char[strlen(ref.address) + 1];
	strcpy(name, ref.name);
	strcpy(address, ref.address);
	office_phone = ref.office_phone;
	mobile_phone = ref.mobile_phone;
	return *this;
}

Bizcard::~Bizcard() {
}

void Bizcard::ShowInfo() {
	cout << "name : " << name << endl;
	cout << "address : " << address << endl;
	cout << "office_phone : " << office_phone << endl;
	cout << "mobile_phone : " << mobile_phone << endl;
}

template <class T>
class Bag {
private:
	T* array;
	int capacity;
	int top;
public:
	Bag(int bagCapacity = 3);
	~Bag();
	
	int Size() const;
	bool IsEmpty() const;
	T& Element() const;
	
	void ChangeSize1D(T*& a, const int oldSize, const int newSize);
	void Push(const T&);
	void Pop();
};

template<class T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity) {
	if (capacity < 1) throw "Capacity must be > 0";
	array = new T[capacity];
	top = -1;
}

template<class T>
Bag<T>::~Bag() {
	delete[] array;
}

template<class T>
inline int Bag<T>::Size() const {
	cout << "Bag's Size : " << top + 1 << endl;
	return top + 1;
}

template<class T>
inline bool Bag<T>::IsEmpty() const {
	bool value = Size() == 0;
	cout << "Bag's IsEmpty : " << value << endl;
	return value;
}

template<class T>
inline T& Bag<T>::Element() const {
	bool value = Size() == 0;
	if (value) {
		cout << "Bag is empty" << endl;
	}
	else {
		std::uniform_int_distribution<int> dis(0, sizeof(array) / sizeof(array[0]));
		int ranValue = dis(gen);
		return array[ranValue];
	}
}

template<class T>
void Bag<T>::ChangeSize1D(T*& a, const int oldSize, const int newSize) {
	if (newSize < 0) throw "New length must be >= 0";
	T* temp = new T[newSize];
	int number = min(oldSize, newSize);
	copy(a, a + number, temp);
	delete[] a;
	a = temp;
}

template<class T>
void Bag<T>::Push(const T& x) {
	if (capacity == top + 1) {
		ChangeSize1D(array, capacity, 2 * capacity);
		capacity *= 2;
	}
	array[++top] = x;
}

template<class T>
void Bag<T>::Pop() {
	if (IsEmpty()) throw "Bag is empty, cannot delete";
	std::uniform_int_distribution<int> dis(0, sizeof(array) / sizeof(array[0]));
	int value = dis(gen);
	int deletePos = value;
	copy(array + deletePos + 1, array + top + 1, array + deletePos);
	array[top--].~T();
}

int main() {
	Bizcard a("AAA", "AAA", 12345678901, 12345678912);
	Bizcard b("BBB", "BBB", 12345678901, 12345678912);
	Bizcard c("CCC", "CCC", 12345678901, 12345678912);

	Bag<Bizcard> myBag;
	cout << myBag.Size() << endl;
	myBag.IsEmpty();
	Bizcard test1 = myBag.Element();
	test1.ShowInfo();

	myBag.Push(a);
	myBag.Push(b);
	myBag.Push(c);
	myBag.Size();
	myBag.IsEmpty();
	Bizcard test2 = myBag.Element();
	test2.ShowInfo();

	myBag.Push(a);
	myBag.Push(a);
	myBag.Push(a);
	myBag.Push(a);
	myBag.Size();
	myBag.IsEmpty();
	Bizcard test3 = myBag.Element();
	test3.ShowInfo();
	
	myBag.Pop();
	myBag.Pop();
	myBag.Size();
	myBag.IsEmpty();
	Bizcard test4 = myBag.Element();
	test4.ShowInfo();

	return 0;
}