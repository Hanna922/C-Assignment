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
	
}      // e�� ��ŭ ���� (�������ڰ� ������ ��� �������� ����)

char* Robot::getName() {
	return name;
}       // name����� �� ����

void Robot::setName(const char* name) {
	strcpy(this->name, name);
}   // name����� ���� ���޵� ���ڿ��� �� �ʱ�ȭ (��������)

int Robot::getEnergy() {
	return energy;
}         // energy����� �� ����  

void Robot::setEnergy(int energy) {
	this->energy = energy;
}

// back, turn, jump ��� ����
// setter, getter ��� ����

