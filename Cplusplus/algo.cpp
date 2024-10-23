#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL)); // настраиваю генератор случайных чисел
	//int random_number = rand() % 100; // применяю генератор случайных чисел
	unsigned int random_number; // 0 млрд до 4 млрд
	cin >> random_number;
	vector<int> numbers = {}; // создал числовой массив
	
	// заполнил массив numbers числами от 0 до 100
	for (int i = 0; i <= random_number * 1.7 + random_number / 3; i++)
	{
		numbers.push_back(i);
	}

	cout << "Случайное число: " << random_number << endl;


	// АЛГОРИТМ ЛИНЕЙНОГО ПОИСКА
	// Сложность O(n) - линейная сложность.
	// То есть если цикл выполняется 1000 раз, то в худшем случае
	// сложность будет 1000.
	// показать содержимое массива numbers

	cout << "АЛГОРИТМ ЛИНЕЙНОГО ПОИСКА" << endl;
	for (int i = 0; i < numbers.size(); i++)
	{
		//cout << "Шаг: " << i + 1 << endl;
		//cout << numbers[i] << " ";
		if (numbers[i] == random_number) {
			cout << "Случайное число " << random_number << " найдено!" << endl;
			cout << "На шаге: " << i << endl;
			break;
		}
	}

	// АЛГОРИТМ ДВОИЧНОГО (БИНАРНОГО) ПОИСКА
	// этот алгоритм работает только в отсортированных массивах
	// {0, 1, 2, 3, 4, 5}
	// {5, 2, 0, 4, 1}
	//  0  1  2  3
	// {0, 1, 2, 3, 4, ..., 50} - 51
	int left = numbers[0]; // это 0
	int right = numbers.size() - 1; // это 100
	int mid;
	int count = 0; // счётчик шагов

	cout << "АЛГОРИТМ ДВОИЧНОГО ПОИСКА" << endl;
	while (left <= right) {
		count++; // увечись счетчик на 1
		
		mid = (left + right) / 2; // 101 / 2 = 50.5
		cout << "Шаг: " << count << " Половина: " << mid << endl;
		if (mid == random_number) {
			cout << "Число " << random_number << " найдено!" << endl;
			break;
		}
		// 70
		// 50..100
		if (random_number > mid) {
			left = mid;
		}
		else {
			right = mid;
		}
	}

	return 0;
}