#include <stdio.h>
#pragma warning(disable:4996)
#define ABS(x) ((x) < 0 ? (-(x)) : (x))

int main() {
	int minus[100] = { 0, };
	int first, second, diff, n, jolly = 1;

	printf("������ ���� : ");
	scanf("%d", &n);

	printf("�˻� ���� �Է� : ");
	scanf("%d", &first);
	
	for (int i = 1; i < n; i++) {
		scanf("%d", &second);
		diff = ABS(second - first);
		if (diff <= 0 || diff >= n || minus[diff]) {
			jolly = 0;
			break;
		}
		minus[diff] = 1;
		first = second;
	}
	
	printf("%s", jolly ? "(Jolly jumper)" : "(Not jolly jumper)");

	return 0;
}