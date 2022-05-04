#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>

using namespace std;
// 클래스 선언
class MoneyBox {
private:
	//char name[20];
	char* name; // 멤버 중에 포인터멤버가 있고 포인터멤버에 부가 메모리를 할당하여 사용하는 경우
	// 생성자에서 메모리 할당하고 소멸자에서 메모리 해제해야하므로 생성자와 소멸자 함수는
	// 무조건 개발자가 코딩해야한다 (즉, 컴파일러가 제공하는 default cons., bit copy cons.는 사용불가 !!
	int sum;
public:
	MoneyBox();  // 디폴트 생성자
	MoneyBox(const char* np, int m = 0);  // 오버로디드 생성자
	MoneyBox(const MoneyBox& br);  // 복사 생성자
	~MoneyBox() { // 소멸자
		cout << this->name << "소멸자 수행중..." << endl;
		delete[] this->name;
	}
	void save(int m);
	void use(int m);
	void prn();
};
// 멤버함수 정의
MoneyBox::MoneyBox()
{
	this->name = new char[strlen("아무개") + 1];
	// 문자열 뒤에 붙는 null 문자를 고려하여 1Byte를 플러스 해야 함 !!
	strcpy(this->name, "아무개");
	this->sum = 0;
	cout << "디폴트 생성자 호출..." << this->name << endl;
}

MoneyBox::MoneyBox(const char* np, int m)
{
	this->name = new char[strlen(np) + 1];
	strcpy(this->name, np);
	this->sum = m;
	cout << "오버로디드 생성자 호출..." << this->name << endl;
}

MoneyBox::MoneyBox(const MoneyBox& br)
{
	this->name = new char[strlen(br.name) + 1];
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

MoneyBox& func(MoneyBox& m);  // 객체를 리턴하는 일반함수
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
MoneyBox& func(MoneyBox& m)
{
	return m;
}