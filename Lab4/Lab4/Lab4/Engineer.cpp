#include "stdafx.h"
#include "Engineer.h"


Engineer::Engineer(): Employee()
{
	this->Title = this->defaultTitle;
}

Engineer::Engineer(string name, string title) : Employee(name)
{
	if (title.empty()) {
		this->Title = this->defaultTitle;
	}
	else {
		this->Title = title;
	}
}




string Engineer::ToString()
{
	string baseName = Employee::ToString();

	return baseName + "Title: " + this->Title + "\n" + "Work PC: " + this->WorkPC + "\n";
}

Engineer::~Engineer()
{
}
