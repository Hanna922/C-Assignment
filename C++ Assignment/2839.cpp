#include <iostream>
using namespace std;

int main() {
	int n, count = 0;
	cin >> n;
	while (n > 0) {
		if (n % 5 == 0) {
			n -= 5;
			count++;
		}
		else if (n % 3 == 0) {
			n -= 3;
			count++;
		}
		else if (n > 5) {
			n -= 5;
			count++;
		}
		else {
			count = -1;
			break;
		}
	}
	cout << count;
	return 0;
}