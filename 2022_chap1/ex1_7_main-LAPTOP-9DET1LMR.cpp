#include<iostream>
using namespace std;
#include "ioacademy.h"
#include "lectopia.h"
using namespace lectopia;
//using namespace ioacademy; //�� ��ü�� ������ �ƴ����� using namespace ����� ����ȭ��Ű�Ƿ� ����ϸ� �ȵ�!!

int main()
{
	cout<< "main()���� ����ϴ� lectopia ���ӽ����̽��� number = " 
		<< lectopia::number <<endl;
	lectopia::print();
	cout<< "main()���� ����ϴ� ioacademy ���ӽ����̽��� number = " 
		<<ioacademy::number <<endl;
	ioacademy::print();
	return 0;
}