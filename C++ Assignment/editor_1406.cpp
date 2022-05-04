#include<iostream>
#include<list>
//STL »ç¿ë
using namespace std;
int main() {
	list<char> clist;
	list<char>::iterator cursor;
	string init, cmd;
	char c;
	int n;

	cin >> init;
	cin >> n;

	for (int i = 0; i < init.size(); i++)
		clist.push_back(init[i]);

	cursor = clist.end();

	for (int i = 0; i < n; i++) {
		cin >> cmd;

		if (cmd == "L") {
			if (cursor != clist.begin())
				cursor--;
		}
		if (cmd == "D") {
			if (cursor != clist.end())
				cursor++;
		}
		if (cmd == "B") {
			if (cursor != clist.begin()) {
				cursor--;
				cursor = clist.erase(cursor);
			}

		}
		if (cmd == "P") {
			cin >> c;
			clist.insert(cursor, c);
		}
	}

	for (char c : clist)
		cout << c;

	return 0;
}