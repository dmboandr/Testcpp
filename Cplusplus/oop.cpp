#include <iostream>
#include <string>

using namespace std;

// Изначально ЯП С++ назывался C with classes
// то есть это был ЯП С, но с поддержкой ООП

// Класс является шаблоном для объектов
// Внутри класса описывается какие свойства и действия
// есть у объектов этого класса.
class Person {
	// Создаем набор атрибутов
	// Переменные внутри класса называю атрибутами
	// Переменная внутри класса = атрибут.
	private:
		string name;
		int age;
		string job;
		int salary;

	// У класса также есть набор методов.
	// Функции, которые создаются внутри класса
	// и описывают дейсвтия над экземплярами класса (объект)
	// называют методами.
	// Функция внутри класса = метод.
	public:
		// создал метод setName
		void setName(string n) {
			name = n;
		}

		void setAge(int a) {
			age = a;
		}

		void setJobName(string j) {
			job = j;
		}

		void setSalary(int s) {
			salary = s;
		}

		int calculateSalary(int months) {
			return months*salary;
		}

		void show() {
			cout << "Имя:  " << name << endl;
			cout << "Возраст:  " << age << endl;
			cout << "Профессия:  " << job << endl;
		}
		
};

int main() {
	setlocale(LC_ALL, "RU");

	// объект - это созданный на основе класса экземпляр
	Person person_1; // создал объект класса Person
	person_1.setName("Vasilii");
	person_1.setAge(40);
	person_1.setJobName("builder");
	person_1.setSalary(97455);

	Person person_2;  // Создал еще один объект класса Person
	person_2.setName("Natalia");
	person_2.setAge(30);
	person_2.setJobName("doctor");
	person_2.setSalary(132650);

	person_1.show();

	person_2.show();

	cout << "Зарплата рабочего за 6 месяцев: " << person_1.calculateSalary(6) << endl;
	cout << "Зарплата врача за 8 месяцев: " << person_2.calculateSalary(8) << endl;

	string b = "";
	b.push_back(1);

	return 0;
}