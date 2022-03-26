#include <iostream>
#include <string>
#include "DHEnpoint.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int sec, k_base, k_mode;

	cout << "Введите парамтры в следующем порядке: СЕКРЕТ БАЗА МОДУЛЬ: " << endl;
	cout << "Секрет: "; cin >> sec;
	cout << "База: "; cin >> k_base;
	cout << "Модуль: "; cin >> k_mode;

	DHEnpoint* endpoint = new DHEnpoint(sec, k_base, k_mode);

	int outsidePartialKey;
	cout << "Введите частичный ключ второй строны: ";
	cin >> outsidePartialKey;

	endpoint->generateFullKey(outsidePartialKey);
	endpoint->encryptFile("message.txt");
}