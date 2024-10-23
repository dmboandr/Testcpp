#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // для std::find

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	// Массивы
	/*
	Массивы позволяют хранить множество данных под одним
	именем
	*/
							//   0    1   2   3   4   5  6
	vector<int> soldiers_age = {20, 22, 19, 35, 29, 26, 33, 20, 19, 18, 40, 38, 36, 20, 22, 19, 35, 29, 26, 33, 20, 19, 18, 40, 38, 36 , 20, 22, 19, 35, 29, 26, 33, 20, 19, 18, 40, 38, 36 };
	/*cout << soldiers_age[0] << endl;
	cout << fruits[10];*/
	//cout << soldiers_age.size() << endl; // .size() - функция, возвращающая кол-во эл массива

	int solds[] = { 'a', 'b', 'c'};
	
	double num = 123.456f;
	int num_1 = 0;
	num_1 = num; // преобразование типов из double в int
	cout << num_1 << endl;

	//solds[1]
	//int count = 0; // счётчик солдат за 30

	//for (int i = 0; i < soldiers_age.size(); i++) {
	//	if (soldiers_age[i] >= 30) {
	//		count++; // добавить 1 к count
	//	}
	//}

	//cout << "Солдат за 30: " << count  << " человека" << endl;

	//int a = 5;
	//a++; // постфиксный итератор
	//cout << a; // 6
	//++a; // префиксный итератор
	//a = 2 + a++; // 9
	//cout << a;

	//for (int i = 0; i < 5; i++) {
	//	cout << i << endl;
	//}

	vector<string> commands = { "end", "customers", "hi", "delete"};

	string user_input = "";
	commands.push_back("uninstall");

	cout << "Список возможных команд: ";
	for (int i = 0; i < commands.size(); ++i) {
		cout << commands[i] << " ";
	}
	cout << endl << endl;

	while (user_input != "quit") {
		cout << "Введите команду: ";
		cin >> user_input; // происходит ввод с клавиатуры

		if (user_input == commands[0]) {
			cout << "Работа программы завершена";
			break; // прервать весь цикл
		}
		else if (user_input == commands[1]) {
			cout << "Показываю список сотрудников: ..." << endl << endl;
		}
		else if (user_input == commands[2]) {
			cout << "Приветсвую, человек!" << endl << endl;
		}
		else if (std::find(commands.begin(), commands.end(), user_input) != commands.end()) {
			cout << "Команда распознана, но она еще на этапе разработки." << endl << endl;
		}
		else {
			cout << "Некорректная команда." << endl << endl;
		}
	}

	return 0;
}