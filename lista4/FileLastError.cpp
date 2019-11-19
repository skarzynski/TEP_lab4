#include "pch.h"
#include "FileLastError.h"

bool FileLastError::lastError;

bool FileLastError::getLastError() {
	return FileLastError::lastError;
}

FileLastError::FileLastError() {
	this->file = nullptr;
	lastError = false;
}

FileLastError::FileLastError(string fileName) {
	lastError = false;
	this->file = fopen(fileName.c_str(), "w+");
	if (this->file == nullptr) {
		lastError = true;
		return;
	}
}

FileLastError::~FileLastError() {
	if (this->file != nullptr) {
		fclose(this->file);
	}
}

void FileLastError::openFile(string fileName) {
	lastError = false;
	this->file = fopen(fileName.c_str(), "w+");
	if (this->file == nullptr) {
		lastError = true;
		return;
	}
}

void FileLastError::printLine(string text) {
	lastError = false;
	if (this->file != nullptr) {
		fprintf(this->file, text.c_str());
	}
	else {
		lastError = true;
		return;
	}
}

void FileLastError::printManyLines(vector<string> text) {
	lastError = false;
	if (this->file == nullptr) {
		lastError = true;
		return;
	}
	for (int i = 0; i < text.size(); ++i) {
		printLine(text[i]);
		if (getLastError()) {
			lastError = true;
			return;
		}
	}
}

void FileLastError::tryOpen10(string fileName) {
	for (int i = 0; i < 10; ++i) {
		this->openFile(fileName);
		if (!getLastError()) {
			return;
		}
	}
}