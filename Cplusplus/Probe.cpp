#include <iostream>


using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	//// допустимые дейсвтия в типах данных
	//// числовые целочисленные
	//// int long unsigned int unsinged long short
	//unsigned int number = 1;
	//int number1 = 1000000;
	//
	//// bool string char int double
	//bool isHuman = true; // проименовано в camelCase
	//bool is_human = true;

	//string name;
	//int x = 1;
	//x = 1;

	//// символом разделителем в С++ являются:
	//// переход на новую строку (enter) \n
	//// табуляция \t TAB
	//// пробел
	//cin >> x >> name;
	//cout << x << " " << name << endl;

	//// float 
	//double pi = 3.2362362314f;

	/*
	Написать программу, решающую квадртное уравнение
	*/

	//// определяем коэфициенты
	//double a, b, c;
	//cout << "Введите коэффициенты a, b, c через пробел: ";
	//cin >> a >> b >> c;
	//
	//// рассчитываем дискриминант
	//double d = pow(b, 2) - 4 * a * c;
	//cout << "Дискриминант: " << d << endl;
	//
	//// переменные для результата, т.е. корни
	//double x1, x2;

	//// если дискриминант отрицательный
	//if (d < 0) {
	//	cout << "Решений нет" << endl;
	//}
	//// если  дискриминант равен 0
	//else if (d == 0) {
	//	x1 = -b / 2 * a;
	//	cout << "Один корень: x=" << x1 << endl;
	//}
	//// Два корня:
	//// x1 = ...
	//// x2 = ...
	//else {
	//	x1 = (-b + sqrt(d)) / (2 * a);
	//	x2 = (-b - sqrt(d)) / (2 * a);
	//	cout << "Два корня: " << endl << "x1 = " << x1;
	//	cout << endl << "x2 = " << x2 << endl;
	//}

	// У циклов есть управляющие конструкции.
	// Всего их 2: break и continue.
	// Эти управляющие конструкции могут останавливать цикл.

	/*for (int i = 0; i < 10; i++) {
		if (i == 5) {
			continue;
		}
		cout << i << endl;
	}*/

	/*
	Студенты родители выделили определенное количество денег.
	Ему нужно платить за квартиру, пока он учится.
	И ему нужно питаться.
	У студента есть стипендия.
	Нужно написать программу, которая определит,
	хватит ли студенту денег на учебный год,
	при определенных затратах.

	money - его количество денег
	grants - стипендия
	rent - квартира в месяц
	expenses - затраты в месяц

	*/

	cout << "Введите количество денег студента: ";
	int money;
	cin >> money;

	double grants = 3000; // стипендия
	double rent = 10000; // аренда квартиры
	double expenses = 7000; // 
	double months = 0;

	for (int i = 0; i < 10; i++) {

		if (money < 0) {
			break;
		}
	}

	while (money >= 0) {
		months++; // прибавь 1
		money += grants;
		money -= rent + expenses;
		cout << "Денег на " << months << " месяц: ";
		cout << money << endl;
		if (months == 10) {
			break;
		}
	}

	if (months >= 10) {
		cout << "Студенту хватит этих денег";
	}
	else {
		cout << "Студенту НЕ хватит этих денег";
	}

	
	return 0;
}