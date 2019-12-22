/*
Author: Toni Mikitsch
Aufgabe: WS19/20: ESA2 Zweite Einsendeaufgabe 
(Urlaubsverwaltung)
ESA2 (Leistungsnachweis) zum vhb-Kurs "C++ Teil1"
Datum: 20.11.2019
Erstelldatum 19.11.2019
Änderungsdatum: 20.11.2019
Name-Datei: esa2_urlaub.cpp
Version: 1.0
*/

/*README
Sie sollen ein Programm zur Urlaubsverwaltung in C++ realisieren.
Schreiben Sie ein C++-Programm nach objektorientierten Grundsätzen (das
Programm muss eine oder mehrere Klassen enthalten), das mindestens
folgenden Sachverhalt abdeckt.

Ausgangssituation: 
Sie wollen ein Programm zur Verwaltung des Urlaubs der Mitarbeiter an Ihrer
Hochschule erstellen.
Jeder Mitarbeiter hat 30 Tage.
Mitarbeiter, die zum 01.01.des laufenden Kalenderjahrs das 50 Lebensjahr bereits vollendet haben, erhalten 32 Tage Urlaub.
Von jedem Mitarbeiter wird gespeichert:
Name
Vorname
Geburtsdatum
Bereits in Anspruch genommener Urlaub
Bei Programmstart ist die „Datenbank“ der Urlaubsverwaltung leer, die Daten müssen erst eingegeben werden. Die Daten müssen nur während der Laufzeit verfügbar sein (keine permanente Speicherung nötig!).

Aufgabe:
Das Programm muss folgendes leisten:
Verwaltung von maximal 500 Mitarbeitern
Anlegen und Löschen eines Mitarbeiters
Eingabe der Tage, wenn der Mitarbeiter Urlaub nehmen möchte  (muss mehrfach möglich sein)
Suche eines Mitarbeiters mit Ausgabe seiner Daten und wie viel Resturlaub er noch hat.
Auflistung aller gespeicherten Mitarbeiterdaten

*/

#include <iostream> 
#include <conio.h>   
#include "Employee.h" //Klasse für Datenspeicherung
#include <vector> //Vectorbibliothek für das Model
#include <string> //String Bibliothek für Stringbearbeitug
#include "rlutil.h" //Getch() Methode Quell: https://github.com/tapio/rlutil
#include <algorithm> //Für die Iteratoren    



using namespace std;

//Model
vector<Employee> ModelEmp;
vector<Employee> tempModelEmp;


//Sortierroutine für mein Model
void sortEmployee(){
	
	if(ModelEmp.size()>0){
		tempModelEmp.clear();
		for(unsigned int i=0; i < ModelEmp.size();i++){
			ModelEmp[i].changeID(i+1);
			tempModelEmp.insert(tempModelEmp.begin(),ModelEmp[i]);
		}
	}
	
}

