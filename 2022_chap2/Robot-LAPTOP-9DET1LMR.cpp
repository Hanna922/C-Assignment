#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
#include "Robot.h"

void Robot::errPrn() {
	cout << "we";
}

Robot::Robot() {
	strcpy(this->name, "");
	this->energy = 0;
}

Robot::Robot(const char* name, int energy) {
	strcpy(this->name, name);
	this->energy = energy;
}

Robot::Robot(const Robot& r) {
	strcpy(this->name, r.name);
	this->energy = r.energy;
}

Robot::~Robot() {
	delete[]name;
}

void Robot::go() {
	
}

void Robot::back() {
	
}

void Robot::turn() {
	
}

void Robot::jump() {
	
}

void Robot::charge(int e) {
	
}      // e값 만큼 충전 (전달인자가 음수일 경우 에너지값 유지)

char* Robot::getName() {
	return name;
}       // name멤버의 값 리턴

void Robot::setName(const char* name) {
	strcpy(this->name, name);
}   // name멤버의 값을 전달된 문자열로 재 초기화 (깊은복사)

int Robot::getEnergy() {
	return energy;
}         // energy멤버의 값 리턴  

void Robot::setEnergy(int energy) {
	this->energy = energy;
}

// back, turn, jump 모두 구현
// setter, getter 모두 구현

