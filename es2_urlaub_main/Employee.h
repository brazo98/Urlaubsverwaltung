#pragma once
#include <vector>
#include <string>
#include "Urlaub.h"
#include "rlutil.h" //Getch() Methode Quell: https://github.com/tapio/rlutil


using namespace std;

const int URLAUBSTAGE = 30; //Konstante für 30 Tageurlaub
const int URLAUBSTAGE_AB50 = 32; //Konstante für 32 Tageurlaub für >50zig

class Employee {
private:
	int id;
	int vacation;
	string fullname;
	string birth;
	vector<Urlaub> modelUrlaub;
public:
	Employee(int id);
	void addUrlaub(int vacation);

	
	void clearID();
	void changeID(int i);
	void insert();
	

	void tableHeader();

	void display(vector<Employee> &ModelEmp,int line = 3);
	void displayOne(vector<Employee> &ModelEmp, int id, int line=3);

	int getRestUrlaub(vector<Employee> &ModelEmp, int empID);
	void insertUrlaub(vector<Employee> &ModelEmp, int empID, int urlaub);
	int getEmpID();
	void setEmpID(int id);
	void setFullNameandBirth(string fullname, string birth);
	//Routine für die Überprüfung ob das 50zigste Lebensjahr erreicht ist!
	bool proofBirth(string birth);
	//Suchfunktion
	int sucheFullname(vector<Employee> &ModelEmp, string fullname);
	
	string convertToUppcase(string &fullname);
};

