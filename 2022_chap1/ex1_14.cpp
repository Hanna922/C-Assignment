#include <iostream>
using namespace std;
void square(int);  // unsigned int형이나 long형이면 에러
void square(double);

int main()
{
	char ch='A';
	short sh=10;
	float ft=3.4f;
	double db=3.4;

	square(ch);  // square(int) 호출
	square(sh);  // square(int) 호출
	square(ft);  // square(double) 호출
	square(db);  // square(double) 호출

	return 0;
}

void square(int a)
{
	cout << "int형으로 호출 : " << a*a << endl;
}

void square(double a)
{
	cout << "double형으로 호출 : " << a*a << endl;
}
