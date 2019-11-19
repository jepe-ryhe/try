#include<iostream>
#include<list>
//#include"stdafx.h"
using namespace std;
template <typename T>
class ArrayList {
public:
	ArrayList(const int size) {
		maxSize = size;
		arrayList = new T[maxSize];
		curLen = 0;
		position = 0;
	}
	~ArrayList() {
		delete[] arrayList;
	}
	void clear() {
		delete[] arrayList;
		curLen = 0;
		position = 0;
		arrayList = new T[maxSize];
	}
	int Length() { return curLen; }
	bool Insert(const int p, const T value);
	bool Delete(const int p);
	bool Append(const T value);
	bool GetValue(const int p, T& value);
	bool SetValue(const int p, const T value);
	bool GetPos(int &p, const T value);
	T delmin();
	void delone(const T value);
	void delsome(const T min, const T max);
private:
	T *arrayList;
	int maxSize;
	int curLen;
	int position;
};


template<typename T>
bool ArrayList<T>::Insert(const int p, const T value)
{
	if (curLen >= maxSize) {
		return false;
	}
	if (p<0 || p>curLen) {
		return false;
	}
	for (int i = curLen; i > p; i--) {
		arrayList[i] = arrayList[i - 1];
	}
	arrayList[p] = value;
	curLen++;
	return true;
}

template<typename T>
bool ArrayList<T>::Delete(const int p)
{
	if (curLen <= 0) {
		return false;
	}
	if (p<0 || p>curLen) {
		return false;
	}
	for (int i = p; i < curLen; i++) {
		arrayList[i] = arrayList[i + 1];
	}
	curLen--;
	return true;
}

template<typename T>
bool ArrayList<T>::Append(const T value)
{
	if (curLen >= maxSize) {
		return false;
	}
	curLen++;
	arrayList[curLen] = value;
	return true;
}

template<typename T>
bool ArrayList<T>::GetValue(const int p, T & value)
{
	if (p<0 || p>curLen) {
		return false;
	}
	value = arrayList[p];
	return true;
}

template<typename T>
bool ArrayList<T>::SetValue(const int p, const T value)
{
	if (p<0 || p>curLen) {
		return false;
	}
	arrayList[p] = value;
	return true;
}

template<typename T>
bool ArrayList<T>::GetPos(int & p, const T value)
{
	for (int i = 0; i < curLen; i++) {
		if (arrayList[i] = value) {
			p = i;
			return true;
		}
	}
	return false;
}
template<typename T>
T ArrayList<T>::delmin()
{
	T min = arrayList[0];
	int p=0;
	for (int i = 0; i < curLen; i++) {
		if (arrayList < min) {
			p = i;
			min = arrayList[i];
		}
	}
	T last;
	GetValue(curLen, last);
	SetValue(p, last);
	Delete(curLen);
	return min;
}

template<typename T>
void ArrayList<T>::delone(const T value)
{
	int p;
	GetPos(p, value);
	Delete(p);
}

template<typename T>
void ArrayList<T>::delsome(const T min, const T max)
{
	for (T i = min; i <= max; i++) {
		delone(i);
	}
}

void main() {}
