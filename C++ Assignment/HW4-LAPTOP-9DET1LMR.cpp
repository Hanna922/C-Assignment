#include <iostream>
using namespace std;
int my_strlen(char* str, char ch = '\n');

int main() {
	char str[80];
	cout << "���ڿ� �Է� : ";
	cin.getline(str, sizeof(str));
	cout << "���ڿ��� ���� : " << strlen(str) << endl;
	char ch;
	int len;
	cout << "���� �Է� : ";
	cin >> ch;
	len = my_strlen(str);
	len = my_strlen(str, ch);
	cout << ch << " ���� ������ ���� : " << len;
	
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