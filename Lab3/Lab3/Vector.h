#include <vector>

using namespace std;
#pragma once

class Matrix;

class Vector
{
private:
	vector<int> _vector;

public:
	Vector();
	~Vector();
	void clear();
	void push_back(int);
	void pop_back();
	Matrix* operator+(Vector vector);
	int operator[](int);
	int Length();
};

