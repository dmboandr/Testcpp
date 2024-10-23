/*
Hangman - это алнгоязычный вариант игры с угадыванием слов.
(Поле чудес)

СОБАКА <- программа  выбрала случайное слово
------
а <-
---А-А

*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  // генератор случайный чисел
#include <ctime> // для работы генератора случайный чисел
#include <algorithm> // полезные алгоритмы
// "я изучаю язык программирования" -> {я, изучаю, ...}


using namespace std;

// Объектно-ориентированное программирование (классы и объекты)
class Hangman {
private:
	string current_word; // текущее слово, что мы пока угадали
	string secter_word; // реальное слово, которое пытаемся угадать
	int lives; // количество попыток
	string question;
	vector<char> guessed_letters; // угаданные нами буквы
	vector<string> questions = { 
		"Название самой популярной серверной операционной системы, ядро которой создал 1 человек?",
		"Название 4-й по счету планеты от солнца, названная в честь бога войны? На английском",
		"Как называется подход трансляции программного кода в исполняемый файл? На английском",
		"Аббревиатура, обозначающая центральное вычислительное устройство современного компьютера?" };
	vector<string> words = { 
		"linux", // 0
		"mars", // 1
		"compile", // 2
		"cpu" }; // 3

	void get_question(int index) {
		question = questions[index];
	}

	// выбрать случайное слово для начала игры
	string get_word() {
		// генерируем случайный индекс
		int index = rand() % words.size();
		get_question(index);
		// вернуть случайное слово
		return words[index];

	}

	// функция проверки на повторный ввод символа
	bool already_guessed(char letter) {
		return find(guessed_letters.begin(), guessed_letters.end(), letter) != guessed_letters.end();
	}

	// функция определения нахождения символа в нашем слове
	bool update_current_word(char letter) {
		bool correct_guess = false;

		// проходимся по всем символам нашего слова
		for (int i = 0; i < secter_word.length(); i++) {
			if (secter_word[i] == letter) {
				// если введённый пользователем символ есть в слове
				// то сохраняем его и выходим из цикла
				current_word[i] = letter; // banana -a-a-a a
				correct_guess = true;
			}
		}
		// в любом случае добавляем уже введенный символ
		// в массив ранее использованных
		guessed_letters.push_back(letter);
		return correct_guess; // возвращаем результат проверки
	}


public:
	// в разделе public обычно находятся все методы класса
	// методом класса называют функцию внутри класса
	
	// конструктор - заполнит нужные поля данными
	Hangman() {
		srand(time(NULL)); // настраиваю генератор
		secter_word = get_word(); // случайное слово
		current_word = string(secter_word.length(), '-');
		lives = 10; // количество попыток
	}

	// здесь вся логика игры
	void play() {
		cout << "Добро пожаловать в игру Hangman" << endl;
		string letters;

		while ( (secter_word != current_word) and (lives > 0) ) {
			cout << "Попыток осталось: " << lives << endl << endl;
			cout << question << endl << endl;
			cout << "Текущее слово: " << current_word << endl;
			
			  // {a, b, c} " " + "a" = " a"
			 // "fg" + '190'
			letters = "";
			for (int i = 0; i < guessed_letters.size(); i++) {
				letters += guessed_letters[i];
			}
			cout << "Введённые символы: " << letters << endl; // a b c

			cout << "Введите букву слова: ";
			char guess; // guess - угадать
			cin >> guess;
			// alphabet = {a, b,  c, d, e ,f, ..., z}
			if ( isalpha(guess) ) {
				guess = tolower(guess);
				cout << "\nВы ввели корректный символ: " << guess << endl;

				if (already_guessed(guess)) {
					cout << "Вы уже вводили этот символ" << endl;
				}
				// а если не вводили...
				else {
					//guessed_letters.push_back(guess); // добавляем введённый символ

					bool correct_guess = update_current_word(guess);
				
					if (correct_guess) {
						cout << "\nВы угадали букву " << guess << endl;
					}
					else {
						cout << "\nТакой буквы нет, не угадали" << endl;
						lives -= 1; // отнимаем количество жизней
					}
				}
			}
			else {
				cout << "\nВы ввели некорректный символ...";
			}
		}

		// подведение итогов
		if (secter_word == current_word) {
			cout << "Вы победили!" << endl;
		}
		else {
			cout << "Вы проиграли. Слово было: " << secter_word << endl;
		}
	}	
};

int main() {
	setlocale(LC_ALL, "RU");
	 
	// создаю объект класса Hangman (нашей игры)
	Hangman hangman;
	hangman.play();
	//cout << hangman.get_word() << endl;


	return 0;
}