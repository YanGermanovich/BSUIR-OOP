// Lab1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include<iostream>
#include <iomanip>
#include <string>
#include <tuple>
#include "Matrix.h"

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

	static bool GetBool() {
		string errorMessage = "Error: this is not a bool type";
		string retryMessage = "Please reenter the value";
		string validChars = "YyNn";
		char result;
		cin >> result;

		while (cin.fail() || validChars.find(result) == std::string::npos) {
			cout << errorMessage << std::endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << retryMessage << endl;
			cin >> result;
		}
		if (validChars.find(result) > 1) {
			return false;
		}
		else {
			return true;
		}
	}

	static void FillMatrix(Matrix* matrix, string matrixName, int rowCount, int colCount) {
		system("cls");
		for (int row = 0; row < rowCount; row++) {
			for (int col = 0; col < colCount; col++) {
				matrix->Print(matrixName);

				matrix->SetElement(row, col, GetInt(matrixName + "[" + to_string(row) + "][" + to_string(col) + "]: "));
				system("cls");
			}
		}
	}
private:
	GetValueFromConsole() {}
};

void SizeMatrix(Matrix* matrix, string matrixName) {
	string pleaseEnterMessage = "Please enter rows and columns count (integer > 2) for " + matrixName;
	string rowMessage = "Rows:";
	string colMessage = "Columns (should be odd and not bigger than rows): ";
	string errMessage = "Error, please reenter the value!";
	int rowCount;
	int colCount;

	cout << pleaseEnterMessage << endl;

	rowCount = GetValueFromConsole::GetInt(rowMessage);

	while (rowCount <= 2) {
		cout << errMessage << endl;
		rowCount = GetValueFromConsole::GetInt(rowMessage);
	}

	colCount = GetValueFromConsole::GetInt(colMessage);

	while (rowCount < colCount || colCount % 2 == 0 || colCount <= 2) {
		cout << errMessage << endl;
		colCount = GetValueFromConsole::GetInt(colMessage);
	}

	matrix->SetSize(rowCount, colCount);
}

void main()
{
	Matrix *matrixA = new Matrix();
	Matrix *matrixB = new Matrix();

	SizeMatrix(matrixA, "first matrix");
	SizeMatrix(matrixB, "second matrix");


	GetValueFromConsole::FillMatrix(matrixA, "first matrix", matrixA->RowCount(), matrixA->ColCount());
	GetValueFromConsole::FillMatrix(matrixB, "second matrix", matrixB->RowCount(), matrixB->ColCount());

	matrixA->Print("First matrix");

	matrixB->Print("Second matrix");

	Matrix matrixA1 = matrixA->GetSubmatrix(1);
	matrixA1.Print("A1 matrix");

	Matrix matrixB4 = matrixB->GetSubmatrix(4);
	matrixB4.Print("B4 matrix");

	Matrix resulteA1B4 = matrixA1 * matrixB4;
	resulteA1B4.Print("A1*B4 matrix");

	matrixA1 *= matrixB4;
	matrixA1.Print("A1*=B4 matrix");

	system("pause");
}
