#include<iostream>
#include<iomanip> // setprecision, setw 사용을 위해 인클루드
using namespace std;
int main()
{
	int number = 12;
	cout << showbase;
	cout << "10진수로출력: " << number << endl;
	cout << "16진수로출력: " << hex << number << endl;
	cout << " 8진수로출력: " << oct << number << endl;
	double dnumber = 7.12345;
	cout << setprecision(3);
	cout << dnumber << endl; // 유효숫자 3자리 출력
	cout << fixed;
	cout << dnumber << endl; // fixed 모드 - 소숫점 이하3자리 출력
	cout << scientific;
	cout << dnumber << endl; // scientific 모드 - 소수점이하 3자리 출력
	cout << "|" << setw(10) << number << "|" << setw(15) << dnumber << "|" << endl;
	cout << left;
	cout << "|" << setw(10) << number << "|" << setw(15) << dnumber << "|" << endl;
	cout << right;
	cout << "|" << setw(10) << number << "|" << setw(15) << dnumber << "|" << endl;

	return 0;
}