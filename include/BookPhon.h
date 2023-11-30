#pragma once
#include "Client.h"
#include <locale.h>

class BookPhon {
private:
	vector<Client> bookClient;
public:
	void addClient() {
		cout << "������� ��� -> ";
		string name;
		cin >> name;
		cout << "������� ������� -> ";
		string lastName;
		cin >> lastName;
		long id;
		bool find = false;
		for (Client c : bookClient) {
			if (name == c.getName() && lastName == c.getLastName()) {
				cout << "������� � ������ " << name << " � �������� " << lastName << " ��� ���������������." << endl;
				find = true;
				break;
			}
		}
		if (!find) {
			if (!bookClient.empty()) {				
				id = bookClient[bookClient.size()-1].getIdClient() + 1;
			}
			else {
				id = 1;				
			}
			Client cl;
			cl.setIdClient(id);
			cl.setName(name);
			cl.setLastName(lastName);
			bookClient.push_back(cl);
		}
		else {
			cout << "��������� �� ������� � ���������� �����." << endl;
		}
	}
	void addPhon() {
		cout << "������� ��� -> ";
		string name;
		cin >> name;
		cout << "������� ������� -> ";
		string lastName;
		cin >> lastName;
		bool find = false;
		int id = 0;
		for (Client c : bookClient) {			
			if (name == c.getName() && lastName == c.getLastName()) {
				cout << "������� � ������ " << name << " � �������� " << lastName << " ���������������." << endl;
				find = true;				
				break;
			}
			id++;
		}
		if (find == false) {
			cout << "������� � ������ " << name << " � �������� " << lastName << " �� ���������������. ������� �������." << endl;
		}
		else {
			bookClient.at(id).addNumber();
		}
	}
	void call() {
		int type;
		while (true) {
			cout << "�������: 1 - ����� �� �����, 2 - ����� �� ������, 0 - ���������� �� ������. -> ";
			cin >> type;
			if (type == 1) {
				cout << "������� ��� -> ";
				string name;
				cin >> name;
				cout << "������� ������� -> ";
				string lastName;
				cin >> lastName;
				bool find = false;
				int id = 0;
				for (Client c : bookClient) {					
					if (name == c.getName() && lastName == c.getLastName()) {
						cout << "������� � ������ " << name << " � �������� " << lastName << " ���������������." << endl;
						find = true;
						break;
					}
					id++;
				}
				if (find == false) {
					cout << "������� � ������ " << name << " � �������� " << lastName << " �� ���������������. ������� �������." << endl;
				}
				else {
					cout << "������ �������� " << bookClient.at(id).getName() <<" "<< bookClient.at(id).getLastName() <<" �� ����� " << bookClient.at(id).getNumberList().at(0).toString()<<endl;
				}
			}
			else if (type == 2) {
				int code;
				cout << "������� ��� ������� ->";
				cin >> code;
				long number;
				cout << "������� ����� �������� (10 ���� ��� ��������) ->";
				cin >> number;
				for (Client c : bookClient) {
					bool check = false;
					for (PhonNumber ph : c.getNumberList()) {
						if (ph.getStateNumber() == code && ph.getPhNumb() == number) {
							cout << "������ �������� " << c.getName() << " " << c.getLastName() << " �� ����� " << c.getNumberList().at(0).toString() << endl;
							check = true;
							break;
						}
					}
					if (check == true)
						break;
				}
			}
			else if (type == 0) {
				break;
			}
			else {
				cout << "������ �� ������ �������. ��������� ����." << endl;
			}
		}		
	}
	void sms() {
		setlocale(LC_ALL, "Russian");
		int type;
		while (true) {
			cout << "�������: 1 - ����� �� �����, 2 - ����� �� ������, 0 - ���������� �� SMS. -> ";
			cin >> type;
			if (type == 1) {
				cout << "������� ��� -> ";
				string name;
				cin >> name;
				cout << "������� ������� -> ";
				string lastName;
				cin >> lastName;
				bool find = false;
				int id = 0;
				for (Client c : bookClient) {					
					if (name == c.getName() && lastName == c.getLastName()) {
						cout << "������� � ������ " << name << " � �������� " << lastName << " ���������������." << endl;
						find = true;
						break;
					}
					id++;
				}
				if (find == false) {
					cout << "������� � ������ " << name << " � �������� " << lastName << " �� ���������������. ������� �������." << endl;
				}
				else {
					string sms = "";
					cout << "������� ����� sms �� ���������� �����: " << endl;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');						
					getline(cin, sms);
					cout << "�������� " << bookClient.at(id).getName() << " " << bookClient.at(id).getLastName() << " �� ����� " << bookClient.at(id).getNumberList().at(0).toString() << endl;
					cout << "���������� sms: " << sms << endl;
				}
			}
			else if (type == 2) {
				int code;
				cout << "������� ��� ������� ->";
				cin >> code;
				long number;
				cout << "������� ����� �������� (10 ���� ��� ��������) ->";
				cin >> number;
				for (Client c : bookClient) {
					bool check = false;
					for (PhonNumber ph : c.getNumberList()) {
						if (ph.getStateNumber() == code && ph.getPhNumb() == number) {
							string sms;
							cout << "������� ����� sms: " << endl;
							getline(cin, sms);
							cout << "�������� " << c.getName() << " " << c.getLastName() << " �� ����� " << c.getNumberList().at(0).toString() << endl;
							cout << "���������� sms: " << sms << endl;
							check = true;
							break;
						}
					}
					if (check == true)
						break;
				}
			}
			else if (type == 0) {
				break;
			}
			else {
				cout << "������ �� ������ �������. ��������� ����." << endl;
			}
		}
	}
};