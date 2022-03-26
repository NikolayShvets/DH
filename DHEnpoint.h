#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class DHEnpoint
{
private:
	int k_base;
	int k_mod;
	int sec;
	int k_full;
public:
	DHEnpoint(int sec, int k_base, int k_mod);
	int generatePartialKey();
	void generateFullKey(const int& outsidePartialKey);
	void encryptFile(const string& path);
	string encryptString(const string& message);
};
