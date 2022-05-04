#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

void computer(int* computer_number);
int check(int* computer_number, int* user_number);
int output(int s, int b);

int main() {
	int computer_number[4] = { 0, };
	int user_number[4] = { 0, };
	int n = 1;
	int result;
	
	computer(computer_number);
	
	printf("예를 들어 컴퓨터가 발생한 난수가 (");
	for (int i = 0; i < 4; i++) {
		printf("%3d", computer_number[i]);
	}
	printf("  ) 일 경우\n\n");
	
	while (true) {
		printf("# %d차 : ", n);
		n++;
		for (int i = 0; i < 4; i++) {
			scanf("%d", &user_number[i]);
		}
		result = check(computer_number, user_number);
		if (result == 1) {
			break;
		}
	}

	return 0;
}

void computer(int* computer_number) {
	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		computer_number[i] = rand() % 9 + 1;
		for (int j = 0; j < i; j++) {
			if (computer_number[i] == computer_number[j]) {
				i--;
			}
		}
	}
}

int check(int* computer_number, int* user_number) {
	int s = 0, b = 0, result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((i == j) && (user_number[i] == computer_number[j])) {
				s++;
			}
			else if (user_number[i] == computer_number[j]) {
				b++;
			}
			else;
		}
	}
	result = output(s, b);
	return result;
}

int output(int s, int b) {
	if (s == 0 && b == 0) {
		printf("No!\n");
		return 0;
	}
	else if (s == 4) {
		printf("OK!!!\n");
		return 1;
	}
	else {
		printf("%dS %dB\n", s, b);
		return 0;
	}
}