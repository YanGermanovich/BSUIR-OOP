#pragma once

template<class T> class Transaction {
private:
	T * initial;
	T * current;

public:
	Transaction() {}
	T* BeginTransaction(T&);
	T* Commit();
	T* Rollback();
	~Transaction();
};

template<class T>
T * Transaction<T>::BeginTransaction(T& obj)
{
	if (this->initial != nullptr) {
		delete initial;
	}

	this->initial = new T(obj);
	this->current = new T(obj);

	return this->current;
}

template<class T>
T * Transaction<T>::Commit()
{
	T* buffer = this->current;
	this->current = NULL;
	this->initial = NULL;

	return buffer;
}

template<class T>
T * Transaction<T>::Rollback()
{
	T* buffer = this->initial;
	this->current = NULL;
	this->initial = NULL;

	return buffer;
}

template<class T>
Transaction<T>::~Transaction()
{
	delete this->initial;
}