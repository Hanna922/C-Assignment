#include<iostream>
using  namespace  std;
const int& sub(int);

int a = 5;
int  main()
{
	int b = 10, res;
	cout << "a=" << a << "  b=" << b << endl;
	res = sub(b);
	//sub(b) = 7;
	cout << "res = " << res << endl;
	return 0;
}
const int& sub(int x)
{
	cout << "x = " << x << endl;
	return a;
}
