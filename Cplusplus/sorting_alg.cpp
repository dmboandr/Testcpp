// ��������� ���������� ��������
// array - ������

#include <iostream>
#include <vector>
#include <math.h> // ��������� ���������� ������� � .h �� �����
// .h - ��� ���������� �� header (���������)
// ��� ������, ��� ��� ���������� ����� ��� ������ �� ����� �
// � � ����� C ��� ���������� ����� ������ .h � ����� �����.

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	// 2^1 = 2
	// 2^2 = 4
	// 2^3 = 8
	//...
	// 3^1 = 1
	// 3^2 = 9
	//for (int i = 2; i <= 10; i++) {

	//	for (int j = 2; j <= 10; j++) { // 2^4
	//		cout << i << "^" << j << " = " << pow(i, j) << endl; // power
	//	}

	//	cout << endl;
	//}

	// ����������� ����������
	vector<int> arr = { 2, 4, 3, 5, 1 };
	int temp = arr[0]; // ����� �������� 2
	arr[0] = arr[1]; // { 4, 4, 3, 5, 1 };
	arr[1] = temp;

	//vector<int> arr_sorted = {};
	// ��������� - ��� ������� ������, ��� ����������,
	// ������ �������� ��������� ������ �������������.
	const int N = arr.size(); // ���������� ��������� �������
	
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	for (int i = 1; i < N; i++) {	       //  0  1  2  3  4
		for (int j = 0; j < N-i; j++) { // { 2, 4, 3, 5, 1 };
			if (arr[i] > arr[j]) { // 2 > 3
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}

	return 0;
}