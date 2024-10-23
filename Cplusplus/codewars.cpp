#include <string>
#include <iostream>
#include <cstdint>
#include <bitset>

using namespace std;

std::string even_or_odd(int number)
{	
	// 1 % 2 == 1
	// 2 % 2 == 0
	// 3 % 2 == 1
	// 4 % 2 == 0
	// 5 % 2 == 1
	if (number % 2 == 0) {
		return "Even";
	}
	else {
		return "Odd";
	}
}



std::string add_binary(uint64_t a, uint64_t b) {
	uint64_t n = a + b;

	if (n == 0) {
		return "0";
	}

	int reminder; // остаток
	string binary; // "10101010101"
	string c;
	// 1100111111110100101001010011010
	// 1000110101110111010001110010101001100111111110100101001010011010
	while (n != 0) {
		reminder = n % 2; // это всегда 1 или 0
		n = n / 2; // 15 / 2 = 7.5
		c = std::to_string(reminder);
		binary += c; // зафиксировать результат
		// конкатенация строк - это объединение строк (сложение)
		// пример: "" + "1" = "1"
		// "1" + "0" = "10"
		//  01234
		// "abcde" -> "edcba"
		// 
		// "e" + "d" + "c" + ... + = "edcba"
	}

	std::reverse(binary.begin(), binary.end()); // "abc" -> "cba"

	//string binary = std::bitset<32>(result).to_string();
	//// 
	//result = std::stoi(binary);
	//binary = std::to_string(result);

	return binary;
}
// -2 млдр до +2 млрд
// ~3 млрд -> -1 млрд

//9119 -> "811181"
// "9119"
// 81
int square_digits(int num) {
	string number = to_string(num); // 9119 -> "9119"
	string s = "";
	string temp = "";
	int digit;
	for (int i = 0; i < number.size(); i++) {
		temp.push_back(number[i]); // 9, 1
		digit = stoi(temp); // 9
		digit = digit * digit; // 81
		s += to_string(digit);
		temp.clear();
	}
	//cout << s << endl;
	int result = stoi(s);
	return result;
}


int main() {
	// 1111
	// junior middle senior
	int n = 9119;
	string s = to_string(n); // "9119" {'9', '1', '1'}
	string temp;
	temp.push_back(s[0]);
	cout << s << endl << temp + "abc" << endl; // 97 + 57
	cout << square_digits(9119) << endl; // 811181
	cout << square_digits(2112) << endl; // 4114
	cout << square_digits(90501) << endl; // 8102501

	return 0;

}

// (условие) ? действие1: действие2

// 1 + 1 = 2
// 2(dec) = 10(bin)