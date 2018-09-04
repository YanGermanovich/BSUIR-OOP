// Lab1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include<iostream>
#include <iomanip>
#include <string>
#include <tuple>

using namespace std;

class Matrix {
private:
	int rowsCount;
	int columnsCount;
	int **matrix;
	bool **isEmpty;
	string notAssigned = "-";
	int maxValueLegth;

	class Row {
	public:
		Row(int* row, int  columnsCount) : row(row) {
			Row::columnsCount = columnsCount;
		}

		int operator[](int index) {
			if (0 <= index && index < columnsCount) {
				return row[index];
			}
			else {
				throw std::out_of_range("There is no column with index " + index);
			}
		}
	private:
		int* row;
		int columnsCount;
	};

	void Finilize() {
		for (int i = 0; i < rowsCount; i++) {
			delete[] matrix[i];
			delete[] isEmpty[i];
		}
		delete[] matrix;
		delete[] isEmpty;
	}

public:
	void SetSize(int rows, int columns) {
		rowsCount = rows;
		columnsCount = columns;
		matrix = new int*[rowsCount];
		isEmpty = new bool*[rowsCount];
		for (int i = 0; i < rowsCount; i++) {
			matrix[i] = new int[columnsCount];
			isEmpty[i] = new bool[columnsCount];
		}
		for (int row = 0; row < rowsCount; row++)
			for (int col = 0; col < columnsCount; col++)
				isEmpty[row][col] = false;
	};

	void Print(string matrixName) {
		cout << matrixName << endl;
		cout << setiosflags(ios::left);
		for (int row = 0; row < rowsCount; row++)
		{
			cout << endl;
			for (int col = 0; col < columnsCount; col++) {
				if (isEmpty[row][col]) {
					cout << setw(maxValueLegth + 3) << matrix[row][col];
				}
				else {
					cout << setw(maxValueLegth + 3) << notAssigned;
				}
			}
			cout << endl;
		}
	};

	void SetElement(int row, int col, int value) {
		if (0 <= row && row < rowsCount) {
			if (0 <= col && col < columnsCount) {
				matrix[row][col] = value;
				isEmpty[row][col] = true;
				if (maxValueLegth < to_string(value).length()) {
					maxValueLegth = to_string(value).length();
				}
			}
			else {
				throw std::out_of_range("There is no column with index " + col);
			}
		}
		else {
			throw std::out_of_range("There is no row with index " + row);
		}
	}

	int RowCount() {
		return rowsCount;
	};

	int ColCount() {
		return columnsCount;
	}

	/// <summary>Gets on of submatrix (matrix divided by center element)</summary>
	/// <param name="subMatrixNumber">1-4. Number of submatrix (rt, lt, rb, lb)</param>  
	/// <returns>Submatrix</returns>  
	Matrix GetSubmatrix(int subMatrixNumber) {
		if (4 < subMatrixNumber || 0 >= subMatrixNumber) {
			std::invalid_argument("matrix number should be in range [1;4]");
		}

		int centerIndex = ((int)columnsCount / 2);
		int resultRowCount = centerIndex;
		int rowShift = 0;
		int colShift = 0;

		if (subMatrixNumber % 2 == 0) {
			colShift = centerIndex + 1;
		}
		if (subMatrixNumber > 2) {
			rowShift = centerIndex + 1;
			resultRowCount = rowsCount - centerIndex - 1;
		}

		Matrix *result = new Matrix();

		result->SetSize(resultRowCount, centerIndex);

		for (int row = 0; row < resultRowCount; row++) {
			for (int col = 0; col < centerIndex; col++) {
				result->SetElement(row, col, matrix[row + rowShift][col + colShift]);
			}
		}

		return *result;
	}

	int& operator()(const unsigned& row, const unsigned& col) {
		return this->matrix[row][col];
	}

	Row operator[](int index) {
		if (0 <= index && index < rowsCount) {
			return Row(matrix[index], columnsCount);
		}
		else {
			throw std::out_of_range("There is no row with index " + index);
		}
	}

	Matrix& operator=(Matrix& rhs) {
		Finilize();

		int  new_rows = rhs.RowCount();
		int new_cols = rhs.ColCount();

		SetSize(new_rows, new_cols);

		for (int i = 0; i < new_rows; i++) {
			for (unsigned j = 0; j < new_cols; j++) {
				matrix[i][j] = rhs[i][j];
				isEmpty[i][j] = true;
			}
		}

		return *this;
	}

	Matrix operator*(Matrix& matr) {
		int rows = matr.RowCount();
		int cols = matr.ColCount();

		if (columnsCount != rows) {
			throw runtime_error("Cannot multiply matrices because columns count of first matrix doen't equal to rows count of second!!!");
		}
		Matrix *result = new Matrix();

		(*result).SetSize(rowsCount, cols);

		for (unsigned i = 0; i < rowsCount; i++) {
			for (unsigned j = 0; j < cols; j++) {
				(*result).SetElement(i, j, 0);
			}
		}
		for (unsigned i = 0; i < rowsCount; i++) {
			for (unsigned j = 0; j < cols; j++) {
				for (unsigned k = 0; k < rows; k++) {
					(*result)(i, j) += (matrix[i][k] * matr(k, j));
				}
			}
		}
		return *result;
	}

	Matrix& operator*=(Matrix& matr) {
		Matrix result = (*this) * matr;
		(*this) = result;
		return *this;
	}

	~Matrix(void) {
		Finilize();
	}
};

class GetValueFromConsole {
public:
	static int GetInt(string key) {
		string errorMessage = "Error: this is not an integer type";
		string retryMessage = "Please reenter the value";
		int result;
		cout << key;
		cin >> result;
		while (cin.fail()) {
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
	string pleaseEnterMessage = "Please enter rows and columns count (integer) for " + matrixName;
	string rowMessage = "Rows:";
	string colMessage = "Columns (should be odd and not bigger than rows): ";
	int rowCount;
	int colCount;

	cout << pleaseEnterMessage << endl;

	rowCount = GetValueFromConsole::GetInt(rowMessage);

	while (rowCount <= 0) {
		rowCount = GetValueFromConsole::GetInt(rowMessage);
	}

	colCount = GetValueFromConsole::GetInt(colMessage);

	while (rowCount < colCount || colCount % 2 == 0 || colCount <= 0) {
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
