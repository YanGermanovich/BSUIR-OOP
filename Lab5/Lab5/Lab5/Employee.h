#include <string>

using namespace std;
#pragma once
class Employee
{
public:
	Employee();
	Employee(string name);
	virtual string ToString() = 0;
	string Salary = "Start salary";// Can be in conventional units (ex. 3 kg of meat)
	~Employee();
private:
	string name;
	string defaultName = "Eployee name";
};



