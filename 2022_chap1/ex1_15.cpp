#include <iostream>
using namespace std;
void char_prn(char ch='#', int cnt=5);  // 기본 전달인자 사용
// void char_prn(char=‘#’, int=5);       //  매개변수 이름은 생략가능

int main()
{
	char_prn();
	char_prn('@');
	char_prn('@', 10);

	return 0;
}

void char_prn(char ch, int cnt)  // 정의에는 기본 전달인자가 없다!
{
	int i;
	for(i=0; i<cnt; i++)
	{
		cout << ch;
	}
	cout << endl; 
}
