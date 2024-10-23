#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	cout << "Введите 1 для действия 1" << endl;
	cout << "Введите 2 для действия 2" << endl;
	cout << "Введите 3 для действия 3" << endl;
	int n;
	cin >> n;

	switch (n) // проверяется n
	{
		case 1: // if (n==1)
		{
			cout << "Выполняется действие 1..." << endl;
			break;
		}
		case 2: // if (n==2)
		{
			cout << "Выполняется действие 2..." << endl;
			break;
		}
		case 3:
		{
			cout << "Выполняется действие 3..." << endl;
			break;
		}
		default: 
		{
			cout << "Неизвестная команда" << endl;
			break;
		}
	}
	
	/*if (n == 1) {
		cout << "Выполняется действие 1..." << endl;
	}
	else if (n == 2) {
		cout << "Выполняется действие 2..." << endl;
	}
	else if (n == 3) {
		cout << "Выполняется действие 3..." << endl;
	}
	else {
		cout << "Неизвестная команда" << endl;
	}*/

	return 0;
}