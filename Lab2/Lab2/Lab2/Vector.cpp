#include "stdafx.h"
#include "Vector.h"
#include <vector>

Vector::Vector()
{
}


Vector::~Vector()
{
	_vector.clear();
}

void Vector::clear() {
	this->_vector.clear();
}

void Vector::push_back(int value)
{
	this->_vector.push_back(value);
}

void Vector::pop_back()
{
	if (_vector.size() > 0) {
		this->_vector.pop_back();
	}
}

int Vector::operator[](int index)
{
	return this->_vector[index];
}

int Vector::Length()
{
	return _vector.size();
}
