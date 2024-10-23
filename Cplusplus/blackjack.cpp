/*
Карточная игра Блэк Джек (21)

И игрокам (у нас 1 игрок) и крупье выдаются по 2 карты.
Игрок видит свои карты сразу, но видит только 1 карту крупье.
Карты имеет стоимость: 1, 2, 3, 4 ...
Игрок после раздачи двух карт может запросить еще 1 карту.
Если сумма всех карт превышает 21, то это проигрышь.
Крупье тоже может добирать карты. Он это делает после игрока.
Если сумма карт крупье меньше 16, то он обзятально добирает карты.

карты = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11}
карты_игрока = {}
карты_компьютера = {}

цикл 2 раза
	раздать карты

*/

#include <iostream>
#include <vector>
#include <random> // для генератора псевдослучайных чисел
#include <cstdlib> // здесь находится srand, чтобы делать генератор более случайным
#include <ctime> // разные операции со временем
#include <algorithm> // разные операции в т.ч. с массивами

using namespace std;

// функция для случайного выбора карты
int deal_card() {
						//0  1  2  3  4 ... -> индексы ...       12   13
	vector<int> cards = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };
	 // устанавливаем начальное число для гсч
	int index = rand() % cards.size(); // 100 % 14 -> 0..13
	int card = cards[index]; // выбираем карту по случайному индексу

	return card; // возвращаем карту
}

// функция показать карты
void show_cards(vector<int> cards) {
	for (int i = 0; i < cards.size(); i++) {
		cout << cards[i] << " ";
	}
	cout << endl;
}

// фукнкция суммирования карт
int sum_cards(vector<int> cards) {
	// {10, 9} , т.е. сумма 19
	// {10, 9, 11} , т.е. туз превращается в 1. сумма 10+9+1 = 20
	int sum = 0;
	//  0  1  2  3
	// {4, 11, 7, 3}, size=4
	for (int i = 0; i < cards.size(); i++) {
		sum += cards[i]; // 0 + 4 + 3 + 7 + 5
	}
	// подменять значение туза с 11 на 1
	if ((sum == 21) && (cards.size() == 2)) {
		return 0; // 0 это будет блэкджек
	}
	else if (sum > 21 && (find(cards.begin(), cards.end(), 11) != cards.end())) {
		// найди индекс элемента 11
		auto index = find(cards.begin(), cards.end(), 11); // сначала находим индекс 11
		cards.erase(index); // удали элемент из этого индекса
		// добавить элемент 1
		cards.push_back(1);

		// пересчитываем сумму заново
		sum = 0;
		for (int i = 0; i < cards.size(); i++) {
			sum += cards[i]; // 0 + 4 + 3 + 7 + 5
		}
	}

	return sum;

}

string calculate_result(int player, int computer) {
	if (player == 0)
		return "У игрока Блэк Джэк. Победил игрок.";
	else if (player > 21)
		return "У игрока перебор. Победил крупье.";
	else if (computer == 0)
		return "У крупье Блэк Джэк. Победил крупье.";
	else if (computer > 21)
		return "У крупье перебор. Победил игрок.";
	else if (player > computer)
		return "Игрок победил по сумме карт.";
	else if (computer > player)
		return "Крупье победил по сумме карт.";
	else if (player == computer)
		return "Ничья.";
}


int main() {
	setlocale(LC_ALL, "RU");

	// массивы с картами
	vector<int> player_cards = {};
	vector<int> computer_cards = {};
	srand(time(NULL)); // это должно находиться за циклом
	bool game_active = true; // переменная отвечающая за ход игры


	while (game_active) {
		cout << "-----------------------------------" << endl;
		// раздай карты игроку и крупье
		for (int i = 0; i < 2; i++) {
			player_cards.push_back(deal_card());
			computer_cards.push_back(deal_card());
		}

		// покажи_карты(игрок)
		cout << "Карты игрока: " << endl;
		show_cards(player_cards);
		// покажи_карты(крупье)
		cout << "Первая карта крупье: " << endl;
		cout << computer_cards[0] << endl << endl;


		string player_decision = "";

		//// решение о доборе карт игроком
		while (player_decision != "no") {  // 120 17 22
			show_cards(player_cards);
			cout << "Сумма карт: " << sum_cards(player_cards) << endl;
			cout << "Введите нет, чтобы закончить добор карт" << endl;
			cout << "Введите да, чтобы добавить 1 карту" << endl;
			cin >> player_decision; // ввод пользователя с клав.
			if (player_decision == "yes") {
				cout << "Добавляется карта игроку..." << endl;
				player_cards.push_back(deal_card());
				//show_cards(player_cards);
			}
			if (sum_cards(player_cards) >= 21) { // 11 5 5
				break;
			}
		}

		// Добор карт крупье
		// По правилам БлэкДжэк крупье добирает карты, если их сумма меньше 17
		while (sum_cards(computer_cards) <= 17 && sum_cards(computer_cards) != 0) {
			computer_cards.push_back(deal_card());
		}

		// Показываем итоговые карты крупье и игрока
		cout << endl << endl << "Карты крупье: ";
		show_cards(computer_cards);
		cout << "Сумма: " << sum_cards(computer_cards) << endl;
		cout << "Карты игрока: ";
		show_cards(player_cards);
		cout << "Сумма: " << sum_cards(player_cards) << endl;

		// Рассчет итога игры (кто победил, проиграл или ничья)
		cout << calculate_result(sum_cards(player_cards), sum_cards(computer_cards)) << endl;

		// Очищаем массивы с картами
		player_cards.clear(); // удаление всех элементов массива, сделать его пустым
		computer_cards.clear(); // то же для второго массива

		cout << "Введите 0 чтобы завершить игру. Или что угодно чтобы сыграть заново: ";
		
		string user_input;
		cin >> user_input; // ""
		if (user_input == "0") {
			game_active = false;
		}

		//cin >> game_active; // 0 == false, 1 == true
	}
	return 0;
}