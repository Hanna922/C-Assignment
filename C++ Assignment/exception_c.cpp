#include <stdio.h>
#pragma warning(disable:4996)

int inputInt(const char* msg);
void myflush();

int main() {
	int age;
	age = inputInt("���� �Է� : ");
	return 0;
}

int inputInt(const char* msg) {
	int n;
	while (1) {
		printf("%s", msg);
		scanf("%d", &n);
		if (getchar() == '\n') {
			break;
			// �ܿ� data�� ���๮�ڸ� �ִٸ� ���� �Է� �� ���̹Ƿ� break
		}
		else {
			myflush();
			// ���� �Է��� �ƴ� ��� �ܿ� data�� ��� ����� �ٽ� ����
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