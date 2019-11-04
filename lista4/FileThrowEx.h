#pragma once
#pragma warning(disable:4996)

#include <fstream>
#include <vector>

using namespace std;

class FileThrowEx {

private:
	FILE* file;                     //wskaŸnik na plik

public:
	FileThrowEx();                  //konstruktor bezparametrowy
	FileThrowEx(string fileName);   //konstruktor otwieraj¹cy plik
	~FileThrowEx();                 //destruktor

	void openFile(string fileName); //otwiera plik
	void printLine(string text);    //wpisuje do pliku liniê tekstu
	void printManyLines(vector<string> text);   //wpisuje do pliku wiele linii tekstu

	void tryOpen10(string fileName);    //próbuje otworzyæ plik 10 razy

};