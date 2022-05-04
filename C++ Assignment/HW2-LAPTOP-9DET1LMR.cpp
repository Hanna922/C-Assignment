#include <iostream>
using namespace std;
double max(double, double);
const char* max(char*, char*);

int main() {
	double da, db;
	char str[20];
	char chr[20];
	double dmax;
	const char* res;

	cout << "두 실수 입력 : ";
	cin >> da >> db;
	dmax = max(da, db);
	cout << "큰 값 : " << dmax << endl;
	
	cout << "두 문자열 입력 : ";
	cin >> str >> chr;
	res = max(str, chr);
	cout << "긴 문자열 : " << res << endl;
	
	return 0;
}

double max(double da, double db) {
	if (da > db) {
		return da;
	}
	else {
		return db;
	}
	
}

const char* max(char* str, char* chr) {
	if (strlen(str) > strlen(chr)) {
		return str;
	}
	else {
		cout << str << chr;
		return chr;
	}
}