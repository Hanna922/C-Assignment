#include <iostream>
using namespace std;
#include "ex1_17_myhdr.h"

int main()
{
	int ary[ArySize]={10,20,30,40,50};
	int sum;
	sum=ary_sum(ary);
	cout << "배열 요소의 합 : " << sum << endl;
	cout << "main()의 ArySize의 주소 : " << &ArySize << endl;
	return 0;
}
