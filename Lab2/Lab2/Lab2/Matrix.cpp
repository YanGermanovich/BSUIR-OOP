#include "stdafx.h"
#include "Matrix.h"
#include "Vector.h"
#include<iostream>
#include <string>
#include <iomanip>

using namespace std;

Matrix::Matrix(Vector a, Vector b)
{
	rowsCount = a.Length();
	columnsCount = b.Length() + 1;
	InitializeMatrix(a,b);
}


Matrix::Matrix()
{
	columnsCount = 10;
	rowsCount = 1;
	InitializeMatrix();
}

Row Matrix::operator[](int index)
{
	if (0 <= index && index < rowsCount) {
		return Row(matrix[index], columnsCount);
	}
	else {
		throw std::out_of_range("There is no row with index " + index);
	}
}

void Matrix::Print(string matrixName) {
	cout << matrixName << endl;
	cout << setiosflags(ios::left);
	for (int row = 0; row < rowsCount; row++)
	{
		cout << endl;
		for (int col = 0; col < columnsCount; col++) {
			cout << setw(3) << matrix[row][col];
		}
		cout << endl;
	}
};


Matrix::~Matrix()
{
	for (int i = 0; i < rowsCount; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Matrix::InitializeMatrix() {
	matrix = new int*[rowsCount];
	for (int i = 0; i < rowsCount; i++) {
		matrix[i] = new int[columnsCount];
	}
}

void Matrix::InitializeMatrix(Vector a, Vector b) {
	InitializeMatrix();
	for (int row = 0; row < rowsCount; row++) {
		matrix[row][0] = a[row];
	}
	for (int col = 0; col < columnsCount - 1; col++) {
		matrix[0][col + 1] = b[col];
	}
	for (int row = 1; row < rowsCount; row++) {
		for (int col = 1; col < columnsCount; col++) {
			matrix[row][col] = matrix[row][0] * matrix[0][col];
		}
	}
}
