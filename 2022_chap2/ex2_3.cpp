#pragma warning(disable : 4996)
#include<iostream>
using namespace std;
#include<string.h>
class Wow
{
private:
	char name[20];
	int age;
public:
	Wow(const char * = "무명씨", int = 0);
	~Wow(void) { };
	void update(const char *, int);
	void output();
};
Wow::Wow(const char *p, int n) : age(n)  // 콜론초기화
{
	strcpy(name, p); // name 멤버는 콜론초기화 기법을 사용할 수 없다
}
void Wow::update(const char *p, int n)
{
	strcpy(name, p);
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
	Wow person3 = person2;
	person1.output();
	person3.output();
	person3.update("King Kong", 77);
	person3.output();
	return 0;
}
