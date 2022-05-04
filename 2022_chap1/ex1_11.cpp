#include<iostream>
using std::cout;
using std::endl;
namespace // 해당 파일에서만 접근가능(Internal Linkage)
{
	int number = 10;
	void func()
	{
		cout << "func" << endl;
	}
}
int main()
{
	cout << number << endl;
	func();
	return 0;
}
