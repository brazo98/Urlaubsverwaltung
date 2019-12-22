#include "Urlaub.h"
#include <vector>
#include <string>
#include "rlutil.h" //Getch() Methode Quell: https://github.com/tapio/rlutil


//Zusätliche Klasse für die Urlaubstage
//Kann jetzt beliebig erweitert werden diese Klasse wird nach Prinzip
//der Gang of four in der Employee instanziert Erbauerprinzip!
//Somit hat der User da nicht viel am Hut damit!
Urlaub::Urlaub(int id, int verbrauchteUrlaub)//Konstruktor
{
	//Weitergabe der Daten
	this->id = id;
	this->verbrauchteUrlaubstage = verbrauchteUrlaub;
}
//Methode für die retourinierung der Daten
int Urlaub::GetverbrauchteUrlaubstage()
{
	return this->verbrauchteUrlaubstage;
}
//Methode zum setzen des Urlaubes
void Urlaub::addVerUrlaubstage(int urlaub)
{
	this->verbrauchteUrlaubstage  += urlaub;
}

