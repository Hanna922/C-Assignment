#include <iostream>
#include <string>
using namespace std;
int main()
{
	string temp;
	cout << "여백 없는 문자열 입력 : ";
	cin >> temp;
	cout << "여백 없는 문자열 입력 결과 : " << temp << endl;
	cin.ignore(); // 입력 버퍼에서 개행 문자 삭제
	cout << "여백 있는 문자열 입력 : ";
	getline(cin, temp);
	cout << "여백 있는 문자열 입력 결과 : " << temp << endl;
	return 0;
}
