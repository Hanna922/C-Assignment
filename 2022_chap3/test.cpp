#include <iostream>
using namespace std;
class Test {
private:
	int t;
public:
	Test(int a= 0){ // inline �Լ��� �������
		cout << "Test ������ ������..." << endl;
		t = a;
	}
	void show() {
		cout << "t = " << t << endl;
	}
};

int main() {
	//Test ary[10] = { Test(10), Test(20), Test(30) };
	//// ��ü �迭�� �� ��ü�� �ʱ�ȭ �� ���� ������ �Լ��� ��������� ȣ���ϴ� ǥ�� ���
	//for (auto n : ary) {
	//	n.show();
	//}

	Test* pAry[10];
	int count = 0; //���� ��ü�� �� ���� ���� �Ǿ����� ī��Ʈ �ϴ� ����
	int i = 0;
	int arySize = sizeof(pAry) / sizeof(pAry[0]);
	while (i < arySize) {
		int num;
		cout << "�����Է� : ";
		cin >> num;
		if (num < 0) break; //���� �Է� �� �ݺ� �ߴ�
		pAry[count++] = new Test(num);
		i++;
	}
	for (i = 0; i < count; i++) {
		pAry[i]->show();
	}
	for (i = 0; i < count; i++) {
		delete pAry[i];
		// delete[] pAry[i]; (X)
	}

	return 0;
}