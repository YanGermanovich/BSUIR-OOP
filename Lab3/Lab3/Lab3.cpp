// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Row.h"
#include "Vector.h"
#include "Matrix.h"
#include<iostream>
#include <string>
#include <tuple>

using namespace std;
class GetValueFromConsole {
public:
	static int GetInt(string key) {
		string errorMessage = "Error: this is not an integer type";
		string retryMessage = "Please reenter the value";
		int result;
		cout << key;
		cin >> result;
		while (cin.fail() || cin.peek() != '\n') {
			cout << errorMessage << std::endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << retryMessage << endl;
			cout << key;
			cin >> result;
		}
		return result;
	}
private:
	GetValueFromConsole() {}
};

int main()
{
	cout << "Enter first vector Length:" << endl;
	int firstVectorLength = GetValueFromConsole::GetInt("Length: ");
	Vector* firstVector = new Vector();

	for (int i = 0; i < firstVectorLength; i++) {
		string message = "[" + to_string(i) + "] = ";
		firstVector->push_back(GetValueFromConsole::GetInt(message));
	}

	cout << "Enter second vector Length:" << endl;
	int secondVectorLength = GetValueFromConsole::GetInt("Length: ");
	Vector* secondVector = new Vector();
	for (int i = 0; i < secondVectorLength; i++) {
		string message = "[" + to_string(i) + "] = ";
		secondVector->push_back(GetValueFromConsole::GetInt(message));
	}

	Matrix* matrix = new Matrix(*firstVector, *secondVector);

	matrix->Print("Matrix");

	Matrix* m = (*firstVector) + (*secondVector);

	m->Print("Matrix m");

	delete firstVector;
	delete secondVector;
	delete matrix;

	system("pause");
	return 0;
}

