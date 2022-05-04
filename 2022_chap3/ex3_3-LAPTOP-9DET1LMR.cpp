#include<iostream>
using namespace std;

class Time
{
private:
	int hour;
	int min;
public:
	/*Time() {
		cout << "default  ������ ȣ��..." << endl;
		hour = min = 0;
	}*/
	Time(int h = 0, int m = 0);  // ��, ���� �޴� �����ε�� ������
	Time(double t);  // �ð��� �Ǽ������� �ʱ�ȭ�ϴ� ������
	//operator double() const;  // double ����ȯ�Լ�
	//operator int() const; // int ����ȯ�Լ�
	double to_double();
	int to_int();
	void show(); // ��� ����Լ�
};

Time::Time(int h, int m)
{
	cout << "int, int  ������ ȣ��..." << endl;
	hour = h;
	min = m;
}

Time::Time(double t)
{
	cout << "double ������ ȣ��..." << endl;
	hour = int(t);
	min = (int)((t - hour)*60.0);
}

double Time::to_double()
{
	cout << "to_double() �Լ� ȣ��..." << endl;
	double temp;
	temp = hour + min / 60.0;
	return temp;
}

int Time::to_int()
{
	cout << "to_int() �Լ� ȣ��..." << endl;
	double temp;
	temp = hour;
	return temp;
}

//Time::operator double() const
//{
//	cout << "double ����ȯ�Լ� ȣ��..." << endl;
//	double temp;
//	temp = hour + min / 60.0;
//	return temp;
//}
//
//Time::operator int() const
//{
//	cout << "int ����ȯ�Լ� ȣ��..." << endl;
//	int temp;
//	temp = hour;
//	return temp;
//}

void Time::show()
{
	cout << this->hour << "�ð� " << this->min << "��" << endl;
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
	// a = 3.5;  // ������ �Լ� ȣ��
	a.show();

	double res;
	res = 1.0 + a.to_double();  // operator double() ����ȯ ����Լ� ȣ��
	cout << res << endl;

	res = 2.7 + a.to_int();
	cout << res << endl;

	return 0;
}