#include <iostream>
using namespace std;
void str_prn(char* str, char ch = '\n');

int main() {
	char str[80];
	cout << "���� �Է� : ";
	cin.getline(str, sizeof(str));
	char ch;
	cout << "���� �Է� : ";
	cin >> ch;
	str_prn(str);
	str_prn(str, ch);

	return 0;
}

void str_prn(char* str, char ch) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ch) {
			break;
		}
		cout << str[i];
	}
	cout << endl;
}