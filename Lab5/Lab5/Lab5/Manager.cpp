#include "stdafx.h"
#include "Manager.h"


Manager::Manager() : Employee()
{
}

Manager::Manager(string name, string project) : Employee(name)
{
	if (project.empty()) {
		this->Project = this->defaultProject;
	}
	else {
		this->Project = project;
	}
}


string Manager::ToString()
{
	string baseName = Employee::ToString();

	return baseName + "Project: " + this->Project + "\n" + "Subordinates number: " + to_string(this->SubordinatesNumber) + "\n";
}

Manager::~Manager()
{
}
