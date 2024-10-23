/*
Hangman - ��� ������������ ������� ���� � ����������� ����.
(���� �����)

������ <- ���������  ������� ��������� �����
------
� <-
---�-�

*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  // ��������� ��������� �����
#include <ctime> // ��� ������ ���������� ��������� �����
#include <algorithm> // �������� ���������
// "� ������ ���� ����������������" -> {�, ������, ...}


using namespace std;

// ��������-��������������� ���������������� (������ � �������)
class Hangman {
private:
	string current_word; // ������� �����, ��� �� ���� �������
	string secter_word; // �������� �����, ������� �������� �������
	int lives; // ���������� �������
	string question;
	vector<char> guessed_letters; // ��������� ���� �����
	vector<string> questions = { 
		"�������� ����� ���������� ��������� ������������ �������, ���� ������� ������ 1 �������?",
		"�������� 4-� �� ����� ������� �� ������, ��������� � ����� ���� �����? �� ����������",
		"��� ���������� ������ ���������� ������������ ���� � ����������� ����? �� ����������",
		"������������, ������������ ����������� �������������� ���������� ������������ ����������?" };
	vector<string> words = { 
		"linux", // 0
		"mars", // 1
		"compile", // 2
		"cpu" }; // 3

	void get_question(int index) {
		question = questions[index];
	}

	// ������� ��������� ����� ��� ������ ����
	string get_word() {
		// ���������� ��������� ������
		int index = rand() % words.size();
		get_question(index);
		// ������� ��������� �����
		return words[index];

	}

	// ������� �������� �� ��������� ���� �������
	bool already_guessed(char letter) {
		return find(guessed_letters.begin(), guessed_letters.end(), letter) != guessed_letters.end();
	}

	// ������� ����������� ���������� ������� � ����� �����
	bool update_current_word(char letter) {
		bool correct_guess = false;

		// ���������� �� ���� �������� ������ �����
		for (int i = 0; i < secter_word.length(); i++) {
			if (secter_word[i] == letter) {
				// ���� �������� ������������� ������ ���� � �����
				// �� ��������� ��� � ������� �� �����
				current_word[i] = letter; // banana -a-a-a a
				correct_guess = true;
			}
		}
		// � ����� ������ ��������� ��� ��������� ������
		// � ������ ����� ��������������
		guessed_letters.push_back(letter);
		return correct_guess; // ���������� ��������� ��������
	}


public:
	// � ������� public ������ ��������� ��� ������ ������
	// ������� ������ �������� ������� ������ ������
	
	// ����������� - �������� ������ ���� �������
	Hangman() {
		srand(time(NULL)); // ���������� ���������
		secter_word = get_word(); // ��������� �����
		current_word = string(secter_word.length(), '-');
		lives = 10; // ���������� �������
	}

	// ����� ��� ������ ����
	void play() {
		cout << "����� ���������� � ���� Hangman" << endl;
		string letters;

		while ( (secter_word != current_word) and (lives > 0) ) {
			cout << "������� ��������: " << lives << endl << endl;
			cout << question << endl << endl;
			cout << "������� �����: " << current_word << endl;
			
			  // {a, b, c} " " + "a" = " a"
			 // "fg" + '190'
			letters = "";
			for (int i = 0; i < guessed_letters.size(); i++) {
				letters += guessed_letters[i];
			}
			cout << "�������� �������: " << letters << endl; // a b c

			cout << "������� ����� �����: ";
			char guess; // guess - �������
			cin >> guess;
			// alphabet = {a, b,  c, d, e ,f, ..., z}
			if ( isalpha(guess) ) {
				guess = tolower(guess);
				cout << "\n�� ����� ���������� ������: " << guess << endl;

				if (already_guessed(guess)) {
					cout << "�� ��� ������� ���� ������" << endl;
				}
				// � ���� �� �������...
				else {
					//guessed_letters.push_back(guess); // ��������� �������� ������

					bool correct_guess = update_current_word(guess);
				
					if (correct_guess) {
						cout << "\n�� ������� ����� " << guess << endl;
					}
					else {
						cout << "\n����� ����� ���, �� �������" << endl;
						lives -= 1; // �������� ���������� ������
					}
				}
			}
			else {
				cout << "\n�� ����� ������������ ������...";
			}
		}

		// ���������� ������
		if (secter_word == current_word) {
			cout << "�� ��������!" << endl;
		}
		else {
			cout << "�� ���������. ����� ����: " << secter_word << endl;
		}
	}	
};

int main() {
	setlocale(LC_ALL, "RU");
	 
	// ������ ������ ������ Hangman (����� ����)
	Hangman hangman;
	hangman.play();
	//cout << hangman.get_word() << endl;


	return 0;
}