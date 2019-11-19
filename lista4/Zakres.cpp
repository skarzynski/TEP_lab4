#include <string>

#include "pch.h"
#include "Zakres.h"

using namespace std;

bool Zakres::lastError;

bool Zakres::getLastError() {
	return Zakres::lastError;
}

Zakres::Zakres() {
	this->from = -1;
	this->to = -1;
	this->value = -1;
	lastError = false;
}

Zakres::Zakres(string value, int from, int to) {
	lastError = false;
	this->from = from;
	this->to = to;
	for (int i = 0; i < value.length(); i++) {
		if (!isdigit(value[i])) {
			lastError = true;
			this->value = -1;
			return;
		}
	}
	int correctValue = atoi(value.c_str());
	if (correctValue >= from && correctValue <= to) {
		this->value = correctValue;
	}
	else {
		lastError = true;
		this->value = -1;
		return;
	}
}

Zakres::Zakres(char* value, int from, int to) {
	lastError = false;
	this->from = from;
	this->to = to;
	char* copy;
	for (copy = value; *value != '\0'; copy++) {
		if (!isdigit(*value)) {
			lastError = true;
		}
	}
	if (this->getLastError()) {
		this->value = -1;
		return;
	}
	int correctValue = atoi(value);
	if (correctValue >= from && correctValue <= to) {
		this->value = correctValue;
	}
	else {
		lastError = true;
		this->value = -1;
		return;
	}
}

int Zakres::getValue() {
	return this->value;
}


Zakres & Zakres::operator=(const string &newValue) {
	lastError = false;
	for (int i = 0; i < newValue.length(); i++) {
		if (!isdigit(newValue[i])) {
			lastError = true;
			return *this;
		}
	}
	int correctValue = atoi(newValue.c_str());
	if (correctValue < this->from || correctValue > this->to) {
		lastError = true;
		return *this;
	}
	this->value = correctValue;
	return *this;
}


Zakres & Zakres::operator=(const Zakres &newValue) {
	lastError = false;
	this->from = newValue.from;
	this->to = newValue.to;
	this->value = newValue.value;
	return *this;
}