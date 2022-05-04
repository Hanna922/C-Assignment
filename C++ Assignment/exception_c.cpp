#include <stdio.h>
#pragma warning(disable:4996)

int inputInt(const char* msg);
void myflush();

int main() {
	int age;
	age = inputInt("나이 입력 : ");
	return 0;
}

int inputInt(const char* msg) {
	int n;
	while (1) {
		printf("%s", msg);
		scanf("%d", &n);
		if (getchar() == '\n') {
			break;
			// 잔여 data에 개행문자만 있다면 정상 입력 된 것이므로 break
		}
		else {
			myflush();
			// 정상 입력이 아닐 경우 잔여 data를 모두 지우고 다시 실행
		}
	}
	return n;
}

void myflush() {
	while (getchar() != '\n') {
		;
	}
	return;
}