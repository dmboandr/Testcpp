/*
���������� ���� (� ���������) ������-�������-������.
Rock Paper Scissors.
����� ����� �������� ���� �� ��������� (r p s).
���� ����� �������� ���-�� ������, �� ��� �������� ��� ����� ��������
������.

��������� �������� ���� ������� ��������� �������.
��������� ����� ����� ����, ��������: player 7 - 5 computer

���� ������������ �� ��� ���, ���� � ������� �� ������� ����� ������:
quit, stop � �.�.


	�������� ���� ���������:
		����� ������ ���� ����� �� ���������� ���������

		���� ����� ������ ��, ���� ������ ��������:
			�������� �� ����
			������ ���� ������

		��������� ������ ����� �� ���������� ���������

		���� ������� �����
			��������� ������� � �������� ����� ������
		���� ������� ���������
			��������� ������� � �������� ����� ����������

		���������� ���� 2-3
*/



#include <iostream> // ��� ����������� �����-������
#include <vector> // ������ ��� �������� �������
#include <random> // ��� ���������� ��������������� �����
#include <cstdlib> // ����� ��������� srand, ����� ������ ��������� ����� ���������
#include <ctime> // ������ �������� �� ��������

using namespace std;

int main() {
	setlocale(LC_ALL, "RU"); // ��������� ���������

	int player_score = 0; // ���� ������
	int computer_score = 0; // ���� ����������
	string player_choice; // ����� ������
	//							0		1			2
	vector<string> choices = { "rock", "paper", "scissors" };
	string computer_choice;
	int random_number;

	while (player_choice != "quit" && player_choice != "q") {

		cout << "�������� ���� �� ���������:" << endl;
		std::cout << "rock paper scissors" << endl;
		std::cout << "������� quit, ����� ��������� ����" << endl << endl;
		cin >> player_choice; // ���������� ���� ������

		if (player_choice != "rock" && player_choice != "paper" && player_choice != "scissors" && player_choice != "q" && player_choice != "quit") {
			std::cout << "������ ������������ �����." << endl;
			continue; // ������������� �������� �����, �� �� ���� ����
		}

		srand(time(NULL)); // ���������� ��������� ��������� �����
		random_number = rand() % 3; // �������� ��������� ��������� �����
		//cout << random_number << endl;
		computer_choice = choices[random_number];

		std::cout << "�����: " << player_choice << " : " << computer_choice << " ���������" << endl;

		if (player_choice == "rock" && computer_choice == "scissors") {
			std::cout << "������� �����" << endl;
			player_score++;
		}
		else if (player_choice == "rock" && computer_choice == "paper") {
			std::cout << "������� ���������" << endl;
			computer_score++;
		}
		else if (player_choice == "rock" && computer_choice == "rock") {
			std::cout << "�����" << endl;
		}
		else if (player_choice == "paper" && computer_choice == "scissors") {
			std::cout << "������� ���������" << endl;
			computer_score++;
		} 
		else if (player_choice == "paper" && computer_choice == "paper") {
			std::cout << "�����" << endl;
		} 
		else if (player_choice == "paper" && computer_choice == "rock") {
			std::cout << "������� �����" << endl;
			player_score++;
		}
		else if (player_choice == "scissors" && computer_choice == "scissors") {
			std::cout << "�����" << endl;
		}
		else if (player_choice == "scissors" && computer_choice == "paper") {
			std::cout << "������� �����" << endl;
			player_score++;
		} 
		else if (player_choice == "scissors" && computer_choice == "rock") {
			std::cout << "������� ���������" << endl;
			computer_score++;
		}

		// ����� 2 - 5 ���������

		cout << "����� " << player_score << " - " << computer_score << " ���������" << endl << endl;
		 
	}

	std::cout << "������ ��������� ���������. ���� ��������";

	return 0;
}
