#pragma once
#include "Employee.h"
class Engineer :
	public Employee
{
public:
	Engineer();
	Engineer(string name, string title = string());
	string WorkPC = "Remote";
	string Title;
	string ToString();
	~Engineer();

private:
	string defaultTitle = "No title";
};

