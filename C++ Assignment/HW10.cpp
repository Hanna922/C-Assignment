#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include<string.h>

class San {
private:
	char* name;
	int height;
public:
	San();
	San(const char*, int);
	San(const San& r);
	~San();
	San& operator = (const San& inp);
	void setName(char*);
	char* getName();
	void setHeight(int);
	int getHeight();
};

San::San() {
	this->name = new char[strlen("NoInput") + 1];
	strcpy(this->name, "NoInput");
	this->height = 0;
}

San::San(const char* n, int h) {
	this->name = new char[strlen(n) + 1];
	strcpy(this->name, n);
	this->height = h;
}

San::San(const San& r) {
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->height = r.height;
}

San::~San() {
	delete[] this->name;
}

San& San::operator=(const San& inp) {
	if (this == &inp) return *this;
	delete[] name;
	name = new char[strlen(inp.name) + 1];
	strcpy(this->name, inp.name);
	height = inp.height;
	return *this;
}

void San::setName(char* n) {
	delete[] this->name;
	this->name = new char[strlen(n) + 1];
	strcpy(name, n);
}

char* San::getName() {
	return name;
}

void San::setHeight(int h) {
	this->height = h;
}

int San::getHeight() {
	return height;
}

int main() {
	char str[100];
	San a("관악", 629);
	San b = a;
	//San b;
	//b = a;
	
	cout << "이름 : " << b.getName() << endl;
	cout << "높이 : " << b.getHeight() << "m" << endl;
	cout << "새로운 산이름을 입력 하시오 : " << endl;
	cin >> str;

	b.setName(str);
	b.setHeight(1234);

	cout << "이름 : " << b.getName() << endl;
	cout << "높이 : " << b.getHeight() << "m" << endl;

	return 0;
}