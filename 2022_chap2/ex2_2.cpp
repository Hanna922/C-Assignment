#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>

using namespace std;
// 클래스 선언
class MoneyBox {
private:
	char name[20];
	int sum;
public:
	MoneyBox();  // 디폴트 생성자
	MoneyBox(const char* np, int m = 0);  // 오버로디드 생성자
	MoneyBox(const MoneyBox& br);  // 복사 생성자
	~MoneyBox() { } // 소멸자
	void save(int m);
	void use(int m);
	void prn();
};
// 멤버함수 정의
MoneyBox::MoneyBox()
{
	strcpy(this->name, "아무개");
	this->sum = 0;
	cout << "디폴트 생성자 호출..." << this->name << endl;
}

MoneyBox::MoneyBox(const char* np, int m)
{
	strcpy(this->name, np);
	this->sum = m;
	cout << "오버로디드 생성자 호출..." << this->name << endl;
}

MoneyBox::MoneyBox(const MoneyBox& br)
{
	strcpy(this->name, br.name);
	this->sum = br.sum;
	cout << "복사 생성자 호출..." << this->name << endl;
}

void MoneyBox::save(int m)
{
	if (m >= 0) { this->sum += m; }
}

void MoneyBox::use(int m)
{
	if (m > 0 && m <= this->sum) { this->sum -= m; }
}

void MoneyBox::prn()
{
	cout << "이름 : " << this->name << endl;
	cout << "잔액 : " << this->sum << endl;
}

MoneyBox func(MoneyBox m);  // 객체를 리턴하는 일반함수
int main()
{
	MoneyBox a;
	MoneyBox b("홍길동");
	MoneyBox c("이순신", 500);
	MoneyBox d = b;
	MoneyBox* mp1 = new MoneyBox("홍길동");
	MoneyBox* mp2 = new MoneyBox(c);

	func(b);

	delete mp1;
	delete mp2;

	return 0;
}
MoneyBox func(MoneyBox m)
{
	return m;
}
