#include <iostream>
using namespace  std;

class Time {
private:
	int hour;  // 시간을 저장할 데이터멤버
	int min;  // 분을 저장할 데이터멤버
public:
	Time(int h = 0, int m = 0);  // 생성자
	Time operator*(int);  // 정수와 곱하는 연산자 멤버함수
	//void operator<<(ostream &os);  // 출력연산자 멤버함수
	//void operator>>(istream &is);  // 입력연산자 멤버함수
	friend ostream& operator<<(ostream& os, Time& br);
	friend istream& operator>>(istream& is, Time& br);
};

Time::Time(int h, int m)
{
	hour = h;
	min = m;
}

Time Time::operator*(int n)  // 곱하는 정수값을 매개변수로 받는다.
{
	int h, m;
	h = hour * n;
	m = min * n;
	if (m >= 60) {
		h += m / 60;
		m = m % 60;
	}
	return Time(h, m);
}

//void Time::operator<<(ostream& os)
//{
//	os << hour << "시간 " << min << "분" << endl;
//}
//
//void Time::operator>>(istream& is)
//{
//	cout << "Time::operator>>()" << endl;
//	is >> hour >> min;
//}

Time operator*(int n, Time &a);
ostream &operator<<(ostream &os, Time &br);
istream &operator>>(istream &is, Time &br);

int main()
{
	Time a, b;
	cout << "시간과 분을 입력하세요 : ";
	cin >> a;
	b = 3 * a;  // a.operator*(3) 호출, a의 시간과 분에 각각 3을 곱함
	cout << a << b;

	return 0;
}

Time operator*(int n, Time &a)  // 3*a를 a*3으로 바꾸는 일반함수
{
	return a * n;  // 전달인자로 받은 값의 위치를 바꾸어 연산한다.
}

ostream &operator<<(ostream &os, Time &br)  // 출력 일반함수
{
	// br << os;
	os << br.hour << "시 " << br.min << "분" << endl;
	return os;
}

istream &operator>>(istream &is, Time &br)  // 입력 일반함수
{
	cout << "extern operator>>()" << endl;
	// br >> is;
	is >> br.hour >> br.min;
	return is;
}
