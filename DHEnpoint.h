#pragma once
class DHEnpoint
{
private:
	int pubK1;
	int pubK2;
	int privateKey;
public:
	DHEnpoint(int pubK1, int pupK2, int privateKey);
	int generatePartialKey();
	int generateFullKey(int rPartialKey);
};
