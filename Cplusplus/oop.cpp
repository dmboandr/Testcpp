#include <iostream>
#include <string>

using namespace std;

// ���������� �� �++ ��������� C with classes
// �� ���� ��� ��� �� �, �� � ���������� ���

// ����� �������� �������� ��� ��������
// ������ ������ ����������� ����� �������� � ��������
// ���� � �������� ����� ������.
class Person {
	// ������� ����� ���������
	// ���������� ������ ������ ������� ����������
	// ���������� ������ ������ = �������.
	private:
		string name;
		int age;
		string job;
		int salary;

	// � ������ ����� ���� ����� �������.
	// �������, ������� ��������� ������ ������
	// � ��������� �������� ��� ������������ ������ (������)
	// �������� ��������.
	// ������� ������ ������ = �����.
	public:
		// ������ ����� setName
		void setName(string n) {
			name = n;
		}

		void setAge(int a) {
			age = a;
		}

		void setJobName(string j) {
			job = j;
		}

		void setSalary(int s) {
			salary = s;
		}

		int calculateSalary(int months) {
			return months*salary;
		}

		void show() {
			cout << "���:  " << name << endl;
			cout << "�������:  " << age << endl;
			cout << "���������:  " << job << endl;
		}
		
};

int main() {
	setlocale(LC_ALL, "RU");

	// ������ - ��� ��������� �� ������ ������ ���������
	Person person_1; // ������ ������ ������ Person
	person_1.setName("Vasilii");
	person_1.setAge(40);
	person_1.setJobName("builder");
	person_1.setSalary(97455);

	Person person_2;  // ������ ��� ���� ������ ������ Person
	person_2.setName("Natalia");
	person_2.setAge(30);
	person_2.setJobName("doctor");
	person_2.setSalary(132650);

	person_1.show();

	person_2.show();

	cout << "�������� �������� �� 6 �������: " << person_1.calculateSalary(6) << endl;
	cout << "�������� ����� �� 8 �������: " << person_2.calculateSalary(8) << endl;

	string b = "";
	b.push_back(1);

	return 0;
}