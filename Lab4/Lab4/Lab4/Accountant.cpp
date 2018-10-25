#include "stdafx.h"
#include "Accountant.h"


Accountant::Accountant() : Employee()
{
	this->Department = this->defauleDepartment;
}

Accountant::Accountant(string name, string department ) : Employee(name)
{
	if (department.empty()) {
		this->Department = this->defauleDepartment;
	}
	else {
		this->Department = department;
	}
}


string Accountant::ToString()
{
	string baseName = Employee::ToString();

	return baseName + "Department: " + this->Department + "\n" + "Main accountant: " + (this->isMainAccountant ? "true" : "false") + "\n";
}

Accountant::~Accountant()
{
}



