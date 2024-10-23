/*
��������� ���� ���� ���� (21)

� ������� (� ��� 1 �����) � ������ �������� �� 2 �����.
����� ����� ���� ����� �����, �� ����� ������ 1 ����� ������.
����� ����� ���������: 1, 2, 3, 4 ...
����� ����� ������� ���� ���� ����� ��������� ��� 1 �����.
���� ����� ���� ���� ��������� 21, �� ��� ���������.
������ ���� ����� �������� �����. �� ��� ������ ����� ������.
���� ����� ���� ������ ������ 16, �� �� ���������� �������� �����.

����� = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11}
�����_������ = {}
�����_���������� = {}

���� 2 ����
	������� �����

*/

#include <iostream>
#include <vector>
#include <random> // ��� ���������� ��������������� �����
#include <cstdlib> // ����� ��������� srand, ����� ������ ��������� ����� ���������
#include <ctime> // ������ �������� �� ��������
#include <algorithm> // ������ �������� � �.�. � ���������

using namespace std;

// ������� ��� ���������� ������ �����
int deal_card() {
						//0  1  2  3  4 ... -> ������� ...       12   13
	vector<int> cards = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };
	 // ������������� ��������� ����� ��� ���
	int index = rand() % cards.size(); // 100 % 14 -> 0..13
	int card = cards[index]; // �������� ����� �� ���������� �������

	return card; // ���������� �����
}

// ������� �������� �����
void show_cards(vector<int> cards) {
	for (int i = 0; i < cards.size(); i++) {
		cout << cards[i] << " ";
	}
	cout << endl;
}

// �������� ������������ ����
int sum_cards(vector<int> cards) {
	// {10, 9} , �.�. ����� 19
	// {10, 9, 11} , �.�. ��� ������������ � 1. ����� 10+9+1 = 20
	int sum = 0;
	//  0  1  2  3
	// {4, 11, 7, 3}, size=4
	for (int i = 0; i < cards.size(); i++) {
		sum += cards[i]; // 0 + 4 + 3 + 7 + 5
	}
	// ��������� �������� ���� � 11 �� 1
	if ((sum == 21) && (cards.size() == 2)) {
		return 0; // 0 ��� ����� ��������
	}
	else if (sum > 21 && (find(cards.begin(), cards.end(), 11) != cards.end())) {
		// ����� ������ �������� 11
		auto index = find(cards.begin(), cards.end(), 11); // ������� ������� ������ 11
		cards.erase(index); // ����� ������� �� ����� �������
		// �������� ������� 1
		cards.push_back(1);

		// ������������� ����� ������
		sum = 0;
		for (int i = 0; i < cards.size(); i++) {
			sum += cards[i]; // 0 + 4 + 3 + 7 + 5
		}
	}

	return sum;

}

string calculate_result(int player, int computer) {
	if (player == 0)
		return "� ������ ���� ����. ������� �����.";
	else if (player > 21)
		return "� ������ �������. ������� ������.";
	else if (computer == 0)
		return "� ������ ���� ����. ������� ������.";
	else if (computer > 21)
		return "� ������ �������. ������� �����.";
	else if (player > computer)
		return "����� ������� �� ����� ����.";
	else if (computer > player)
		return "������ ������� �� ����� ����.";
	else if (player == computer)
		return "�����.";
}


int main() {
	setlocale(LC_ALL, "RU");

	// ������� � �������
	vector<int> player_cards = {};
	vector<int> computer_cards = {};
	srand(time(NULL)); // ��� ������ ���������� �� ������
	bool game_active = true; // ���������� ���������� �� ��� ����


	while (game_active) {
		cout << "-----------------------------------" << endl;
		// ������ ����� ������ � ������
		for (int i = 0; i < 2; i++) {
			player_cards.push_back(deal_card());
			computer_cards.push_back(deal_card());
		}

		// ������_�����(�����)
		cout << "����� ������: " << endl;
		show_cards(player_cards);
		// ������_�����(������)
		cout << "������ ����� ������: " << endl;
		cout << computer_cards[0] << endl << endl;


		string player_decision = "";

		//// ������� � ������ ���� �������
		while (player_decision != "no") {  // 120 17 22
			show_cards(player_cards);
			cout << "����� ����: " << sum_cards(player_cards) << endl;
			cout << "������� ���, ����� ��������� ����� ����" << endl;
			cout << "������� ��, ����� �������� 1 �����" << endl;
			cin >> player_decision; // ���� ������������ � ����.
			if (player_decision == "yes") {
				cout << "����������� ����� ������..." << endl;
				player_cards.push_back(deal_card());
				//show_cards(player_cards);
			}
			if (sum_cards(player_cards) >= 21) { // 11 5 5
				break;
			}
		}

		// ����� ���� ������
		// �� �������� �������� ������ �������� �����, ���� �� ����� ������ 17
		while (sum_cards(computer_cards) <= 17 && sum_cards(computer_cards) != 0) {
			computer_cards.push_back(deal_card());
		}

		// ���������� �������� ����� ������ � ������
		cout << endl << endl << "����� ������: ";
		show_cards(computer_cards);
		cout << "�����: " << sum_cards(computer_cards) << endl;
		cout << "����� ������: ";
		show_cards(player_cards);
		cout << "�����: " << sum_cards(player_cards) << endl;

		// ������� ����� ���� (��� �������, �������� ��� �����)
		cout << calculate_result(sum_cards(player_cards), sum_cards(computer_cards)) << endl;

		// ������� ������� � �������
		player_cards.clear(); // �������� ���� ��������� �������, ������� ��� ������
		computer_cards.clear(); // �� �� ��� ������� �������

		cout << "������� 0 ����� ��������� ����. ��� ��� ������ ����� ������� ������: ";
		
		string user_input;
		cin >> user_input; // ""
		if (user_input == "0") {
			game_active = false;
		}

		//cin >> game_active; // 0 == false, 1 == true
	}
	return 0;
}