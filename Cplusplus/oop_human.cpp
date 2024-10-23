#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // ��������� ������-��������� �����
#include <ctime> // ��� ����� �������� �������



using namespace std;


/*
�������� ����� (���) �������.
������� ����� ��� �����������: ������, �����, ���������.
������� ������ ���� ������ ������ ���-��: ��������, ������,
������, ������ � ������� � �.�.
������ �������� �������� �����-�� �� �����������.
����������� ������� �� ����� �������, ����� �������
���� ������� 30 ����.
*/

class Human {
private: // ����� ����������� ���������� ������� ��������
	string name; // ���
	double money; // ������
	int hunger; // �����
	int fatigue; // ���������
	int food; // ���
	bool alive; // ���������

public: // ����� ����������� ������ (�������) ��� ��������
// �����������
	Human(string initialName, double initialMoney, int initialHunger) :
		name(initialName),
		money(initialMoney),
		hunger(initialHunger),
		fatigue(0),
		food(20),
		alive(true) {}
	

	// ������.
	// ������ - ��� ������� ������ ������.

	// ����� ������
	void work() {
		if (fatigue < 80) {
			cout << name << " ����� �� ������." << endl;
			money += 100; // ��� �����
			hunger -= 20; // ������������
			fatigue += 20;
		}
		else {
			cout << name << " ������� �����, �� ����� ��������..." << endl;
			hunger -= 10;
		}
	}

	// ����� ������
	void eat() {
		if (food >= 20) {
			cout << name << " ����." << endl;
			hunger += 20;
			food -= 20;
			fatigue -= 5;
		} 
		else {
			cout << "� " << name << " ��� ���..." << endl;
			fatigue += 5;
			hunger -= 10;
		}
	}

	// ����� ������� ���
	void shop() {
		if (money >= 50) {
			cout << name << " ������ � ������� � ����� ���." << endl;
			food += 20;
			money -= 50;
			fatigue += 10;
			hunger -= 10;
		}
		else {
			cout << "� " << name << " ��� ����� �� ���..." << endl;
			fatigue += 10;
			hunger -= 10;
		}
	}

	void rest() {
		vector<string> options = { "������� �����", "������� � ����", "������� ���������" };
		int options_index = rand() % options.size(); // ����� 0, 1, 2
		cout << name << " " << options[options_index] << endl;
		fatigue -= 20;
		hunger -= 10;
	}

	void show() {
		cout << "���� ��������. ����������:" << endl;
		cout << name << endl;

		if (fatigue < 0) {
			fatigue = 0;
		}
		cout << "������: " << money << "\n�����: " << hunger << "\n���������: " << fatigue << "\n���: " << food << endl;
	}

	// ������� �����
	bool check() {
		return alive;
	}

	void act() {
		// � �� ���� �� ��� �������?
		if (hunger <= 0) {
			cout << name << " ����..." << endl;
			alive = false;
			return;
		}

		if (hunger < 40) {
			eat();
			return;
		}

		if (food == 0) {
			shop();
			return;
		}

		if (money == 0) {
			work();
			return;
		}

		int random = rand() % 5; // 0, 1, 2, 3, 4
		if (random == 1) {
			work();
		}
		else if (random == 2) {
			eat();
		}
		else if (random == 3) {
			shop();
		}
		else if (random == 4) {
			rest();
		}
		else {
			rest();
		}
	}

};


int main() {
	setlocale(LC_ALL, "RU");

	srand(static_cast<unsigned int>(time(0))); // ������ ��� ����������
	
	Human petya("����", 150, 50); // ������ ������ petya ������ Human
	
	for (int i = 1; i <= 365; i++) {
		if (petya.check() == false)
			break;
		cout<< "##################" << "���� " << i << "##################" << endl;
		petya.act();
		petya.show();
	}
	

	
	return 0;
}