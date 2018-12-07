#include "Row.h"
#include "Vector.h"
#include <string>
#include <iostream>
#include <iomanip>
#pragma once

template <class T>
class Matrix
{

private:
	int rowsCount;
	int columnsCount;
	T **matrix;
	void InitializeMatrix();
	void InitializeMatrix(Vector<T> a, Vector<T> b);

public:
	Matrix();
	Matrix(Vector<T> a, Vector<T> b);
	Row<T> operator[](int index);
	void Print(string matrixName);
	~Matrix();
};

template <class T>
Matrix<T>::Matrix(Vector<T> a, Vector<T> b)
{
	rowsCount = a.Length();
	columnsCount = b.Length() + 1;
	InitializeMatrix(a, b);
}

template <class T>
Matrix<T>::Matrix()
{
	columnsCount = 10;
	rowsCount = 1;
	InitializeMatrix();
}

template <class T>
Row<T> Matrix<T>::operator[](int index)
{
	if (0 <= index && index < rowsCount) {
		return Row<T>(matrix[index], columnsCount);
	}
	else {
		throw std::out_of_range("There is no row with index " + index);
	}
}

template <class T>
void Matrix<T>::Print(string matrixName) {
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

template <class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < rowsCount; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

template <class T>
void Matrix<T>::InitializeMatrix() {
	matrix = new T*[rowsCount];
	for (int i = 0; i < rowsCount; i++) {
		matrix[i] = new int[columnsCount];
	}
}

template <class T>
void Matrix<T>::InitializeMatrix(Vector<T> a, Vector<T> b) {
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
