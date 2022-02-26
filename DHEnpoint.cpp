#include "DHEnpoint.h"
#include <cmath>


DHEnpoint::DHEnpoint(int pubK1, int pubK2, int privateKey) {
	this->pubK1 = pubK1;
	this->pubK2 = pubK2;
	this->privateKey = privateKey;
}

int DHEnpoint::generatePartialKey() {
	int partialKey = pow(pubK1, privateKey);
	partialKey = static_cast<int>(partialKey) % pubK2;
	return partialKey;
}

int DHEnpoint::generateFullKey(int rPartialKey)
{
	int res = static_cast<int>(pow(rPartialKey, privateKey)) % pubK2;
	return res;
}

