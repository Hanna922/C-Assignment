#include<iostream>
using namespace std;
int main(void)
{
	int a = 10, b = 126;
	float f = 3.14, g = 5.0;
	cout.setf(ios::showpos);
	cout << a << endl;
	cout << f << endl;
	cout << hex << a << endl;
	cout.setf(ios::showbase);
	cout << a << endl;
	cout << b << endl;
	cout.setf(ios::uppercase);
	cout << a << endl;
	cout << b << endl;
	cout.setf(ios::showpoint);
	cout << f << endl;
	cout << g << endl;
	return 0;
}
