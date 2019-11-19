#pragma once
#pragma warning(disable:4996)

#include<fstream>
#include<vector>

using namespace std;

class FileLastError {

private:
	static bool lastError; //pole okre�laj�ce czy poprzednia operacja zwr�ci�a b��d
	
	
	FILE* file;     //wska�nik na plik

public:
	static bool getLastError();         //zwraca czy ostatnia operacja si� powiod�a

	FileLastError();                    //konstruktor bezparametrowy
	FileLastError(string fileName);     //konstruktor otwieraj�cy plik
	~FileLastError();                   //destruktor

	void openFile(string fileName);     //otwiera plik
	void printLine(string text);        //wpisuje do pliku lini� tekstu
	void printManyLines(vector<string> text);   //wpisuje do pliku wiele linii tekstu

	void tryOpen10(string fileName);    //pr�buje otworzy� plik 10 razy

};