#pragma once
#include <vector>
#include <string>
#include "rlutil.h" //Getch() Methode Quell: https://github.com/tapio/rlutil
using namespace std;

//Datenklasse f�r die Urlaubstage
class Urlaub {
private: //Datenkapselung
	int id;
	unsigned int verbrauchteUrlaubstage;

public:
	//Konstruktor
	Urlaub(int id, int verbrauchteUrlaub);
	int GetverbrauchteUrlaubstage();//Methode f�r die R�ckgabe 
	void addVerUrlaubstage(int urlaub); //Methode f�r das hinzuf�gen des Urlaubstage!
};