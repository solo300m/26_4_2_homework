#pragma once
#include "Client.h"
#include <locale.h>

class BookPhon {
private:
	vector<Client> bookClient;
public:
	void addClient() {
		cout << "Введите Имя -> ";
		string name;
		cin >> name;
		cout << "Введите фамилию -> ";
		string lastName;
		cin >> lastName;
		long id;
		bool find = false;
		for (Client c : bookClient) {
			if (name == c.getName() && lastName == c.getLastName()) {
				cout << "Контакт с именем " << name << " и фамилией " << lastName << " уже зарегистрирован." << endl;
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
			cout << "Изменения не внесены в телефонную книгу." << endl;
		}
	}
	void addPhon() {
		cout << "Введите Имя -> ";
		string name;
		cin >> name;
		cout << "Введите фамилию -> ";
		string lastName;
		cin >> lastName;
		bool find = false;
		int id = 0;
		for (Client c : bookClient) {			
			if (name == c.getName() && lastName == c.getLastName()) {
				cout << "Контакт с именем " << name << " и фамилией " << lastName << " зарегистрирован." << endl;
				find = true;				
				break;
			}
			id++;
		}
		if (find == false) {
			cout << "Контакт с именем " << name << " и фамилией " << lastName << " не зарегистрирован. Введите контакт." << endl;
		}
		else {
			bookClient.at(id).addNumber();
		}
	}
	void call() {
		int type;
		while (true) {
			cout << "Введите: 1 - Поиск по имени, 2 - Поиск по номеру, 0 - Отказаться от звонка. -> ";
			cin >> type;
			if (type == 1) {
				cout << "Введите Имя -> ";
				string name;
				cin >> name;
				cout << "Введите фамилию -> ";
				string lastName;
				cin >> lastName;
				bool find = false;
				int id = 0;
				for (Client c : bookClient) {					
					if (name == c.getName() && lastName == c.getLastName()) {
						cout << "Контакт с именем " << name << " и фамилией " << lastName << " зарегистрирован." << endl;
						find = true;
						break;
					}
					id++;
				}
				if (find == false) {
					cout << "Контакт с именем " << name << " и фамилией " << lastName << " не зарегистрирован. Введите контакт." << endl;
				}
				else {
					cout << "Звонок контакту " << bookClient.at(id).getName() <<" "<< bookClient.at(id).getLastName() <<" на номер " << bookClient.at(id).getNumberList().at(0).toString()<<endl;
				}
			}
			else if (type == 2) {
				int code;
				cout << "введите код региона ->";
				cin >> code;
				long number;
				cout << "Введите номер телефона (10 цифр без символов) ->";
				cin >> number;
				for (Client c : bookClient) {
					bool check = false;
					for (PhonNumber ph : c.getNumberList()) {
						if (ph.getStateNumber() == code && ph.getPhNumb() == number) {
							cout << "Звонок контакту " << c.getName() << " " << c.getLastName() << " на номер " << c.getNumberList().at(0).toString() << endl;
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
				cout << "Набран не верный вариант. Повторите ввод." << endl;
			}
		}		
	}
	void sms() {
		setlocale(LC_ALL, "Russian");
		int type;
		while (true) {
			cout << "Введите: 1 - Поиск по имени, 2 - Поиск по номеру, 0 - Отказаться от SMS. -> ";
			cin >> type;
			if (type == 1) {
				cout << "Введите Имя -> ";
				string name;
				cin >> name;
				cout << "Введите фамилию -> ";
				string lastName;
				cin >> lastName;
				bool find = false;
				int id = 0;
				for (Client c : bookClient) {					
					if (name == c.getName() && lastName == c.getLastName()) {
						cout << "Контакт с именем " << name << " и фамилией " << lastName << " зарегистрирован." << endl;
						find = true;
						break;
					}
					id++;
				}
				if (find == false) {
					cout << "Контакт с именем " << name << " и фамилией " << lastName << " не зарегистрирован. Введите контакт." << endl;
				}
				else {
					string sms = "";
					cout << "Введите текст sms на английском языке: " << endl;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');						
					getline(cin, sms);
					cout << "Контакту " << bookClient.at(id).getName() << " " << bookClient.at(id).getLastName() << " на номер " << bookClient.at(id).getNumberList().at(0).toString() << endl;
					cout << "Отправлена sms: " << sms << endl;
				}
			}
			else if (type == 2) {
				int code;
				cout << "введите код региона ->";
				cin >> code;
				long number;
				cout << "Введите номер телефона (10 цифр без символов) ->";
				cin >> number;
				for (Client c : bookClient) {
					bool check = false;
					for (PhonNumber ph : c.getNumberList()) {
						if (ph.getStateNumber() == code && ph.getPhNumb() == number) {
							string sms;
							cout << "Введите текст sms: " << endl;
							getline(cin, sms);
							cout << "Контакту " << c.getName() << " " << c.getLastName() << " на номер " << c.getNumberList().at(0).toString() << endl;
							cout << "Отправлена sms: " << sms << endl;
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
				cout << "Набран не верный вариант. Повторите ввод." << endl;
			}
		}
	}
};