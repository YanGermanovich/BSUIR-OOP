// Lab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Accountant.h";
#include "Employee.h";
#include "Engineer.h";
#include "Manager.h";
#include "iostream"

int main()
{
	cout << "Enter name of accountant One: ";

	string nameAccountant;
	cin >> nameAccountant;

	cout << "Enter department of accountant One: ";

	string departmentAccountant;
	cin >> departmentAccountant;

	Employee* accountantOne = new Accountant(nameAccountant, departmentAccountant);

	cout << accountantOne->ToString() << endl;

	cout << "Enter name of Engineer One: ";

	string nameEngineer;
	cin >> nameEngineer;

	cout << "Enter title of Engineer One: ";

	string titleEngineer;
	cin >> titleEngineer;

	Employee* engineerOne = new Engineer(nameEngineer, titleEngineer);

	cout << engineerOne->ToString() << endl;

	cout << "Enter name of Manager One: ";

	string nameManager;
	cin >> nameManager;

	cout << "Enter project of Manager One: ";

	string projectManager;
	cin >> projectManager;

	Employee* managerOne = new Manager(nameManager, projectManager);

	cout << managerOne->ToString() << endl;

	delete accountantOne;
	delete engineerOne;
	delete managerOne;

	system("pause");
	return 0;
}

