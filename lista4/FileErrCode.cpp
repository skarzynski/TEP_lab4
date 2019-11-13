#include "pch.h"
#include "FileErrCode.h"

FileErrCode::FileErrCode() {
	this->file = nullptr;
}

FileErrCode::FileErrCode(string fileName, bool &result) {
	this->file = fopen(fileName.c_str(), "w+");
	if (this->file == nullptr) {
		result = false;
	}
	result = true;
}

FileErrCode::~FileErrCode() {
	if (this->file != nullptr) {
		fclose(this->file);
	}
}

bool FileErrCode::openFile(string fileName) {
	this->file = fopen(fileName.c_str(), "w+");
	if (this->file == nullptr) {
		return false;
	}
	return true;
}

bool FileErrCode::printLine(string text) {
	if (this->file == nullptr) {
		return false;
	}
	fprintf(this->file, text.c_str());
	return true;
}

bool FileErrCode::printManyLines(vector<string> text) {
	if (this->file == nullptr) {
		return false;
	}
	for (int i = 0; i < text.size(); ++i) {
		if (!printLine(text[i])) {
			return false;
		}
	}
	return true;
}

void FileErrCode::tryOpen10(string fileName) {
	for (int i = 0; i < 10; ++i) {
		if (this->openFile(fileName)) {
			return;
		}
	}
}