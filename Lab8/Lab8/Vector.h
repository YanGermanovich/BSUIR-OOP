#include <vector>

using namespace std;
#pragma once

template <class T>
class Matrix;

template <class T>
class Vector
{
private:
	vector<T> _vector;

public:
	Vector();
	~Vector();
	void clear();
	void push_back(T);
	void pop_back();
	Matrix<T>* operator+(Vector<T> vector);
	T operator[](int);
	int Length();
};

template <class T>
Vector<T>::Vector()
{
}

template <class T>
Vector<T>::~Vector()
{
	_vector.clear();
}

template <class T>
void Vector<T>::clear() {
	this->_vector.clear();
}

template <class T>
void Vector<T>::push_back(T value)
{
	this->_vector.push_back(value);
}

template <class T>
void Vector<T>::pop_back()
{
	if (_vector.size() > 0) {
		this->_vector.pop_back();
	}
}

template <class T>
Matrix<T>* Vector<T>::operator+(Vector<T> vector)
{
	return new Matrix<int>(*this, vector);
}

template <class T>
T Vector<T>::operator[](int index)
{
	return this->_vector[index];
}

template <class T>
int Vector<T>::Length()
{
	return _vector.size();
}

