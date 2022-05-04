#pragma warning (disable : 4996)
#include <iostream>
using namespace std;
#include <string.h>

//class Fund; //forward 선언문

class MoneyBox; //forward 선언문
// Fund 클래스 정의
class Fund {
private:
	int sum;
public:
	Fund(int m = 0);
	void donate(MoneyBox& br, int m);  // 모금 함수
	friend ostream& operator<<(ostream& os, Fund& br);
};

// MoneyBox 클래스 정의
class MoneyBox {
	//friend class Fund;  // 프렌드 클래스 선언
	friend void Fund::donate(MoneyBox&, int);
private:
	char name[20];
	int sum;
public:
	MoneyBox(const char *np = "아무개", int m = 0);
	void save(int m);
	void use(int m);
	friend ostream &operator<<(ostream &os, MoneyBox &br);
};

// MoneyBox 클래스의 멤버함수 정의
MoneyBox::MoneyBox(const char *np, int m)
{
	strcpy(name, np);
	sum = m;
}

void MoneyBox::save(int m)
{
	sum += m;
}

void MoneyBox::use(int m)
{
	sum -= m;
}

// Fund 클래스의 멤버함수 정의
Fund::Fund(int m)
{
	sum = m;
}

void Fund::donate(MoneyBox &br, int m)
{
	if (m > br.sum) {
		cout << "잔액이 부족합니다!" << endl;
		return;
	}
	br.sum -= m;
	sum += m;
	cout << br.name << "님은 " << m << "원 기부했다." << endl;
}

// 출력연산자 프렌드함수 선언
ostream &operator<<(ostream &os, MoneyBox &br);
ostream &operator<<(ostream &os, Fund &br);
// 메인함수
int main()
{
	MoneyBox a("철이", 100), b("메텔", 500);
	Fund angel;

	cout << "기부 전 잔액..." << endl;
	cout << a << b << endl;

	angel.donate(a, 50);
	angel.donate(b, 200);

	cout << "\n기부 후 잔액..." << endl;
	cout << a << b << endl;

	cout << angel << endl;

	return 0;
}

// 출력연산자 프렌드함수 정의
ostream &operator<<(ostream &os, MoneyBox &br)
{
	os << "이름 : " << br.name << ", ";
	os << "잔액 : " << br.sum << endl;
	return os;
}

ostream &operator<<(ostream &os, Fund &br)
{
	cout << "현재까지 적립금 : " << br.sum;
	return os;
}
