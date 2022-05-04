#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int n, i, j, k;
	int ary[10][10] = {};
	int num = 1, x = 0, y = 0, s = 1;
	printf("# 행/열의 수 입력 : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		ary[y][x] = num++;
		x += s;
	}
	x -= 1;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			y += s;
			ary[y][x] = num++;
		}
		s *= -1;
		for (k = 0; k < i; k++) {
			x += s;
			ary[y][x] = num++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", ary[i][j]);
		}
		printf("\n\n");
	}

	return 0;
}