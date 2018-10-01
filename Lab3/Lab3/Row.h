#pragma once

class Row {
public:
	Row(int* row, int  columnsCount);
	int operator[](int index);
private:
	int* row;
	int columnsCount;
};
