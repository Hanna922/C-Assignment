#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	char str[20];
	int one, two, three;

	cout << "이름 : ";
	cin.getline(str, sizeof(str));
	cout << "세 과목의 점수 : ";
	cin >> one;
	cin >> two;
	cin >> three;
	cout << endl << endl;
	cout << setw(40) << "=====< 성적표 >=====" << endl;
	cout << "============================================================" << endl;
	cout << setw(10) << "이름" << setw(10) << "국어" << setw(10) << "영어";
	cout << setw(10) << "수학" << setw(10) << "총점" << setw(10) << "평균" << endl;
	cout << "============================================================" << endl;
	cout << setw(10) << str << setw(10) << one << setw(10) << two;
	cout << setw(10) << three << setw(10) << one + two + three << setw(10);
	cout << fixed << setprecision(2) << (one + two + three) / 3.0 << endl;
	
	return 0;
}