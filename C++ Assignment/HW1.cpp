#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	char str[20];
	int one, two, three;

	cout << "�̸� : ";
	cin.getline(str, sizeof(str));
	cout << "�� ������ ���� : ";
	cin >> one;
	cin >> two;
	cin >> three;
	cout << endl << endl;
	cout << setw(40) << "=====< ����ǥ >=====" << endl;
	cout << "============================================================" << endl;
	cout << setw(10) << "�̸�" << setw(10) << "����" << setw(10) << "����";
	cout << setw(10) << "����" << setw(10) << "����" << setw(10) << "���" << endl;
	cout << "============================================================" << endl;
	cout << setw(10) << str << setw(10) << one << setw(10) << two;
	cout << setw(10) << three << setw(10) << one + two + three << setw(10);
	cout << fixed << setprecision(2) << (one + two + three) / 3.0 << endl;
	
	return 0;
}