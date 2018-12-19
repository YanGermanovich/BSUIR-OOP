// Lab8.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include "Row.h"
#include "Vector.h"
#include "Matrix.h"
#include<iostream>
#include <string>
#include <tuple>
#include <memory>
#include "Transaction.h"

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
	std::auto_ptr<Vector<int>> firstVector(new Vector<int>());

	for (int i = 0; i < firstVectorLength; i++) {
		string message = "[" + to_string(i) + "] = ";
		firstVector->push_back(GetValueFromConsole::GetInt(message));
	}

	cout << "Enter second vector Length:" << endl;
	int secondVectorLength = GetValueFromConsole::GetInt("Length: ");
	std::auto_ptr<Vector<int>> secondVector(new Vector<int>());
	for (int i = 0; i < secondVectorLength; i++) {
		string message = "[" + to_string(i) + "] = ";
		secondVector->push_back(GetValueFromConsole::GetInt(message));
	}

	std::auto_ptr<Matrix<int>> matrix(new Matrix<int>(*firstVector.get(), *secondVector.get()));

	matrix->Print("Result matrix");

	std::auto_ptr<Transaction<Matrix<int>>> transaction(new Transaction<Matrix<int>>());

	Matrix<int>* scope = transaction.get()->BeginTransaction(*matrix.get());

	try {
		scope->ReplaceAll(10);
		matrix.reset(transaction->Commit());
		matrix->Print("New Matrix");
	}
	catch (const std::exception& e) {
		matrix.reset(transaction->Rollback());
	}

	system("pause");
	return 0;
}

