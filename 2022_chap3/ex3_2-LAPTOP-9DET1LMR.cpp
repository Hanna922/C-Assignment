#include <iostream>
using namespace  std;
 class Time{
 private:
int hour;  // 시간을 저장할 데이터멤버
int min;  // 분을 저장할 데이터멤버
  public:
Time(int h=0, int m=0);  // 생성자
	Time operator+(const Time &br);  // 덧셈연산자 멤버함수
	Time operator-();  // Unary minus 연산자 멤버함수
	Time &operator++();  // 전위표기 증가연산자
	Time operator++(int);  // 후위표기 증가연산자
	Time operator*(int);
	void show();  // 시간을 출력하는 멤버함수
  };

  Time::Time(int h, int m)
  {
	hour=h;
	min=m;
  }

  Time Time::operator+(const Time &br)
  {
	int h, m;  // 시간, 분을 임시로 저장할 변수
	h=hour+br.hour;  // 시간의 합
	m=min+br.min;  // 분의 합
	if(m>=60){  // 더한 값이 60분 이상이면
	    h+=m/60;  // 시간에 추가
	    m=m%60;  // 나머지 분 계산
	}
	Time res(h, m);  // 임시객체 생성
	return res;  // 임시객체를 리턴한다.
  }	

  Time Time::operator-()  // 매개변수가 없다.
  {
	 Time temp(-hour, -min);  // 부호를 바꾸어 임시객체 생성
	 return temp;  // 임시객체 리턴
  }

  Time &Time::operator++()  // 전위표기 증가연산자 
  {
	 min++;
	 if(min==60){
	     hour++;
	     min=0;
	 }
	 cout << "prefix..." << endl;
	 return *this;  // 증가된 객체를 리턴한다.
  }

  Time Time::operator++(int)  // 후위표기 증가연산자
  {
	Time temp(hour, min);  // 증가되기 전의 객체를 임시 보관한다.
	min++;
	if(min==60){
	    hour++;
	    min=0;
	}
	cout << "postfix..." << endl;
	return temp;   // 증가되기 전의 객체를 리턴한다.
  }

  void Time::show()
  {
	cout << hour << "시간 " << min << "분" << endl;
  }

  Time Time::operator*(int n) {
	  int h, m;
	  h = hour * n;
	  m = min * n;
	  if (m >= 60) {
		  h += m / 60;
		  m = m % 60;
	  }
	  cout << "Time::operator*()" << endl;
	  return Time(h, m);
  }

  void func(Time &br);
  Time operator*(int n, Time& r);

  int main()
  {
	Time a(5, 50), b(3, 30), c;

	//c=-b+a;  // c.operator=(b.operator-().operator+(a))
	//a.show();  // 5시간 50분
	//b.show();  // 3시간 30분
	//c.show();  // 2시간 20분

	//c=++a+b;
	//a.show();  // 5시간 51분
	//b.show();  // 3시간 30분
	//c.show();  // 9시간 21분 

	//c=a+b++;
	//a.show();  // 5시간 51분
	//b.show();  // 3시간 31분
	//c.show();  // 9시간 21분

	//func(++a);
	//a.show();  // 5시간 53분

	c = b * 3;
	c.show();

	c = 3 * b;
	c.show();

	return 0;
  }

  void func(Time &br)
  {
	br++;
  }

  Time operator*(int n, Time& r) {
	  cout << "extern operator*()" << endl;
	  return r * n;
  }

