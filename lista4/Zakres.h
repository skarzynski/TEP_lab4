#pragma once
#pragma warning(disable:4996)

#include <iostream>

using namespace std;

class Zakres {

private:
	static bool lastError;			//pole okresślające czy poprzednia operacja zwróciła błąd


	int from;				//początek zakresu
	int to;					//koniec zakresu
	int value;				//wartość obiektu klasy
	
public:
	static bool getLastError() { return(lastError); }						//zwraca czy ostatnia operacja się powiodła


	Zakres();				//konstruktor  bezparametrowy
	Zakres(string value, int from, int to);		//konstruktor próbujący przekonwertować ciąg znaków na l. całkowitą
	Zakres(char* value, int from, int to);		//konstruktor próbujący przekonwertować ciąg znaków (przekazany za pomocą wskaźnika) na l. całkowitą

	int getValue();								//zwraca wartość pola value

	Zakres &operator = (const string &newValue);	//operator przypisania (wartość)
	Zakres &operator = (const Zakres &newValue);	//operator przypisania (obiekt)

};