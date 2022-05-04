#include<iostream>
using namespace std;
int main(void)
{
	float f = 3.14, g = 150.0;
	cout.setf(ios::showpos);
	cout.setf(ios::showpoint);
	cout.precision(3);
	cout << f << "\n";
	cout << g << "\n\n";
	cout.setf(ios::scientific, ios::floatfield);
	cout << f << "\n";
	cout << g << "\n\n";
	return 0;
}
