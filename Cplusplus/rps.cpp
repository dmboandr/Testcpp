/*
Консольная игра (в терминале) камень-ножницы-бумага.
Rock Paper Scissors.
Игрок может выбирать один из вариантов (r p s).
Если игрок выбирает что-то другое, то ему сообщают что такое выбирать
нельзя.

Компьютер выбирает свой вариант случайным образом.
Программа будет вести счёт, например: player 7 - 5 computer

Игра продолжается до тех пор, пока в консоль не напишут слово выхода:
quit, stop и т.д.


	основной цикл программы:
		игрок делает свой выбор из допустимых вариантов

		если игрок выбрал то, чего нельзя выбирать:
			сообщить об этом
			начать цикл заново

		компьютер делает выбор из допустимых вариантов

		если победил игрок
			прибавить единицу к счетчику побед игрока
		если победил компьютер
			прибавить единицу к счетчику побед компьютера

		отобразить счёт 2-3
*/



#include <iostream> // для консольного ввода-вывода
#include <vector> // вектор для создания массива
#include <random> // для генератора псевдослучайных чисел
#include <cstdlib> // здесь находится srand, чтобы делать генератор более случайным
#include <ctime> // разные операции со временем

using namespace std;

int main() {
	setlocale(LC_ALL, "RU"); // кодировку кириллицы

	int player_score = 0; // счет игрока
	int computer_score = 0; // счет компьютера
	string player_choice; // выбор игрока
	//							0		1			2
	vector<string> choices = { "rock", "paper", "scissors" };
	string computer_choice;
	int random_number;

	while (player_choice != "quit" && player_choice != "q") {

		cout << "Выберите один из вариантов:" << endl;
		std::cout << "rock paper scissors" << endl;
		std::cout << "Введите quit, чтобы завершить игру" << endl << endl;
		cin >> player_choice; // консольный ввод текста

		if (player_choice != "rock" && player_choice != "paper" && player_choice != "scissors" && player_choice != "q" && player_choice != "quit") {
			std::cout << "Сделан некорректный выбор." << endl;
			continue; // останавливает итерацию цикла, но не весь цикл
		}

		srand(time(NULL)); // настраиваю генератор случайных чисел
		random_number = rand() % 3; // применяю генератор случайных чисел
		//cout << random_number << endl;
		computer_choice = choices[random_number];

		std::cout << "Игрок: " << player_choice << " : " << computer_choice << " Компьютер" << endl;

		if (player_choice == "rock" && computer_choice == "scissors") {
			std::cout << "Победил игрок" << endl;
			player_score++;
		}
		else if (player_choice == "rock" && computer_choice == "paper") {
			std::cout << "Победил компьютер" << endl;
			computer_score++;
		}
		else if (player_choice == "rock" && computer_choice == "rock") {
			std::cout << "Ничья" << endl;
		}
		else if (player_choice == "paper" && computer_choice == "scissors") {
			std::cout << "Победил компьютер" << endl;
			computer_score++;
		} 
		else if (player_choice == "paper" && computer_choice == "paper") {
			std::cout << "Ничья" << endl;
		} 
		else if (player_choice == "paper" && computer_choice == "rock") {
			std::cout << "Победил игрок" << endl;
			player_score++;
		}
		else if (player_choice == "scissors" && computer_choice == "scissors") {
			std::cout << "Ничья" << endl;
		}
		else if (player_choice == "scissors" && computer_choice == "paper") {
			std::cout << "Победил игрок" << endl;
			player_score++;
		} 
		else if (player_choice == "scissors" && computer_choice == "rock") {
			std::cout << "Победил компьютер" << endl;
			computer_score++;
		}

		// игрок 2 - 5 компьютер

		cout << "Игрок " << player_score << " - " << computer_score << " компьютер" << endl << endl;
		 
	}

	std::cout << "Работа программы завершена. Игра окончена";

	return 0;
}
