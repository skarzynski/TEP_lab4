// lista4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>

#include "pch.h"
#include "FileLastError.h"
#include "FileThrowEx.h"
#include "FileErrCode.h"

using namespace std;

int main()
{
	FileLastError fle("test");
	vector<string> vector;
	vector.push_back("qqq");
	vector.push_back("www");
	vector.push_back("eee");
	//fle->openFile("test");
	//fle.printLine("rrr");
	fle.printManyLines(vector);
	printf("%d \n",fle.getLastError());
	//cout << fle.getLastError() << endl;

	FileThrowEx fte("test2");
	//fte.openFile("test2");
	//fte.printLine("rrr");
	fte.printManyLines(vector);

	FileErrCode fec("test3");
	//fec.openFile("test3");
	//cout << fec.printLine("rrr") << endl;
	printf("%d \n", fec.printManyLines(vector));
	//cout << fec.printManyLines(vector) << endl;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
