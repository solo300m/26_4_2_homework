#pragma once
#include <iostream>
#include <string>
using namespace std;

class PhonNumber {
private:
	long idClient = 0;
	int stateNumber = 7;
	long long phNumb = 0;
public:
	void setIdClient(long id) {
		idClient = id;
	}
	void setStateNumber(int stNum) {
		stateNumber = stNum;
	}
	void setPhNumb(long long num) {
		phNumb = num;
	}
	long getIdClient() {
		return idClient;
	}
	int getStateNumber() {
		return stateNumber;
	}
	long getPhNumb() {
		return phNumb;
	}
	string toString() {
		int t1, t2, t3, t4;
		long long tmp;
		t1 = phNumb / 10000000;
		tmp = phNumb % 10000000;
		t2 = tmp / 10000;
		tmp = tmp % 10000;
		t3 = tmp / 100;
		tmp = tmp % 100;
		t4 = tmp;
		return "+" + to_string(stateNumber) + " ( " + to_string(t1) + " ) " + to_string(t2) + " - " + to_string(t3) + " - " + to_string(t4);
	}
};