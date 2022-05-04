#include <iostream>
#include <vector>
using namespace std;

int solve(int N, int K, vector<int> arr) {
	//int left = K, right = 0;
	int count = 1, time = K;

	while (count < K) { // N=6, K=2
		for (int j = 0; j < N - 1; ++j) {
			if (abs((arr[j + 1] - arr[j])) > time) {
				count++;
			}
		}
	}
	
	cout << time;
	return 0;
}

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> arr(N); //arr(6)
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	solve(N, K, arr);
	return 0;
}