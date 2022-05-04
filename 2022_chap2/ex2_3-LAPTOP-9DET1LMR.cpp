#pragma warning(disable : 4996)
#include<iostream>
using namespace std;
#include<string.h>
class Wow
{
private:
	//char name[20];
	char* name;
	int age;
public:
	Wow(const char * = "무명씨", int = 0);
	Wow(const Wow& r);
	~Wow(void) {
		delete[] this->name;
	};
	void update(const char *, int);
	void output();
};
Wow::Wow(const char *p, int n) : age(n)  // 콜론초기화
{
	this->name = new char[strlen(p) + 1];
	strcpy(name, p); // name 멤버는 콜론초기화 기법을 사용할 수 없다
}
Wow::Wow(const Wow& r) : age(r.age) {
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	//this->age = r.age;
}
void Wow::update(const char *p, int n)
{
	delete[] this->name; // 1. 기존 메모리를 해제 (메모리 누수(leak) 방지) !!!!!!!!!!매우중요!!!!!!!!
	this->name = new char[strlen(p) + 1]; // 2. 새 메모리 할당
	strcpy(name, p); // 3. 이름 문자열을 새 메모리에 복사
	age = n;
}
void Wow::output()
{
	cout << "* 이름 : " << name << endl;
	cout << "* 나이 : " << age << endl;
}
int main()
{
	Wow person1;
	Wow person2("King", 20);
	Wow person3 = person2; // 복사생성자 (deep copy cons.)
	person1.output();
	person3.output();
	person3.update("King Kong", 77);
	person3.output();
	return 0;
}
