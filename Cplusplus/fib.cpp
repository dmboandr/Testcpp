#include <iostream>
#include <vector>

using namespace std;

void rec(int n) {
	if (n == 5) return;
	cout << n << endl;
	rec(n + 1);
	cout << n << endl;
	
}
// Решение через рекурсию
double fib(double n) {
	if (n == 1) return 0;
	if (n == 2) return 1;
	return fib(n-1) + fib(n-2);
}

// Динамическое программирование

// рекурсия
int main() {
	setlocale(LC_ALL, "RU");
	// Ряд чисел Фибоначчи
	// 1  2  3  4  5  6  7  8  9
	// 0, 1, 1, 2, 3, 5, 8, 13, 21
	// Рассчитать число Фибоначчи до какого-то числа
	//cout << fib(65) << endl;
	//                     0  1
	vector<int64_t> dyn_fib = {0, 1};

	for (int i = 2; i < 100; i++) {
		dyn_fib.push_back(dyn_fib[i-1] + dyn_fib[i-2]);
	}
	// -2 млрд до +2 млдр
	for (int i = 0; i < dyn_fib.size(); i++) {
		cout << dyn_fib[i] << endl;
	}

	cout << dyn_fib[65] << endl;

	return 0;
}