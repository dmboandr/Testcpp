#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool chk_prts(string text) {
	stack<char> stk;
	
	for (int i = 0; i < text.size(); i++) {
		if (stk.empty() && text[i] == ')') {
			return false;
		}

		if (text[i] == '(') {
			stk.push(text[i]);
		}
		else if (text[i] == ')' && stk.top() == '(') {
			stk.pop();
		}
	}
	if (stk.empty()) return true;
	else return false;
}

int main() {
	setlocale(LC_ALL, "RU");
	string expression_1 = "()()";
	string expression_2 = ")(()";
	string expression_3 = "((()(()))())()";

	// ")"

	cout << "��������� " << expression_1 << " ������������������: " << chk_prts(expression_1) << endl;
	cout << "��������� " << expression_2 << " ������������������: " << chk_prts(expression_2) << endl;
	cout << "��������� " << expression_3 << " ������������������: " << chk_prts(expression_3) << endl;
	return 0;
}