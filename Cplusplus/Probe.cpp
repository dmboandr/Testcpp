#include <iostream>


using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	//// ���������� �������� � ����� ������
	//// �������� �������������
	//// int long unsigned int unsinged long short
	//unsigned int number = 1;
	//int number1 = 1000000;
	//
	//// bool string char int double
	//bool isHuman = true; // ������������ � camelCase
	//bool is_human = true;

	//string name;
	//int x = 1;
	//x = 1;

	//// �������� ������������ � �++ ��������:
	//// ������� �� ����� ������ (enter) \n
	//// ��������� \t TAB
	//// ������
	//cin >> x >> name;
	//cout << x << " " << name << endl;

	//// float 
	//double pi = 3.2362362314f;

	/*
	�������� ���������, �������� ��������� ���������
	*/

	//// ���������� �����������
	//double a, b, c;
	//cout << "������� ������������ a, b, c ����� ������: ";
	//cin >> a >> b >> c;
	//
	//// ������������ ������������
	//double d = pow(b, 2) - 4 * a * c;
	//cout << "������������: " << d << endl;
	//
	//// ���������� ��� ����������, �.�. �����
	//double x1, x2;

	//// ���� ������������ �������������
	//if (d < 0) {
	//	cout << "������� ���" << endl;
	//}
	//// ����  ������������ ����� 0
	//else if (d == 0) {
	//	x1 = -b / 2 * a;
	//	cout << "���� ������: x=" << x1 << endl;
	//}
	//// ��� �����:
	//// x1 = ...
	//// x2 = ...
	//else {
	//	x1 = (-b + sqrt(d)) / (2 * a);
	//	x2 = (-b - sqrt(d)) / (2 * a);
	//	cout << "��� �����: " << endl << "x1 = " << x1;
	//	cout << endl << "x2 = " << x2 << endl;
	//}

	// � ������ ���� ����������� �����������.
	// ����� �� 2: break � continue.
	// ��� ����������� ����������� ����� ������������� ����.

	/*for (int i = 0; i < 10; i++) {
		if (i == 5) {
			continue;
		}
		cout << i << endl;
	}*/

	/*
	�������� �������� �������� ������������ ���������� �����.
	��� ����� ������� �� ��������, ���� �� ������.
	� ��� ����� ��������.
	� �������� ���� ���������.
	����� �������� ���������, ������� ���������,
	������ �� �������� ����� �� ������� ���,
	��� ������������ ��������.

	money - ��� ���������� �����
	grants - ���������
	rent - �������� � �����
	expenses - ������� � �����

	*/

	cout << "������� ���������� ����� ��������: ";
	int money;
	cin >> money;

	double grants = 3000; // ���������
	double rent = 10000; // ������ ��������
	double expenses = 7000; // 
	double months = 0;

	for (int i = 0; i < 10; i++) {

		if (money < 0) {
			break;
		}
	}

	while (money >= 0) {
		months++; // ������� 1
		money += grants;
		money -= rent + expenses;
		cout << "����� �� " << months << " �����: ";
		cout << money << endl;
		if (months == 10) {
			break;
		}
	}

	if (months >= 10) {
		cout << "�������� ������ ���� �����";
	}
	else {
		cout << "�������� �� ������ ���� �����";
	}

	
	return 0;
}