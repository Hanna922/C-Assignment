#include<iostream>
using namespace std;
class Robot {
public:
	Robot() {
		cout << "Robot constructor" << endl;
	}
	~Robot() {
		cout << "Robot destructor" << endl;
	}
};
int main()
{
	Robot* rp;
	rp = new Robot[3];
	delete[] rp; // 문제 발생!! (R.T.E. or 메모리 해제가 덜 되는 메모리 누수(Leak)현상
		return 0;
}
