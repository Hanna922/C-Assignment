#include <iostream>
using namespace std;

int divide(int num1, int num2, int* q, int* r);

int main() {
	int num1, num2;
	int q, r;

	cout << "두 개의 정수 입력 : ";
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
		cout << "나누는 수(두 번째 정수)는 " << expn << "이 될 수 없습니다." << endl;
	}
	return 0;
}

int divide(int num1, int num2, int* q, int* r) {
	*q = num1 / num2;
	*r = num1 % num2;
	return 0;
}