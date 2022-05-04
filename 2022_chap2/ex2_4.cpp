#include <iostream>
using namespace std;
class Letter {
private:
	const char ch;  // const 데이터멤버
	int num;
public:
	Letter(char c = '*', int n = 0);
	void n_prn();
	void c_prn() const;  // const 멤버함수
	void show();
};

Letter::Letter(char c, int n) : ch(c)
{
	num = n;
}

void Letter::n_prn()
{
	// ch='@';  -> 에러, const 데이터멤버는 수정할 수 없다.
	num += 10;
	cout << "const가 아닌 멤버함수 호출..." << endl;
	show();
}

void Letter::c_prn() const
{
	// num+=10;  -> 에러, const멤버함수이므로 수정할 수 없다.
	cout << "const 멤버함수 호출..." << endl;
	// show();  -> 에러, const멤버함수는 일반 멤버함수 호출불가
}

void Letter::show()
{
	int i;
	for (i = 0; i < num; i++) {
		cout << ch;
	}
	cout << endl;
}

int main()
{
	Letter a('@', 5);
	const Letter b('#', 3);

	a.n_prn();  // non const 멤버함수 호출
	a.c_prn();
	//b.n_prn();  //-> 에러, const객체는 const가 아닌 멤버 호출불가
	b.c_prn();  // const 멤버함수 호출

	return 0;
}
