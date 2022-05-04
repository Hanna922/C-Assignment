#include <iostream>
using namespace std;
int my_strlen(char* str, char ch = '\n');

int main() {
	char str[80];
	cout << "문자열 입력 : ";
	cin.getline(str, sizeof(str));
	cout << "문자열의 길이 : " << strlen(str) << endl;
	char ch;
	int len;
	cout << "문자 입력 : ";
	cin >> ch;
	len = my_strlen(str);
	len = my_strlen(str, ch);
	cout << ch << " 이전 까지의 길이 : " << len;
	
	return 0;
}

int my_strlen(char* str, char ch) {
	int len = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ch) {
			break;
		}
		len++;
	}
	return len;
}