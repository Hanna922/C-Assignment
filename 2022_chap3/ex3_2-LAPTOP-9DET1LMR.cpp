#include <iostream>
using namespace  std;
 class Time{
 private:
int hour;  // �ð��� ������ �����͸��
int min;  // ���� ������ �����͸��
  public:
Time(int h=0, int m=0);  // ������
	Time operator+(const Time &br);  // ���������� ����Լ�
	Time operator-();  // Unary minus ������ ����Լ�
	Time &operator++();  // ����ǥ�� ����������
	Time operator++(int);  // ����ǥ�� ����������
	Time operator*(int);
	void show();  // �ð��� ����ϴ� ����Լ�
  };

  Time::Time(int h, int m)
  {
	hour=h;
	min=m;
  }

  Time Time::operator+(const Time &br)
  {
	int h, m;  // �ð�, ���� �ӽ÷� ������ ����
	h=hour+br.hour;  // �ð��� ��
	m=min+br.min;  // ���� ��
	if(m>=60){  // ���� ���� 60�� �̻��̸�
	    h+=m/60;  // �ð��� �߰�
	    m=m%60;  // ������ �� ���
	}
	Time res(h, m);  // �ӽð�ü ����
	return res;  // �ӽð�ü�� �����Ѵ�.
  }	

  Time Time::operator-()  // �Ű������� ����.
  {
	 Time temp(-hour, -min);  // ��ȣ�� �ٲپ� �ӽð�ü ����
	 return temp;  // �ӽð�ü ����
  }

  Time &Time::operator++()  // ����ǥ�� ���������� 
  {
	 min++;
	 if(min==60){
	     hour++;
	     min=0;
	 }
	 cout << "prefix..." << endl;
	 return *this;  // ������ ��ü�� �����Ѵ�.
  }

  Time Time::operator++(int)  // ����ǥ�� ����������
  {
	Time temp(hour, min);  // �����Ǳ� ���� ��ü�� �ӽ� �����Ѵ�.
	min++;
	if(min==60){
	    hour++;
	    min=0;
	}
	cout << "postfix..." << endl;
	return temp;   // �����Ǳ� ���� ��ü�� �����Ѵ�.
  }

  void Time::show()
  {
	cout << hour << "�ð� " << min << "��" << endl;
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
	//a.show();  // 5�ð� 50��
	//b.show();  // 3�ð� 30��
	//c.show();  // 2�ð� 20��

	//c=++a+b;
	//a.show();  // 5�ð� 51��
	//b.show();  // 3�ð� 30��
	//c.show();  // 9�ð� 21�� 

	//c=a+b++;
	//a.show();  // 5�ð� 51��
	//b.show();  // 3�ð� 31��
	//c.show();  // 9�ð� 21��

	//func(++a);
	//a.show();  // 5�ð� 53��

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

