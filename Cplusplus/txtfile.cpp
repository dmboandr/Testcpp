#include <iostream> // ���������� ����-�����
#include <fstream> // �������� (txt) ����-�����
#include <string> // ��� ������ ������� ��������� �� ��������
#include <sstream>  // ��� ��� ���������� ������
#include <vector> // ��� ������ � ���������

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	// �������������� � ���������� ������� (������/������)

	//// �������� � ����
	//std::ofstream out; // ������ ���������� (������)
	//out.open("input.txt", ios::app); // ������� ���� ��� ������, ������������� ����
	//// ���� ����� �� ����������, �� �� ����� ������
	//if (out.is_open()) {
	//	out << "123\n"; // ��� ����� ��� �������� � ����
	//	// ���� �� ��������� ��� ���������� � ����� � ��������� ������
	//	// �� ������ ����� ��������� ����� ������� ������ �����
	//}
	//out.close(); // ����������� ���� �� ����������� ������

	//// ��������� �� �����
	//string line; // [���  ������] ���;
	//std::ifstream in("config.txt"); // ������ ������ ��� ������ �� �����
	//
	//if (in.is_open()) {
	//	// ��������� ���������� ����� � ���������� ������ ������
	//	while (std::getline(in, line)) {
	//		cout << line << endl;
	//	}
	//}

	//in.close(); // ������� ����, ����� ���������� ������

	//std::ifstream file; // ������ ������, ������� ��������������� � ������
	//// ios::in - ������ �����
	//// ios::out - ������ � ���� (� ������� ����� ��� ��� ����)
	//// ios::app - �������� ����� ����� � �������������
	//string text;
	//vector<int> numbers;
	//int a;

	//file.open("input.txt");

	//if (file.is_open()) {
	//	std::getline(file, text);
	//}
	//file.close(); // ������� ����

	/*cout << text << endl;
	std::istringstream is(text);*/

	//while (is) { // "115 20"
	//	is >> a;
	//	numbers.push_back(a); // {115, 20}
	//}

	//int sum = 0;
	//for (int i = 0; i < numbers.size()-1; i++) {
	//	sum += numbers[i];
	//}
	//cout << sum << endl; // �������� �����

	//std::ofstream out; // ������ ���������� (������)
	//out.open("output.txt");

	//if (out.is_open()) {
	//	// ������ ���������� ���������� sum ����
	//	// ���� ��������� ���� ������ out
	//	out << sum; 
	//}
	//out.close();
	
	// "25 115 52525    252525 25252 252522"
	// if i == ' ' {
	// 
	// } 0    1    2
	// "511"
	// "25"
	// {'1', '1', '5', ' ', '2', '5'}


	// 5 -> INPUT.TXT
	// 1 + 2 + 3 + 4 + 5 = 15
	// 30 -> 1 + 2 + 3 + 4 + ... + 30

	// �������

	std::ifstream file; // ������ ������, ������� ��������������� � ������
	// ios::in - ������ �����
	// ios::out - ������ � ���� (� ������� ����� ��� ��� ����)
	// ios::app - �������� ����� ����� � �������������
	string text; // � ���� ������ ����� �������� ���������� �����

	file.open("input.txt");

	if (file.is_open()) {
		std::getline(file, text);
	}
	file.close(); // ������� ����

	cout << text << endl;

	// a -> 97; 97 - a
	// "5" -> 5; 5 -> 53

	int number = std::stoi(text); // "00009999" -> 9999

	cout << number << endl;

	int result = 0;

	for (int i = 1; i <= number; i++) {
		// 0 + 1 = 1; 1 + 2 = 3; 3 + 3 = 6
		result += i;
	}
	
	cout << result << endl;

	std::ofstream out; // ������ ���������� (������)
	out.open("output.txt");

	if (out.is_open()) {
	//	// ������ ���������� ���������� sum ����
	//	// ���� ��������� ���� ������ out
		out << result; 
	}
	out.close();
	
	return 0;
}