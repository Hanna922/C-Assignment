#include <iostream>
using namespace std;

int divide(int num1, int num2, int* q, int* r);

int main() {
	int num1, num2;
	int q, r;

	cout << "�� ���� ���� �Է� : ";
	cin >> num1 >> num2;
	cout << endl;
	try {
		if (num2 == 0) {
			throw num2;
		}
		else {
			divide(num1, num2, &q, &r);
			cout << num1 << " / " << num2 << " = " << q << ", ";
			cout << num1 << " % " << num2 << " = " << r << endl;
		}
	}
	catch (int expn) {
		cout << "������ ��(�� ��° ����)�� " << expn << "�� �� �� �����ϴ�." << endl;
	}
	return 0;
}

int divide(int num1, int num2, int* q, int* r) {
	*q = num1 / num2;
	*r = num1 % num2;
	return 0;
}