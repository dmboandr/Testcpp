#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	cout << "������� 1 ��� �������� 1" << endl;
	cout << "������� 2 ��� �������� 2" << endl;
	cout << "������� 3 ��� �������� 3" << endl;
	int n;
	cin >> n;

	switch (n) // ����������� n
	{
		case 1: // if (n==1)
		{
			cout << "����������� �������� 1..." << endl;
			break;
		}
		case 2: // if (n==2)
		{
			cout << "����������� �������� 2..." << endl;
			break;
		}
		case 3:
		{
			cout << "����������� �������� 3..." << endl;
			break;
		}
		default: 
		{
			cout << "����������� �������" << endl;
			break;
		}
	}
	
	/*if (n == 1) {
		cout << "����������� �������� 1..." << endl;
	}
	else if (n == 2) {
		cout << "����������� �������� 2..." << endl;
	}
	else if (n == 3) {
		cout << "����������� �������� 3..." << endl;
	}
	else {
		cout << "����������� �������" << endl;
	}*/

	return 0;
}