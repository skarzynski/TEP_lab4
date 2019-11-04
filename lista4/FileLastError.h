#pragma once
#pragma warning(disable:4996)

#include<fstream>
#include<vector>

using namespace std;

class FileLastError {

private:
	FILE* file;     //wskaŸnik na plik
	bool lastError; //pole okreœlaj¹ce czy poprzednia operacja zwróci³a b³¹d

public:
	FileLastError();                    //konstruktor bezparametrowy
	FileLastError(string fileName);     //konstruktor otwieraj¹cy plik
	~FileLastError();                   //destruktor

	void openFile(string fileName);     //otwiera plik
	void printLine(string text);        //wpisuje do pliku liniê tekstu
	void printManyLines(vector<string> text);   //wpisuje do pliku wiele linii tekstu

	bool getLastError();                //zwraca czy ostatnia operacja siê powiod³a

	void tryOpen10(string fileName);    //próbuje otworzyæ plik 10 razy

};