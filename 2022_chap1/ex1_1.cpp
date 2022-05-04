#include<iostream>
using namespace std;
void my_flush();
int main()
{
	int intNumber;
	double doubleNumber;
	char ch;
	char str[100];
	cout << "정수값입력 : ";
	cin >> intNumber;
	cout << "실수값 입력";
	cin >> doubleNumber;
	cout << "문자 입력: ";
	cin >> ch;
	cout << "문자열 입력 : ";
	cin >> str;
	cout << "intNumber = " << intNumber << endl;
	cout << "doubleNumber = " << doubleNumber << endl;
	cout << "ch = " << ch << endl;
	cout << "str = " << str << endl;
	my_flush();
	cout << "중간에 여백없는 문자열을 입력하세요 : ";
	cin.getline(str, sizeof(str));
	cout << "입력 받은 문자열 : " << str << endl;
	cout << "여백 문자를 입력하세요(space, tab, enter) : ";
	ch = cin.get(); //get()은 오버로딩된 멤버함수로 어떤 문자든 한 문자 읽어들임
	cout << "입력한 여백문자의 아스키코드 값 : " << (int)ch << endl;
	return 0; // <= 생략가능 
}
void my_flush() // 사용자가 만든 cin 입력 버퍼 지우기 함수
{
	while (cin.get() != '\n');
}
