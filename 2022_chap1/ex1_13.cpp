#include <iostream>
using namespace std;
void prn(const char *);
void prn(const char *, int);
void prn(char, int);
void prn(char*);

int main()
{
	char str[10]="Star";

	prn(str);  // prn(char *) 호출
	prn("Moon");  // prn(char *) 호출
	prn("Gogumi", 3);  // prn(char *, int) 호출
	prn('#', 7);  // prn(char, int) 호출
	
	return 0;
}

void prn(const char *p)
{
	cout << p << endl;
}

void prn(const char *p, int rc)
{
	int i;
	for(i=0; i<rc; i++){
		cout << p << endl;
	}
}

void prn(char ch, int rc)
{
	int i;
	for(i=0; i<rc; i++){
		cout << ch;
	}
	cout << endl;
}

void prn(char* p)
{
	cout << "4번 prn() : " << p << "\n";
}