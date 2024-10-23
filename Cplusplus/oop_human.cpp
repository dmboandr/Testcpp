#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // генератор псевдо-случайных чисел
#include <ctime> // для ввода текущего времени



using namespace std;


/*
Создадим класс (ООП) человек.
Человек имеет ряд показателей: деньги, голод, усталость.
Человек каждый день должен делать что-то: работать, читать,
играть, ходить в магазин и т.д.
Каждое действие изменяет какой-то из показателей.
Попробовать описать всё таким образом, чтобы человек
смог прожить 30 дней.
*/

class Human {
private: // здесь описываются показатели каждого человека
	string name; // имя
	double money; // деньги
	int hunger; // голод
	int fatigue; // усталость
	int food; // еда
	bool alive; // состояние

public: // здесь описываются методы (функции) или действия
// конструктор
	Human(string initialName, double initialMoney, int initialHunger) :
		name(initialName),
		money(initialMoney),
		hunger(initialHunger),
		fatigue(0),
		food(20),
		alive(true) {}
	

	// методы.
	// методы - это функции внутри класса.

	// метод работа
	void work() {
		if (fatigue < 80) {
			cout << name << " ходит на работу." << endl;
			money += 100; // его доход
			hunger -= 20; // проголодался
			fatigue += 20;
		}
		else {
			cout << name << " слишком устал, не может работать..." << endl;
			hunger -= 10;
		}
	}

	// метод поесть
	void eat() {
		if (food >= 20) {
			cout << name << " поел." << endl;
			hunger += 20;
			food -= 20;
			fatigue -= 5;
		} 
		else {
			cout << "У " << name << " нет еды..." << endl;
			fatigue += 5;
			hunger -= 10;
		}
	}

	// метод покупки еды
	void shop() {
		if (money >= 50) {
			cout << name << " сходил в магазин и купил еды." << endl;
			food += 20;
			money -= 50;
			fatigue += 10;
			hunger -= 10;
		}
		else {
			cout << "У " << name << " нет денег на еду..." << endl;
			fatigue += 10;
			hunger -= 10;
		}
	}

	void rest() {
		vector<string> options = { "почитал книгу", "поиграл в доту", "смотрел телевизор" };
		int options_index = rand() % options.size(); // будет 0, 1, 2
		cout << name << " " << options[options_index] << endl;
		fatigue -= 20;
		hunger -= 10;
	}

	void show() {
		cout << "День завершен. Показатели:" << endl;
		cout << name << endl;

		if (fatigue < 0) {
			fatigue = 0;
		}
		cout << "Деньги: " << money << "\nГолод: " << hunger << "\nУсталость: " << fatigue << "\nЕда: " << food << endl;
	}

	// проверь пульс
	bool check() {
		return alive;
	}

	void act() {
		// А не умер ли наш человек?
		if (hunger <= 0) {
			cout << name << " умер..." << endl;
			alive = false;
			return;
		}

		if (hunger < 40) {
			eat();
			return;
		}

		if (food == 0) {
			shop();
			return;
		}

		if (money == 0) {
			work();
			return;
		}

		int random = rand() % 5; // 0, 1, 2, 3, 4
		if (random == 1) {
			work();
		}
		else if (random == 2) {
			eat();
		}
		else if (random == 3) {
			shop();
		}
		else if (random == 4) {
			rest();
		}
		else {
			rest();
		}
	}

};


int main() {
	setlocale(LC_ALL, "RU");

	srand(static_cast<unsigned int>(time(0))); // ячейка для генератора
	
	Human petya("Петя", 150, 50); // создаю объект petya класса Human
	
	for (int i = 1; i <= 365; i++) {
		if (petya.check() == false)
			break;
		cout<< "##################" << "День " << i << "##################" << endl;
		petya.act();
		petya.show();
	}
	

	
	return 0;
}