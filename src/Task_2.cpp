// Task_2.cpp: определяет точку входа для приложения.
//

#include "Task_2.h"
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	BookPhon pBook;
	while (true) {
		cout << "Ввести команду. 1-Добавить контакт, 2-Добавить номер телефона, 3-Позвонить, 4-Отправить СМС, 0-Выход из программы" << endl;
		int take;
		cin >> take;
		if (take == 1) {
			pBook.addClient();
		}
		else if (take == 2) {
			pBook.addPhon();
		}
		else if (take == 3) {
			pBook.call();
		}
		else if (take == 4) {
			pBook.sms();
		}
		else if (take == 0) {
			break;
		}
		else {
			cout << "Не верный ввод. Повторите." << endl;
		}
	}	
	return 0;
}
