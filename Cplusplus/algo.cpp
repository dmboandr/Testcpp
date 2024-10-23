#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL)); // ���������� ��������� ��������� �����
	//int random_number = rand() % 100; // �������� ��������� ��������� �����
	unsigned int random_number; // 0 ���� �� 4 ����
	cin >> random_number;
	vector<int> numbers = {}; // ������ �������� ������
	
	// �������� ������ numbers ������� �� 0 �� 100
	for (int i = 0; i <= random_number * 1.7 + random_number / 3; i++)
	{
		numbers.push_back(i);
	}

	cout << "��������� �����: " << random_number << endl;


	// �������� ��������� ������
	// ��������� O(n) - �������� ���������.
	// �� ���� ���� ���� ����������� 1000 ���, �� � ������ ������
	// ��������� ����� 1000.
	// �������� ���������� ������� numbers

	cout << "�������� ��������� ������" << endl;
	for (int i = 0; i < numbers.size(); i++)
	{
		//cout << "���: " << i + 1 << endl;
		//cout << numbers[i] << " ";
		if (numbers[i] == random_number) {
			cout << "��������� ����� " << random_number << " �������!" << endl;
			cout << "�� ����: " << i << endl;
			break;
		}
	}

	// �������� ��������� (���������) ������
	// ���� �������� �������� ������ � ��������������� ��������
	// {0, 1, 2, 3, 4, 5}
	// {5, 2, 0, 4, 1}
	//  0  1  2  3
	// {0, 1, 2, 3, 4, ..., 50} - 51
	int left = numbers[0]; // ��� 0
	int right = numbers.size() - 1; // ��� 100
	int mid;
	int count = 0; // ������� �����

	cout << "�������� ��������� ������" << endl;
	while (left <= right) {
		count++; // ������� ������� �� 1
		
		mid = (left + right) / 2; // 101 / 2 = 50.5
		cout << "���: " << count << " ��������: " << mid << endl;
		if (mid == random_number) {
			cout << "����� " << random_number << " �������!" << endl;
			break;
		}
		// 70
		// 50..100
		if (random_number > mid) {
			left = mid;
		}
		else {
			right = mid;
		}
	}

	return 0;
}