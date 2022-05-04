#include <iostream>
using namespace std;
void exchange(int x, int y);
int main()
{
	int a=10, b=20;
	cout << "바꾸기 전 a, b의 값 : ";
	cout << a << ' ' << b << endl;
	exchange(a, b);
	cout << "바꾼 후 a, b의 값 : ";
	cout << a << ' ' << b << endl;
	return 0;
}
void exchange(int x, int y)  // 매개변수로 참조변수를 사용
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
