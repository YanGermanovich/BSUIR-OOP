#include "stdafx.h"
#include "Employee.h"
#include <string>

using namespace std;
Employee::Employee()
{
}

Employee::Employee(string name)
{
	if (name.empty()) {
		this->name = defaultName;
	}
	else {
		this->name = name;
	}
}

string Employee::ToString()
{
	return "Name: " + this->name + "\n" + "Salary: " + this->Salary + "\n";
}

Employee::~Employee()
{
	this->name = this->defaultName;
}


