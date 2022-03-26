#include "DHEnpoint.h"


DHEnpoint::DHEnpoint(int sec, int k_base, int k_mod) {
	this->sec = sec;
	this->k_base = k_base;
	this->k_mod = k_mod;

	cout << "The partial key is " << generatePartialKey() << endl;
}

int DHEnpoint::generatePartialKey() {
	int partialKey = pow(k_base, sec);
	partialKey = static_cast<int>(partialKey) % k_mod;
	return partialKey;
}

void DHEnpoint::generateFullKey(const int& outsidePartialKey)
{
	k_full = static_cast<int>(pow(outsidePartialKey, sec)) % k_mod;
}

void DHEnpoint::encryptFile(const string& path) {
	/*
	* 1) ������� ���� �� ���� path
	* 2) ��� ������ ������ ��������� ����������
	* 3) ������� �������������� ������ � ������
	* 4) �������� ������ � �������� ����
	*/

	ifstream source(path, ios_base::in);
	vector<string> encryptedStrings;

	string s;                                 
	while (getline(source, s))
	{
		encryptedStrings.push_back(encryptString(s));
	}
	source.close();

	ofstream receiver(path, ios_base::out | ios_base::trunc);
	for (const auto& s : encryptedStrings) {
		receiver << s << endl;
	}
	receiver.close();
}

string DHEnpoint::encryptString(const string& message) {
	string encryptedMessage = "";
	for (const auto& s : message) {
		encryptedMessage += s ^ k_full;
	}
	return encryptedMessage;
}

