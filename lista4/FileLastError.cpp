#include "pch.h"
#include "FileLastError.h"

FileLastError::FileLastError() {
	this->file = nullptr;
	this->lastError = false;
}

FileLastError::FileLastError(string fileName) {
	this->lastError = false;
	this->file = fopen(fileName.c_str(), "w+");
	if (this->file == nullptr) {
		this->lastError = true;
		return;
	}
}

FileLastError::~FileLastError() {
	if (this->file != nullptr) {
		fclose(this->file);
	}
}

void FileLastError::openFile(string fileName) {
	this->lastError = false;
	this->file = fopen(fileName.c_str(), "w+");
	if (this->file == nullptr) {
		this->lastError = true;
		return;
	}
}

void FileLastError::printLine(string text) {
	this->lastError = false;
	if (this->file != nullptr) {
		fprintf(this->file, text.c_str());
	}
	else {
		this->lastError = true;
		return;
	}
}

void FileLastError::printManyLines(vector<string> text) {
	this->lastError = false;
	if (this->file == nullptr) {
		this->lastError = true;
		return;
	}
	for (int i = 0; i < text.size(); ++i) {
		printLine(text[i]);
		if (this->getLastError()) {
			this->lastError = true;
			return;
		}
	}
}

bool FileLastError::getLastError() {
	return this->lastError;
}

void FileLastError::tryOpen10(string fileName) {
	for (int i = 0; i < 10; ++i) {
		this->openFile(fileName);
		if (!this->getLastError()) {
			return;
		}
	}
}