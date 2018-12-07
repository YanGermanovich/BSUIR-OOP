#pragma once

template <class T>

class Row {
public:
	Row(T* row, int  columnsCount);
	T operator[](int index);
private:
	T* row;
	int columnsCount;
};

template <class T>
Row<T>::Row(T* row, int  columnsCount) : row(row) {
	Row<T>::columnsCount = columnsCount;
}

template <class T>
T Row<T>::operator[](int index) {
	if (0 <= index && index < columnsCount) {
		return row[index];
	}
	else {
		throw std::out_of_range("There is no column with index " + index);
	}
}

