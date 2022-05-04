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
	Wow(const char * = "����", int = 0);
	Wow(const Wow& r);
	~Wow(void) {
		delete[] this->name;
	};
	void update(const char *, int);
	void output();
};
Wow::Wow(const char *p, int n) : age(n)  // �ݷ��ʱ�ȭ
{
	this->name = new char[strlen(p) + 1];
	strcpy(name, p); // name ����� �ݷ��ʱ�ȭ ����� ����� �� ����
}
Wow::Wow(const Wow& r) : age(r.age) {
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	//this->age = r.age;
}
void Wow::update(const char *p, int n)
{
	delete[] this->name; // 1. ���� �޸𸮸� ���� (�޸� ����(leak) ����) !!!!!!!!!!�ſ��߿�!!!!!!!!
	this->name = new char[strlen(p) + 1]; // 2. �� �޸� �Ҵ�
	strcpy(name, p); // 3. �̸� ���ڿ��� �� �޸𸮿� ����
	age = n;
}
void Wow::output()
{
	cout << "* �̸� : " << name << endl;
	cout << "* ���� : " << age << endl;
}
int main()
{
	Wow person1;
	Wow person2("King", 20);
	Wow person3 = person2; // ��������� (deep copy cons.)
	person1.output();
	person3.output();
	person3.update("King Kong", 77);
	person3.output();
	return 0;
}
