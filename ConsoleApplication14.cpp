// ConsoleApplication14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "DHEnpoint.h"
using namespace std;

int main()
{
	int m_pub_k{ 3 }, m_priv_k{ 2 };
	int s_pub_k{ 5 }, s_priv_k{ 7 };
	DHEnpoint Sadat = DHEnpoint(s_pub_k, m_pub_k, s_priv_k);
	DHEnpoint Michael = DHEnpoint(s_pub_k, m_pub_k, m_priv_k);

	int m_partial_k = Michael.generatePartialKey();
	int s_partial_k = Sadat.generatePartialKey();

	int m_full_k = Michael.generateFullKey(s_partial_k);
	int s_full_k = Sadat.generateFullKey(m_partial_k);

	cout << "m_partial_k = " << m_partial_k << endl;
	cout << "s_partial_k = " << s_partial_k << endl;
	cout << "m_full_k = " << m_full_k << endl;
	cout << "s_full_k = " << s_full_k << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
