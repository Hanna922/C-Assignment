#include<iostream>
using namespace std;
class Sample {
private:
	int num;
	static int cnt;      // 정적멤버변수 선언부
public:
	Sample(int n = 0);
	void prn() const;
	static void setNum(int n);  // 정적멤버함수선언
};

int Sample::cnt = 0;  // 정적 멤버변수 정의부 

void Sample::setNum(int n)  // 정적 멤버함수 정의
{
	cnt = n;  // 정적 멤버변수의 값을 변경한다.
}
Sample::Sample(int n)  // 오버로디드생성자정의
{
	num = n;
	cnt++;  // 객체가 생성될 때 마다 1씩 증가한다.
}

void Sample::prn() const  // 출력멤버함수정의
{
	cout << "num : " << num << ", ";
	cout << "cnt : " << cnt << endl;
}

int main()
{
	int start;

	cout << "시작값을입력하세요: ";
	cin >> start;
	Sample::setNum(start);  // 객체 없이 독립적으로 호출 가능 

	Sample a(10), b(20), c(30);  // 시작값3을입력하면…
	a.prn();
	b.prn();
	c.prn();
	return 0;
}
