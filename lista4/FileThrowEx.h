#pragma once
#pragma warning(disable:4996)

#include <fstream>
#include <vector>

using namespace std;

class FileThrowEx {

private:
	FILE* file;                     //wska�nik na plik

public:
	FileThrowEx();                  //konstruktor bezparametrowy
	FileThrowEx(string fileName);   //konstruktor otwieraj�cy plik
	~FileThrowEx();                 //destruktor

	void openFile(string fileName); //otwiera plik
	void printLine(string text);    //wpisuje do pliku lini� tekstu
	void printManyLines(vector<string> text);   //wpisuje do pliku wiele linii tekstu

	void tryOpen10(string fileName);    //pr�buje otworzy� plik 10 razy

};