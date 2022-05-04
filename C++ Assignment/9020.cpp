#include <iostream>
using namespace std;

int main() {
	int T, n, rt, rt2;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> n;
		
		//짝수 처리 해야함
		for (int i = n/2; i <= n; i++) {
			rt = sqrt(i);
			if (rt == 1 && i != 1) {
				continue;
			}
			else {
				for (int j = 2; j <= rt; j++) {
					if (!(i % j))
						break;
					if (j == rt) {
						//소수임
						rt2 = sqrt(n - i);
						if (rt2 == 1) {
							cout << i << " " << n - i << endl;
						}
						else {
							for (int j = rt2; j >= 2; j--) {
								if (!((n - i) % j))
									break;
								if (j == rt2) {
									if (i < (n - i))
										cout << i << " " << n - i << endl;
									else
										cout << n - i << " " << i << endl;
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}