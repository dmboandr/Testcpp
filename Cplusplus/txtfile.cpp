#include <iostream> // консольный ввод-вывод
#include <fstream> // файловый (txt) ввод-вывод
#include <string> // для разных функций связанных со строками
#include <sstream>  // это для разделения строки
#include <vector> // для работы с массивами

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	// Взаимодействие с текстовыми файлами (чтение/запись)

	//// ЗАПИСАТЬ В ФАЙЛ
	//std::ofstream out; // создал переменную (объект)
	//out.open("input.txt", ios::app); // открыть файл для записи, относительный путь
	//// если файла не существует, то он будет создан
	//if (out.is_open()) {
	//	out << "123\n"; // сам текст что записать в файл
	//	// если мы несколько раз обращаемся к файлу с действием запись
	//	// то каждое новое обращение будет стирать старый текст
	//}
	//out.close(); // освобождаем файл из оперативной памяти

	//// ПРОЧИТАТЬ ИЗ ФАЙЛА
	//string line; // [тип  данных] имя;
	//std::ifstream in("config.txt"); // создал объект для чтение из файла
	//
	//if (in.is_open()) {
	//	// прочитать содержимое файла и отобразить каждую строку
	//	while (std::getline(in, line)) {
	//		cout << line << endl;
	//	}
	//}

	//in.close(); // закрыть файл, чтобы освободить память

	//std::ifstream file; // создаю объект, который взаимодействует с файлом
	//// ios::in - чтение файла
	//// ios::out - запись в файл (с заменой всего что там было)
	//// ios::app - добавить новый текст к существующему
	//string text;
	//vector<int> numbers;
	//int a;

	//file.open("input.txt");

	//if (file.is_open()) {
	//	std::getline(file, text);
	//}
	//file.close(); // закрыли файл

	/*cout << text << endl;
	std::istringstream is(text);*/

	//while (is) { // "115 20"
	//	is >> a;
	//	numbers.push_back(a); // {115, 20}
	//}

	//int sum = 0;
	//for (int i = 0; i < numbers.size()-1; i++) {
	//	sum += numbers[i];
	//}
	//cout << sum << endl; // хранится сумма

	//std::ofstream out; // создал переменную (объект)
	//out.open("output.txt");

	//if (out.is_open()) {
	//	// запиши содержимое переменной sum туда
	//	// куда указывает путь объека out
	//	out << sum; 
	//}
	//out.close();
	
	// "25 115 52525    252525 25252 252522"
	// if i == ' ' {
	// 
	// } 0    1    2
	// "511"
	// "25"
	// {'1', '1', '5', ' ', '2', '5'}


	// 5 -> INPUT.TXT
	// 1 + 2 + 3 + 4 + 5 = 15
	// 30 -> 1 + 2 + 3 + 4 + ... + 30

	// РЕШЕНИЕ

	std::ifstream file; // создаю объект, который взаимодействует с файлом
	// ios::in - чтение файла
	// ios::out - запись в файл (с заменой всего что там было)
	// ios::app - добавить новый текст к существующему
	string text; // в этой строке будет хранится содержимое файла

	file.open("input.txt");

	if (file.is_open()) {
		std::getline(file, text);
	}
	file.close(); // закрыли файл

	cout << text << endl;

	// a -> 97; 97 - a
	// "5" -> 5; 5 -> 53

	int number = std::stoi(text); // "00009999" -> 9999

	cout << number << endl;

	int result = 0;

	for (int i = 1; i <= number; i++) {
		// 0 + 1 = 1; 1 + 2 = 3; 3 + 3 = 6
		result += i;
	}
	
	cout << result << endl;

	std::ofstream out; // создал переменную (объект)
	out.open("output.txt");

	if (out.is_open()) {
	//	// запиши содержимое переменной sum туда
	//	// куда указывает путь объека out
		out << result; 
	}
	out.close();
	
	return 0;
}