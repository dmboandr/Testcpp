#include <iostream>
#include <vector>
#include <fstream> // файловый (txt) ввод-вывод
#include <string> // для разных функций связанных со строками
#include <sstream>  // это для разделения строки

using namespace std;

/*
Напишите программу, которая в последовательности натуральных чисел
определяет максимальное число, кратное 5.
Программа получает на вход количество чисел в последовательности,
а затем сами числа. В последовательности всегда имеется число, кратное 5.
Количество чисел не превышает 1000. Введенные числа не превышают 30 000.
Программа должна вывести одно число  — максимальное число, кратное 5.

3
10
25
12  --> 25

3
50
10
12  --> 50
*/

int max_of_five(unsigned int n) {

	int number;
	int max_num = 0;
	// i < 5? true ....
	for (int i = 0; i < n; i++) {
		cin >> number; // сюда мы вводим число

		
		if (number % 5 == 0 && number > max_num) { // кратно ли введённое число 5
			max_num = number;  // если да, то мы говорим, что это число макс
		}
		
	}
	return max_num; // возвращаем максимальное
}

int sum_of_six(int n) {

	int result = 0;

	

	return result;
}

int func() {
	//cout << endl << max_of_five(3);
	//
	//"11 2 3 4 5"

	string str = "-1 -2 -3 -4 -5";
	vector<string> numbers; // {"1", "2", "-5"}

	for (int i = 0; i < str.size(); i++) {

		if (str[i] != 32) {
			if (str[i] != 45) // "ab"[0]
				1 + 1;
				//numbers.push_back(str[i]);
		}
	}

	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "RU");
	/*cout << "X Y Z W" << endl;

	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			for (int z = 0; z < 2; z++) {
				for (int w = 0; w < 2; w++) {
					if ( (((x <= y) && (y <= w)) || (z == (x || y)))==false  ) {
						cout << x << " " << y << " " << z << " " << w << endl;
					}
				}

			}
		}
	}*/
	// 1. Прочитать текстовый файл и занести числа в массив
	vector<string> numbers = {};

	std::ifstream file; // создаю объект, который взаимодействует с файлом
	// ios::in - чтение файла
	// ios::out - запись в файл (с заменой всего что там было)
	// ios::app - добавить новый текст к существующему
	string text; // в этой строке будет хранится содержимое файла

	file.open("17 (2).txt"); // пытаюсь открыть файл

	if (!file.is_open()) {
		cout << "Не удалось открыть файл" << endl;
		return 1;
	}

	cout << "Получилось открыть файл" << endl;
	

	// прочитываю содержимое файла и записываю в массив
	while (getline(file, text)) {
		numbers.push_back(text);
	}
	file.close(); // закрыли файл
	cout << numbers.size() << endl; // numbers.size() - количество эл-тов

	//			  0  1  2   3  4
	// numbers = {6, 2, 9, –3, 6} 
	vector<int> pairs = {}; // размер этого массива и есть количество пар
	// "10" % 3
	//numbers = { "168", "7", "320", "328" };
	// 1000 * 1000 = 1000000
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i+1; j < numbers.size(); j++) {
			if ( (stoi(numbers[i]) % 160 != stoi(numbers[j]) % 160) and (stoi(numbers[i])%7==0 or stoi(numbers[j])%7==0) ) {
				pairs.push_back(stoi(numbers[i]) + stoi(numbers[j]));
				// 500 + '25791' = 0000156125
			}
		}
	}

	
	// это первый ответ, количество пар, где хотя бы 1 число кратно 3
	cout << pairs.size() << endl;
	int max = pairs[0]; // пока что считаем первый элемент максимальным

	for (int i = 1; i < pairs.size(); i++) { // проходимся по всем эл-там
		if (pairs[i] > max) { // сравниваю эл-т с максимальным
			max = pairs[i]; // новое максимальное теперь наш эл-т
		}
	}

	cout << max << endl; // максимальная сумма
	
	return 0;
}