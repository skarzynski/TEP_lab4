#pragma once
#pragma warning(disable:4996)

#include <fstream>
#include <vector>

using namespace std;

class FileErrCode {

private:
	FILE* file;         //wska�nik na plik

public:
	FileErrCode();      //konstruktor bezparametrowy
	FileErrCode(string fileName, bool &result); //konstruktor otwieraj�cy plik
	~FileErrCode();               //destruktor

	bool openFile(string fileName); //otwiera plik
	bool printLine(string text);    //wpisuje do pliku lini� tekstu
	bool printManyLines(vector<string> text);   //wpisuje do pliku wiele linii tekstu

	void tryOpen10(string fileName);    //pr�buje otworzy� plik 10 razy

};
