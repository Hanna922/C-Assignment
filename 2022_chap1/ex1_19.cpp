#include <iostream>
using namespace std;

int sub(int &num);
int main()
{
	int res;
	res = sub(10+20); // 에러 발생
	cout << res << endl;
	return 0;
}				
int sub(int &num)  
{
	return num * num;
}
