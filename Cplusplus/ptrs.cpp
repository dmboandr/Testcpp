#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	// ������ � ���������
	// ������ ����������� ����� ���-�� ����������������
	//int& a; // ���������������� - ������ ������ ��������
	int humanAverageLifespanPerCountry = 73;
	int& x = humanAverageLifespanPerCountry;

	int& c = x;

	c = 999;

	cout << "������ ����������: " << humanAverageLifespanPerCountry << endl;
	cout << "������ ����������: " << x << endl;
	

	// ��������� (��������) Pointers
	string first_name = "Dmitri";
	string* ptr_first_name = &first_name;

	cout << endl << "������� ���������" << endl;

	cout << "���� ����������: " << first_name << endl;
	cout << "�������: " << *ptr_first_name << endl;

	return 0;
	// dynamic load library
}