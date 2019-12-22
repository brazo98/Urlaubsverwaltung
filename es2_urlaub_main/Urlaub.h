#pragma once
#include <vector>
#include <string>
#include "rlutil.h" //Getch() Methode Quell: https://github.com/tapio/rlutil
using namespace std;

//Datenklasse für die Urlaubstage
class Urlaub {
private: //Datenkapselung
	int id;
	unsigned int verbrauchteUrlaubstage;

public:
	//Konstruktor
	Urlaub(int id, int verbrauchteUrlaub);
	int GetverbrauchteUrlaubstage();//Methode für die Rückgabe 
	void addVerUrlaubstage(int urlaub); //Methode für das hinzufügen des Urlaubstage!
};