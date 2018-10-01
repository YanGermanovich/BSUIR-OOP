#include "Row.h"
#include "Vector.h"

#pragma once
class Matrix
{

private:
	int rowsCount;
	int columnsCount;
	int **matrix;
	void InitializeMatrix();
	void InitializeMatrix(Vector a, Vector b);

public:
	Matrix();
	Matrix(Vector a, Vector b);
	Row operator[](int index);
	void Print(string matrixName);
	~Matrix();
};