#include<iostream>
using namespace std;
#include "Robot.h"

void input(Robot* rp, int cnt);
void work(Robot* rp, int cnt);
void prn(Robot* rp, int cnt);

int main() {
	Robot* rp;
	int cnt;
	cout << "������ �κ��� ����� �Է��Ͻÿ� : ";
	cin >> cnt;
	rp = new Robot[cnt]; // ���� �߻� ���� �ذ� ����

	input(rp, cnt);
	work(rp, cnt);
	prn(rp, cnt);
	delete[] rp;

	return 0;
}

void input(Robot* rp, int cnt) {
	char* ob1;
	cout << "3";
	for (int i = 1; i <= cnt; i++) {
		cout << "4";
		cout << i << "�� �κ����� �Է��Ͻÿ� : ";
		ob1 = rp[i].getName();
		cout << ob1 << "�� ������ ���� �Է��Ͻÿ� : ";
		cin >> cnt;
		cout << endl;
	}
}

void work(Robot* rp, int cnt) {
	
	
}

void prn(Robot* rp, int cnt) {

	
}