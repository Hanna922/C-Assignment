#include <iostream>
using namespace std;
class Test {
private:
	int t;
public:
	Test(int a= 0){ // inline 함수로 만들어짐
		cout << "Test 생성자 수행중..." << endl;
		t = a;
	}
	void show() {
		cout << "t = " << t << endl;
	}
};

int main() {
	//Test ary[10] = { Test(10), Test(20), Test(30) };
	//// 객체 배열의 각 객체를 초기화 할 때는 생성자 함수를 명시적으로 호출하는 표현 사용
	//for (auto n : ary) {
	//	n.show();
	//}

	Test* pAry[10];
	int count = 0; //실제 객체가 몇 개가 생성 되었는지 카운트 하는 변수
	int i = 0;
	int arySize = sizeof(pAry) / sizeof(pAry[0]);
	while (i < arySize) {
		int num;
		cout << "정수입력 : ";
		cin >> num;
		if (num < 0) break; //음수 입력 시 반복 중단
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