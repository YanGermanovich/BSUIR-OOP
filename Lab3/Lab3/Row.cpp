#include "stdafx.h"
#include "Row.h"
#include<iostream>

Row::Row(int* row, int  columnsCount) : row(row) {
	Row::columnsCount = columnsCount;
}

int Row::operator[](int index) {
	if (0 <= index && index < columnsCount) {
		return row[index];
	}
	else {
		throw std::out_of_range("There is no column with index " + index);
	}
}

