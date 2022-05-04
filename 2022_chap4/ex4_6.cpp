#include <iostream>
using namespace std;
class Base
{
public:
	virtual void view() { cout << "Base view..." << endl; }
};

class Derived : public Base
{
public:
	virtual void view() { cout << "Derived view..." << endl; } // 파생클래스의 virtual 
															   // 키워드는 생략 가능함
};

int main()
{
	Base a, *bp;
	Derived b;

	bp = &a;     // 기본클래스의 객체 참조
	bp->view();  // 기본클래스의 view함수 호출
	bp = &b;     // 파생클래스의 객체 참조
	bp->view();  // 파생클래스의 view함수 호출

	return 0;
}
