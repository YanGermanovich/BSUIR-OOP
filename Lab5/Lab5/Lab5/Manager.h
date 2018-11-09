#pragma once
#include "Employee.h"
class Manager :
	public Employee
{
public:
	Manager();
	Manager(string name, string project = string());
	string Project;
	int SubordinatesNumber = 0;
	string ToString();
	~Manager();
private:
	string defaultProject = "Main project";
};

