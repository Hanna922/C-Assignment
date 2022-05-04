// iMoneyBox의선언, 멤버함수의정의 (iMoneyBox.cpp)
#include <iostream>
using namespace std;
#include "iMoneyBox.h"

iMoneyBox::iMoneyBox(const char *np, int m, int l) : MoneyBox(np, m)
{
	this->limit = l;
}
//-------------------------------------------------------------------------
int iMoneyBox::check()
{
	int temp;
	temp = int((double)this->getSum() / this->limit * 100);
	return temp;
}
//-------------------------------------------------------------------------
void iMoneyBox::setLimit(int limit)
{
	this->limit = limit;
}
//-------------------------------------------------------------------------
int iMoneyBox::getLimit()
{
	return this->limit;
}
