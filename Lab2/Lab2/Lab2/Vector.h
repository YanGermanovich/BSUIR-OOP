#include <vector>
using namespace std;
#pragma once
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
	int operator[](int);
	int Length();
};

