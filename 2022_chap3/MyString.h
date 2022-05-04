
class MyString {
private:
	char* str; // 문자열을 연결할 포인터멤버
	int len; // 문자열의 길이를 저장
public:
	MyString(); // 디폴트 생성자
	MyString(const char* cp); // 오버로디드 생성자
	MyString(const MyString& br); // 복사 생성자
	~MyString(); // 소멸자
	MyString& operator=(const MyString& br); // 대입연산자 멤버함수
	MyString operator+(const MyString& br); // 덧셈 연산자
	bool operator>(const MyString& br); // 관계연산자 멤버함수(길이 비교)
	void operator<<(ostream& os); // 출력연산자 멤버함수
	void operator>>(istream& is); // 입력연산자 멤버함수
};
ostream& operator<<(ostream& os, MyString& br); // 출력 일반함수
