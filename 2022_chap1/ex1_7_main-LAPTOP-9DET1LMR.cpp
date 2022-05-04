#include<iostream>
using namespace std;
#include "ioacademy.h"
#include "lectopia.h"
using namespace lectopia;
//using namespace ioacademy; //이 자체는 에러가 아니지만 using namespace 명령을 무력화시키므로 사용하면 안됨!!

int main()
{
	cout<< "main()에서 출력하는 lectopia 네임스페이스의 number = " 
		<< lectopia::number <<endl;
	lectopia::print();
	cout<< "main()에서 출력하는 ioacademy 네임스페이스의 number = " 
		<<ioacademy::number <<endl;
	ioacademy::print();
	return 0;
}