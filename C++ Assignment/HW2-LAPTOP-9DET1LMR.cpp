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

	cout << "�� �Ǽ� �Է� : ";
	cin >> da >> db;
	dmax = max(da, db);
	cout << "ū �� : " << dmax << endl;
	
	cout << "�� ���ڿ� �Է� : ";
	cin >> str >> chr;
	res = max(str, chr);
	cout << "�� ���ڿ� : " << res << endl;
	
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