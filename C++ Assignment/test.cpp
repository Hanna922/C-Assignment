#include <iostream>
using namespace  std;

class Machine {
private:
	string _name;
public:
	Machine(const string& name) : _name(name) {}
};

class Tv : public Machine {
public:
	Tv(const char* name) :Machine(name){}
};

class Phone :public Machine {
public:
	Phone() {}
};