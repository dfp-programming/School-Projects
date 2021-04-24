#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template<typename T>
class myArray
{
private:
	int _begin, _end, _size;
public:
	T* safeArray;
	myArray();
	myArray(int);
	myArray(int, int);
	int returnSize() const;
	int returnBegin() const;
	int returnEnd() const;
	void putValue(T, int);
	T returnValue(int);
	void printArray();

	~myArray();
};
template<typename T>
myArray<T>::myArray()
{
	_begin = 0;
	_end = 0;
	_size = 0;
	safeArray = nullptr;
}

template<typename T>
myArray<T>::myArray(int _right)
{
	//The array may begin in a negative index, but can't have a negative _size.
	//This constructor only allows positive values to be passed, so it needs abs().
	_end = abs(_right);
	_begin = 0;
	_size = _end;
	safeArray = new T[_size];
	for (int i = 0; i < _size; i++)
		safeArray[i] = T();
}

template<typename T>
myArray<T>::myArray(int _left, int _right)
{
	if (_left >= _right)
	{
		_begin = 0;
		_end = 0;
		_size = 0;
		safeArray = new T;
		cout << "left index " << _left << " is bigger than right index " << _right << ". Array size 0" << endl;
	}
	else
	{
		_begin = _left;
		_end = _right;
		_size = abs(_end - _begin);
		safeArray = new T[_size];
		for (int i = 0; i < _size; i++)
			safeArray[i] = T();
	}
}

template<typename T>
int myArray<T>::returnSize() const
{
	return _size;
}

template<typename T>
inline int myArray<T>::returnBegin() const
{
	return _begin;
}

template<typename T>
inline int myArray<T>::returnEnd() const
{
	return _end;
}

template<typename T>
void myArray<T>::putValue(T _what, int _where)
{
	if (_where >= _begin && _where < _end)
	{
		if (_begin == 0) safeArray[_where] = _what;
		if (_begin > 0) safeArray[_where - _begin] = _what;
		if (_begin < 0) safeArray[_where + abs(_begin)] = _what;
	}
	else
		cout << "Index " << setw(3) << right << _where << " is out of bounds.";

}
template<typename T>
T myArray<T>::returnValue(int _where)
{
	if (_where >= _begin && _where < _end)
	{
		if (_begin == 0) return safeArray[_where];
		if (_begin > 0) return safeArray[_where - _begin];
		if (_begin < 0) return safeArray[_where + abs(_begin)];
	}
	else
	{
		cout << "Index " << setw(3) << right << _where << " is out of bounds.";
		return T();
	}
}

template<typename T>
void myArray<T>::printArray()
{
	for (int i = 0; i < _size; i++)
	{
		cout << "Index " << setw(3) << right << i+_begin << "  value =  " << safeArray[i] << endl;
	}
}

template<typename T>
myArray<T>::~myArray()
{
	delete[] safeArray;
}

