﻿#include <iostream>

using namespace std;

int main()
{
    // Установление кодировки русских символов
    setlocale(LC_ALL, "RU");
    //cout << "Привет!\n";
    // //консольный ввод
    //int age;
    //cout << "Введите ваш возраст: ";
    //cin >> age;

    //// арифметические операции
    //// + - * / %

    //// операторы сравнения
    //// > >= < <= == != !
    //// a == b -> true

    //// логические операции
    //// && (И)   || (ИЛИ) ! (НЕТ)

    //// условная конструкция
    //if (age >= 18) {
    //    cout << "Вы можете водить автомобиль.";
    //}
    //else {
    //    cout << "Вам нет 18. Вы не можете водить автомобиль.";
    //}

    //int month; // здесь будет храниться номер месяца
    //cout << "Введите номер месяца: ";
    //cin >> month; // консольный ввод в month

    //if (month == 1 || month == 2 || month == 12) {
    //    cout << "Зима";
    //}
    //else if (month == 3 || month == 4 || month == 5) {
    //    cout << "Весна";
    //}
    //else if (month == 6 || month == 7 || month == 8) {
    //    cout << "Лето";
    //}
    //else if (month >= 9 && month <= 11) {
    //    cout << "Осень";
    //}
    //else {
    //    cout << "Вы ввели некорректное значение\n";
    //    cout << "Введите число от 1 до 12.";
    //}

    // ЦИКЛИЧЕСКИЕ КОНСТРУКЦИИ (ЦИКЛЫ)

    /*
    Циклы бывают двух видов:
    1) Циклы когда мы знаем (относительно) сколько итераций
    (цикл for)
    2) Циклы когда мы не знаем сколько итераций.
    */
    
    //  итерация - это одно из множественных повторений цикла
    
    /*
    Вывести квадраты чисел от 1 до 1000.
    1*1 = 1
    2*2 = 4
    3*3 = 9
    4*4 = 16
    5*5 = 25
    */
    
    // 1^2=1
    // 2^2=4
    /*for (int i = 1; i <= 1000; i++) {
        cout << i << "^2=" << i*i << endl;
    }*/

    /*
    fizzbuzz - известная задача в программировании.
    Перебираются числа от 1 до 100.
    Если число кратно 3, вместо числа пишут fizz
    Если число кратно 5, вместо числа пишут buzz
    Если число кратно 3 и 5, то пишут fizzbuzz
    */

    /*for (int i = 1; i <= 100; i++) {
        if ((i % 3 == 0) && (i % 5 == 0)) {
            cout << "fizzbuzz" << endl;
        }
        else if (i % 3 == 0) {
            cout << "fizz" << endl;
        }
        else if (i % 5 == 0) {
            cout << "buzz" << endl;
        }
        else {
            cout << i << endl;
        }
    }*/

    //int number;
    //cin >> number; // если я ввёл 51
    //number += 1; // это  то же самое, что number = number + 1;
    //number--; // это сокращенная запись number += 1
    //cout << number; // вывелось бы 20
    //cin >> number;
    //// 15 20 25 30 45
    //if (number % 5 == 0) {
    //    cout << "нечётное";
    //}


    // ЦИКЛ WHILE
    // Пока условие в скобках истинно, цикл while продолжается
    
    /*int userInput = 10;

    while (userInput != 0) {
        cout << "Выполняется много действий..." << endl;
        cout << "Введите 0, чтобы завершить программу: ";
        cin >> userInput;
        }*/

    int i = 0;

    while (i < 5) {
        cout << "Привет " << i << endl;
        i++;
    }


    return 0;
}
