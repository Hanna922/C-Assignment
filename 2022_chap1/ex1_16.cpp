#include <iostream>
using namespace std;

#define SQUARE(x) x*x  // (x)*(x) 로 수정하여 수행해보자
inline int square(int x) { return x*x; } // 인라인 함수의 정의

int main()
{
	int ires;
	int n = 5;
	ires=square(3+4);
	cout << "inline 함수를 이용한 3+4의 거듭제곱 : " << ires << endl;
	
	n = 5;
	ires=SQUARE(3+4);
	cout << "매크로 함수를 이용한 3+4의 거듭제곱 : " << ires << endl;
	return 0;
}
