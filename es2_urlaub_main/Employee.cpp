#include <iostream>  
#include <conio.h>   
#include "Employee.h"
#include <vector>
#include <string>
#include "rlutil.h" //Getch() Methode Quell: https://github.com/tapio/rlutil
#include <time.h>
#include <sstream>
#include <ctype.h>
#include <cstring>
#include <cstdio>

using namespace std;

//Konstruktor zur Instanzierung nach Gang of 4!Builder Pattern!
Employee::Employee(int id){
	 this->id = id;
	 //Instanzierung der Klasse Urlaub wo die Daten für die Urlaubserfassung erfolgt
	 Urlaub url(id, 0);
	 modelUrlaub.insert(modelUrlaub.end(), url); //Das Model ist in der Employee Klasse somit Voll im Zugriff
	
}
//Methode für Umwandlung in GROSSBUCHSTABEN
string Employee::convertToUppcase(string &fullname){
	for(unsigned int i=0; i<fullname.length(); i++){
		fullname[i] = toupper(fullname[i]);
	}

	return fullname;
}


//Suchmethode
int Employee::sucheFullname(vector<Employee> &ModelEmp, string fullname){
	int idx=0;
	string searchName=fullname;
	string modelSuche="";
	
	try
	{
		for (unsigned int i = 0; i < ModelEmp.size(); i++)
		{
			modelSuche = ModelEmp[i].fullname;
			modelSuche = convertToUppcase(modelSuche);
			idx = modelSuche.find(convertToUppcase(searchName));
		
			if (idx >= 0){
				return ModelEmp[i].getEmpID();
			}
		 
		}
		
	}
	catch (const std::exception&)
	{
		cout << "Fehler passiert in Funktion SucheFullname\n";
	}

	return 0;
}
//Methode zum überprüfen ob jemand bereits das 50zigste Lebensjahr erreicht hat
bool Employee::proofBirth(string birth){
	int uFunf=50;
	int idx=0;
	int jahr=0;
	string _birth=birth;
	string extractYear="";

	try{
	
		idx = _birth.rfind(".");
		extractYear =_birth.substr(idx+1,99999);

		time_t Zeitstempel;
		tm *nun;
		Zeitstempel = time(0);
		if (localtime != NULL){
			nun = localtime(&Zeitstempel);
			
			istringstream inStream(extractYear);
			inStream >> jahr;
			
			jahr = nun->tm_year+1900-jahr;
			
			if ( jahr >= uFunf){
				return true;
			}else return false;
		}
	}catch(const std::exception&){
		cout << "Fehler passiert in proofBirth Funktion: \n";
		return false;
	}
	return false;
}
//Methode zur Retourgabe der ID
int Employee::getEmpID(){
	return id;
}
//Setzmethode
void Employee::setEmpID(int id){
	this->id = id;
}
//Methode für das Ändern der ID
void Employee::changeID(int i){
	this->id=i;
}
//Methode zum löschen der ID
void Employee::clearID(){
	id=0;
}
//Methode zum setzen des fullname und geburtsdatum
void Employee::setFullNameandBirth(string fullname, string birth){
	this->fullname = fullname;
	this->birth = birth;
}

//Methode für das hochzählen des Urlaubes
void Employee::addUrlaub(int vacation){
	this->modelUrlaub[0].addVerUrlaubstage(vacation);
}

//Methode für das abfüllen fullname und birthday in der Mainroutine
void Employee::insert()
{
	cout << "Fullname: \n"; cin.seekg(0, ios::end);
	cin.clear();
	getline(cin,fullname);


	cout << "Birthday: \n"; cin.seekg(0, ios::end);
	cin.clear();
	getline(cin, birth);
}
//Methode für die Headerausgabe
void Employee::tableHeader()
{
	gotoxy(1, 1);
	cout << "ID";
	gotoxy(10, 1);
	cout << "Full Name";
	gotoxy(30, 1);
	cout << "Birthday";
	gotoxy(50, 1);
	cout << "Vacation";

	for (int i = 0; i < 80; i++) {
		gotoxy(i, 2);
		cout << "-";
	}

}
//Methode für die Ausgabe eines Tupel
void Employee::displayOne(vector<Employee> &ModelEmp, int id, int line)
{
	long temp = 0;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(2);
	
	try
	{
			
		gotoxy(1, line + id);
		cout << ModelEmp[id].id;
		gotoxy(10, line + id);
		cout << ModelEmp[id].fullname;
		gotoxy(30, line + id);
		cout << ModelEmp[id].birth;
		gotoxy(50, line + id);


		if (proofBirth(ModelEmp[id].birth)==true){
			cout << (URLAUBSTAGE_AB50 - (ModelEmp[id].modelUrlaub[0].GetverbrauchteUrlaubstage())) << endl;
		}else{
			cout << (URLAUBSTAGE - (ModelEmp[id].modelUrlaub[0].GetverbrauchteUrlaubstage())) << endl;
		}
	
	}
	catch (const std::exception&)
	{
		cout << "Fehler passiert Funktion displayOne\n";
	}


}
//Methode für die Ausgabe aller Tupel
void Employee::display(vector<Employee> &ModelEmp, int line)
{
	long temp = 0;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(2);

	try
	{
		for (unsigned int i = 0; i < ModelEmp.size(); i++)
		{
			gotoxy(1, line + i);
			cout << ModelEmp[i].getEmpID();
			gotoxy(10, line + i);
			cout << ModelEmp[i].fullname;
			gotoxy(30, line + i);
			cout << ModelEmp[i].birth;
			gotoxy(50, line + i);


		
			if (proofBirth(ModelEmp[i].birth)==true){
				cout << (URLAUBSTAGE_AB50 - (ModelEmp[i].modelUrlaub[0].GetverbrauchteUrlaubstage())) << endl;
			}else{
				cout << (URLAUBSTAGE - (ModelEmp[i].modelUrlaub[0].GetverbrauchteUrlaubstage())) << endl;
			}

		}

		
	}
	catch (const std::exception&)
	{
		cout << "Fehler passiert in Funktion Display\n";
	}
	

}
//Methode für das retounieren des Resturlaubes
int Employee::getRestUrlaub(vector<Employee> &ModelEmp, int empID)
{
	try
	{
		return ModelEmp[empID].modelUrlaub[0].GetverbrauchteUrlaubstage();
		
	}
	catch (const std::exception&)
	{
		cout << "Fehler passiert in Funktion getRestUrlaub";
	}
	return 0;
}
//Methode für das manipulieren des Urlaubes direkt im Model
void Employee::insertUrlaub(vector<Employee> &ModelEmp, int empID, int urlaub)
{
	try
	{
		ModelEmp[empID].modelUrlaub[0].addVerUrlaubstage(urlaub);
	}
	catch (const std::exception&)
	{
		cout << "Fehler passiert in Funktion insertUrlaub\n";
	}
	
}















