#pragma once
#include "PhonNumber.h"
#include <vector>

class Client {
private:
	long idClient = 0;
	string name = "";
	string lastName = "";
	vector<PhonNumber> numberList;
public:
	void addNumber() {
		PhonNumber pNum;
		pNum.setStateNumber(7);
		cout << "Введите номер телефона 10 цифр. Код региона +" << pNum.getStateNumber() << " ";
		long long num;
		cin >> num;
		pNum.setPhNumb(num);
		pNum.setIdClient(idClient);
		numberList.push_back(pNum);
	}
	vector<PhonNumber> getNumberList() {
		return numberList;
	}
	long getIdClient() {
		return idClient;
	}
	string getName() {
		return name;
	}
	string getLastName() {
		return lastName;
	}
	void setIdClient(long id) {
		idClient = id;
	}
	void setName(string name) {
		this->name = name;
	}
	void setLastName(string lName) {
		lastName = lName;
	}
	string to_String() {
		return to_string(idClient) + " " + name + " " + lastName;
	}
};