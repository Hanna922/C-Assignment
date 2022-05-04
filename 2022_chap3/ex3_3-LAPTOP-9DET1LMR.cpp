#include<iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
public:
	/*Time() {
		cout << "default  생성자 호출..." << endl;
		hour = min = 0;
	}*/
	Time(int h = 0, int m = 0);  // 시, 분을 받는 오버로디드 생성자
	Time(double t);  // 시간을 실수값으로 초기화하는 생성자
	//operator double() const;  // double 형변환함수
	//operator int() const; // int 형변환함수
	double to_double();
	int to_int();
	void show(); // 멤버 출력함수
};

Time::Time(int h, int m)
{
	cout << "int, int  생성자 호출..." << endl;
	hour = h;
	min = m;
}

Time::Time(double t)
{
	cout << "double 생성자 호출..." << endl;
	hour = int(t);
	min = (int)((t - hour)*60.0);
}

double Time::to_double()
{
	cout << "to_double() 함수 호출..." << endl;
	double temp;
	temp = hour + min / 60.0;
	return temp;
}

int Time::to_int()
{
	cout << "to_int() 함수 호출..." << endl;
	double temp;
	temp = hour;
	return temp;
}

//Time::operator double() const
//{
//	cout << "double 형변환함수 호출..." << endl;
//	double temp;
//	temp = hour + min / 60.0;
//	return temp;
//}
//
//Time::operator int() const
//{
//	cout << "int 형변환함수 호출..." << endl;
//	int temp;
//	temp = hour;
//	return temp;
//}

void Time::show()
{
	cout << this->hour << "시간 " << this->min << "분" << endl;
}

int main()
{
	//Time a;
	//// a = 3.5; // a = Time(3.5);
	//a = Time(3.5);
	//a.show();
	//
	//// a = 3; // a = Time((double)3);
	//a = (Time)3.5;
	//a.show();

	Time a;
	// a = 3.5;  // 생성자 함수 호출
	a.show();

	double res;
	res = 1.0 + a.to_double();  // operator double() 형변환 멤버함수 호출
	cout << res << endl;

	res = 2.7 + a.to_int();
	cout << res << endl;

	return 0;
}