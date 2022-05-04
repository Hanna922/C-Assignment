#include <iostream>
using namespace std;
void str_prn(char* p, char c = '\0');
int main()
{
	char str[80];
	cout << "문장 입력 : ";
	cin.getline(str, sizeof(str));
	char ch;
	cout << "문자 입력 : ";
	cin >> ch;
	str_prn(str);
	str_prn(str, ch);
	return 0;
}
void str_prn(char* p, char c)
{
	while (*p != c && *p != '\0') {
		cout << *p++;
	}
	cout << endl;
}