int main(){
	Employee *emp;
	//Ein paar lokale Variablen zur Zwischenspeicherung für die Weiterleitung an die Employeeklasse
	unsigned int  id = 0, urlaub = 0;
	string fullname = "";
	string birth;
	string suchname="";

	do{

		
		//Mein neues Dashboard
		system("cls");
		gotoxy(29, 2);  cout << "=====UrlaubsverwaltungTHD=====";
		gotoxy(29, 3);  cout << "1. Einfuegen                   ";
		gotoxy(29, 4);  cout << "2. Editieren/Updaten          ";
		gotoxy(29, 5);  cout << "3. Loeschen                    ";
		gotoxy(29, 6);  cout << "4. Suchen                     ";
		gotoxy(29, 7);  cout << "5. Urlaubserfassung           ";
		gotoxy(29, 8);  cout << "6. Anzeigen                   ";
		gotoxy(29, 9);  cout << "7. THD                        ";
		gotoxy(29, 10); cout << "8. Quit                       ";
		gotoxy(29, 11); cout << "==============================";

		char menu;
	repeat:
		gotoxy(29, 13);
		cout << "Ihre Auswahl: ";
		menu = getch();
		//Switchroutine für die Abfrage der Auswahl
		switch (menu){
			
		
			case '1': //Insert Routine
				//Hier erfolgt die dynamische Instanzierung der Klasse Employee
				emp = new Employee(ModelEmp.size()+1);
				system("cls");
				emp->insert();//
				ModelEmp.insert(ModelEmp.end(), *emp); //speicherung der Objektinstanz in das Vectormodel
				system("cls");
				ModelEmp[0].tableHeader(); //Ausgabe des Headers
				ModelEmp[0].display(ModelEmp); //Anzeige der eingegebenen Daten
				
				system("pause");
				delete emp;
				break;
			case '2': //Änderung und Updateroutine
				system("cls");
				if (!ModelEmp.empty()){
					ModelEmp[0].tableHeader();
					ModelEmp[0].display(ModelEmp);
					cout << "Welche ID moechte Sie aendern?: \n"; cin >> id;
					system("cls");
					ModelEmp[0].tableHeader();
					ModelEmp[0].displayOne(ModelEmp,id-1);
					cout << "Fullname: \n"; cin.seekg(0, ios::end);
					cin.clear();
					getline(cin,fullname);
					cout << "Birthday: \n"; cin.seekg(0, ios::end);
					cin.clear();
					getline(cin, birth);
					ModelEmp[id-1].setFullNameandBirth(fullname, birth);
					system("cls");
					ModelEmp[id-1].tableHeader();
					ModelEmp[id-1].displayOne(ModelEmp,id-1);
				}
				system("pause");
				break;
			case '3': //Löschroutine
				
				system("cls");
				if (!ModelEmp.empty()){
					ModelEmp[0].tableHeader();
					ModelEmp[0].display(ModelEmp);
					cout << "Welche ID moechte Sie entfernen?: \n"; cin >> id;
					ModelEmp.erase(ModelEmp.begin() + (id-1)); //Wird aus dem Model gelöscht an dieser Stelle ID-1
					sortEmployee();
					system("cls");
					if (!ModelEmp.empty()){
						ModelEmp[0].tableHeader();
						ModelEmp[0].display(ModelEmp);
					}
				}else if (ModelEmp.empty()){
					ModelEmp.clear();
					system("cls");
				}
							
				system("pause");
				
				break;
			case '4':  //Suchroutine
				system("cls");
				if (!ModelEmp.empty()){
					ModelEmp[0].tableHeader();
					ModelEmp[0].display(ModelEmp);
					cout << "Bitte geben Sie den Suchnamen ein: \n"; cin >> suchname;
					
					id = ModelEmp[0].sucheFullname(ModelEmp, suchname);//Suchroutine wird in der Klasse Employee los gekickt!
					system("cls");
					if(id != 0){
						ModelEmp[id-1].tableHeader();
						ModelEmp[id-1].displayOne(ModelEmp,id-1);
					}
				}
				system("pause");
				break;
			case '5': //Urlaubserfassungsroutine
				system("cls");
				if (!ModelEmp.empty()){
					ModelEmp[0].tableHeader();
					ModelEmp[0].display(ModelEmp);
					cout << "Bitte geben Sie die ID ein: \n"; cin >> id;
					cout << "Bitte geben Sie die Anzahl Urlaubstage ein: \n"; cin >> urlaub;
					

					ModelEmp[(id-1)].addUrlaub(urlaub); //Auch diese Routine wird in der Klasse Employee los gekickt!
					system("cls");
					
					ModelEmp[(id-1)].tableHeader();
					ModelEmp[(id-1)].display(ModelEmp);
					
				}
				system("pause");

				break;
			case '6': // Komplette Datensätze anzeigen
				system("cls");
				if (!ModelEmp.empty()){
					ModelEmp[0].tableHeader();
					ModelEmp[0].display(ModelEmp);
				}
				system("pause");
				break;
			case '7': //About THD
				cout << "THD Angewandte Informatik www.thg.de\n";
				system("pause");
				break;
			case '8': //Exit Ausgang aus dem Programm
				cout << "Auswahl 8";
				exit(0);

			default:
				gotoxy(29, 15);  cout << "Falsche Eingabe";
				getch(); gotoxy(29, 15); system("cls");
				goto repeat;
		}

	}while(true); //Wird wiederholt bis case:8 kommt!
	system("pause");
	return 0;
}