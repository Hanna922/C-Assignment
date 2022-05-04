#include <iostream>
using namespace std;

int N, M;
int arr[300];

bool isPossible(int mid) { //mid = 5
    int sum = 0, groupCnt = 1;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (sum > mid) {
            sum = arr[i]; //sum = 2
            groupCnt++; //groupCnt = 3
        }
    }
    return groupCnt <= M;
}

void printAns(int mid) {
    cout << mid << '\n';

    int i, sum = 0, marbleCnt = 0;
    for (i = 0; i < N; i++) {
        sum += arr[i];
        if (sum > mid) {
            sum = arr[i];
            M--;
            cout << marbleCnt << " ";
            marbleCnt = 0;
        }
        marbleCnt++;
        // M���� �׷��� ����� ���� �ּ����� ������ ���ܵӴϴ�.
        // (������ �׷쿡 ��� ���� 1���� ��ġ�ؾ� �ϱ� ����.)
        if (N - i == M) break;
    }

    // ������ ���� ���� ������ ���� �׷������ ����ϰ�
    // ������ ���� �׷쿡�� ���� 1���� ��ġ
    while (M--) {
        cout << marbleCnt << " ";
        marbleCnt = 1;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    int left = 0, right = 0, mid;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        // ���� �� �ִ밪���� left ����
        left = left < arr[i] ? arr[i] : left;
        right += arr[i];
    }

    while (left <= right) { //left = 9, right = 44
        mid = (left + right) / 2; //mid = 26.5
        if (isPossible(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }

    // ���� ���
    printAns(left);
}