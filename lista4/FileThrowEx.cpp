#include <iostream>

#include "pch.h"
#include "FileThrowEx.h"

using namespace std;

FileThrowEx::FileThrowEx() {
	this->file = nullptr;
}

FileThrowEx::FileThrowEx(string fileName) {
	this->file = fopen(fileName.c_str(), "w+");
	if (this->file == nullptr) {
		throw 1;
	}
}

FileThrowEx::~FileThrowEx() {
	if (this->file != nullptr) {
		fclose(this->file);
	}
}

void FileThrowEx::openFile(string fileName) {
	this->file = fopen(fileName.c_str(), "w+");
	if (this->file == nullptr) {
		throw 1;
	}
}

void FileThrowEx::printLine(string text) {
	if (this->file != nullptr) {
		fprintf(this->file, text.c_str());
	}
	else {
		throw 1;
	}
}

void FileThrowEx::printManyLines(vector<string> text) {
	if (this->file == nullptr) {
		throw 1;
	}
	for (int i = 0; i < text.size(); ++i) {
		try {
			printLine(text[i]);
		}
		catch (int e) {
			printf("Exception: %d", e);
			//cout << "Exception: " << e << endl;
		}

	}
}

void FileThrowEx::tryOpen10(string fileName) {
	for (int i = 0; i < 10; ++i) {
		try {
			this->openFile(fileName);
			return;
		}
		catch (int e) {
			printf("Exception: %d", e);
			//cout << "Exception: " << e << endl;
		}

	}
}