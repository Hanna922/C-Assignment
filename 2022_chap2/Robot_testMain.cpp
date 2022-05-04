#include<iostream>
using namespace std;
#include "Robot.h"

void input(Robot* rp, int cnt);
void work(Robot* rp, int cnt);
void prn(Robot* rp, int cnt);

int main() {
	Robot* rp;
	int cnt;
	cout << "구입할 로봇의 대수를 입력하시오 : ";
	cin >> cnt;
	rp = new Robot[cnt]; // 문제 발생 아직 해결 못함

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
		cout << i << "번 로봇명을 입력하시오 : ";
		ob1 = rp[i].getName();
		cout << ob1 << "의 에너지 양을 입력하시오 : ";
		cin >> cnt;
		cout << endl;
	}
}

void work(Robot* rp, int cnt) {
	
	
}

void prn(Robot* rp, int cnt) {

	
}