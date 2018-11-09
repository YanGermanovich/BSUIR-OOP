#pragma once
#include "Employee.h"
class Accountant :
	public Employee
{
public:
	Accountant();
	Accountant(string name, string department = string());
	string ToString();
	string Department;
	bool isMainAccountant = false;
	~Accountant();

private:
	string defauleDepartment = "Main department";
};

