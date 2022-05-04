#include <stdio.h>
#pragma warning(disable:4996)
#define ABS(x) ((x) < 0 ? (-(x)) : (x))

int main() {
	int minus[100] = { 0, };
	int first, second, diff, n, jolly = 1;

	printf("숫자의 개수 : ");
	scanf("%d", &n);

	printf("검사 수열 입력 : ");
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