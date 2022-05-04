#include<iostream>
using namespace std;
int main()
{
	int intArray[5] = { 1,3,5,7,9 };
	char charArray[10] = "apple";
	cout << intArray << endl; // 주소출력
	cout << charArray << endl; // 문자열출력
	cout << (void*)charArray << endl; // 주소출력
	return 0;
}
