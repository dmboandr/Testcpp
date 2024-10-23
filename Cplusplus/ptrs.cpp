#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	// Ссылки и указатели
	// Ссылку обязательно нужно чем-то инициализировать
	//int& a; // инициализировать - значит задать значение
	int humanAverageLifespanPerCountry = 73;
	int& x = humanAverageLifespanPerCountry;

	int& c = x;

	c = 999;

	cout << "Первая переменная: " << humanAverageLifespanPerCountry << endl;
	cout << "Вторая переменная: " << x << endl;
	

	// Указатели (поинтеры) Pointers
	string first_name = "Dmitri";
	string* ptr_first_name = &first_name;

	cout << endl << "ПРИМЕРЫ ПОИНТЕРОВ" << endl;

	cout << "Сама переменная: " << first_name << endl;
	cout << "Поинтер: " << *ptr_first_name << endl;

	return 0;
	// dynamic load library
}