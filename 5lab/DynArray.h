#pragma once
#include <iostream>
#include <stdbool.h>
#include <typeinfo>
#include <ctime>
#include <cstring>

using namespace std;

struct Vec2 {
	float x = 0.0f,y = 0.0f;
	
	Vec2() = default;

	Vec2(float x, float y):
		x(x),y(y){
	}
	
	friend ostream& operator<<(ostream& os, const Vec2& vec) {
		os << vec.x << "-x " << vec.y << "-y; ";
		return os;
	}
	friend istream& operator>>(istream& is, Vec2& vec) {
		cout << "x:" << endl;
		is >> vec.x;
		cout << "y:" << endl;
		is >> vec.y;
		return is;
	}

	float getLength() const {
		return pow(pow(this->x, 2) + pow(this->y, 2), 0.5);
	}

	bool operator<(const Vec2& other) const {
		return this->getLength() < other.getLength();
	}

	bool operator>(const Vec2& other) const {
		return this->getLength() > other.getLength();
	}

	bool operator==(const Vec2& other) const {
		return this->getLength() == other.getLength();
	}
};

template <typename T, int maxSize>
class InitDynArr {
private:
	T* arr;
	int size = 0;

public:

	InitDynArr() {
		size = 0;
		arr = new T[maxSize];
	}
	
	InitDynArr(const InitDynArr& other) {
		size = other.size;
		arr = new T[maxSize];
		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}

	InitDynArr<T, maxSize>& operator=(const InitDynArr& other){
		if (this != &other){
			delete[] arr;
			size = other.size;
			arr = new T[maxSize];
			for (int i = 0; i < size; i++){
				arr[i] = other.arr[i];
			}
		}
		return *this;
	}
	
	~InitDynArr() {
		delete[] arr;
	}

	int getSize() const {
		return size;
	}

	int getMaxSize() const {
		return maxSize;
	}
	
	friend  ostream& operator<<(ostream& os, InitDynArr<T, maxSize>& arr) {
		for (int i = 0; i < arr.getSize(); ++i)
			os << arr[i] << " ";
		return os;
	}

	void sort(bool bAscending);
	void insert(const T& elem, int n);
	void remove(int n);

	T& operator[](int index);
	void operator+(const T& elem);
	void operator-(const T& elem);
	bool operator<(const InitDynArr& other) const;
	bool operator>(const InitDynArr& other) const;
};

template <typename T, int maxSize>
void InitDynArr<T, maxSize>::sort(bool bAscending) {
	if (bAscending) {
		for (int i = 0; i < size - 1; i++) {
			int min = i;
			for (int j = i + 1; j < size; j++)
				if (arr[j] < arr[min])
					min = j;
			T temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
	else {
		for (int i = size; i >= 1; i--) {
			int min = i;
			for (int j = i - 1; j >= 0; j--)
				if (arr[j] < arr[min])
					min = j;
			T temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

template <typename T, int maxSize>
void InitDynArr<T, maxSize>::insert(const T& elem, int n) {
	if (n > size){
		cout << "You are trying to add an element to a position that is outside the array" << endl;
		return;
	}
	else {
		T* tmp = new T[size + 1];
		for (int i = 0; i < size; i++) {
			tmp[i] = arr[i];
		}
		delete[] arr;
		arr = tmp;
	}

	for (int i = size; i > n; i--) {
		arr[i] = arr[i - 1];
	}
	arr[n] = elem;
	size++;
}

template <typename T, int maxSize>
void InitDynArr<T, maxSize>::remove(int n) {
	if (n > size) {
		cout << "You are trying to remove an element from a position that is outside the array" << endl;
		return;
	}
	else {
		T* tmp = new T[size-1];
		for (int i = 0; i < n; i++) {
			tmp[i] = arr[i];
		}
		tmp[n] = arr[n + 1];
		for (int i = n + 1; i < size - 1; i++) {
				tmp[i] = arr[i + 1];
		}
		size--;
		delete[] arr;
		arr = tmp;
	}
}

template <typename T, int maxSize>
T& InitDynArr<T, maxSize>::operator[](int index) {
	if (index > size) {
		cout << "Index outside array" << endl;
	}
	else {
		return arr[index];
	}
}

template <typename T, int maxSize>
void InitDynArr<T, maxSize>::operator+(const T& elem) {
	insert(elem, size);
}

template <typename T, int maxSize>
void InitDynArr<T, maxSize>::operator-(const T& elem) {
	for (int i = 0; i < size; i++){
		if (arr[i] == elem){
			remove(i);
			return;
		}
	}
}

template <typename T, int maxSize>
bool InitDynArr<T, maxSize>::operator<(const InitDynArr& other) const{
	if (size != other.size) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		if (arr[i] > other.arr[i]) {
			return false;
		}
	}
	return true;
}

template <typename T, int maxSize>
bool InitDynArr<T, maxSize>::operator>(const InitDynArr& other) const
{
	if (size != other.size) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		if (arr[i] < other.arr[i]) {
			return false;
		}
	}
	return true;
}

template <int maxSize>
class InitDynArr<char*, maxSize>{
private:
	char** arr = nullptr;
	int size = 0;

public:
	InitDynArr(){
		size = 0;
		arr = new char* [maxSize];
	}

	~InitDynArr(){
		for (int i = 0; i < size; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}

	InitDynArr(const InitDynArr& other) {
		size = other.size;
		arr = new char* [maxSize];
		for (int i = 0; i < size; i++) {
			arr[i] = new char[strlen(other.arr[i]) + 1];
			strcpy_s(arr[i], strlen(other.arr[i]) + 1, other.arr[i]);
		}
	}

	InitDynArr<char*, maxSize>& operator=(const InitDynArr& other) {
		if (this != &other) {
			for (int i = 0; i < size; i++) {
				delete arr[i];
			}
			delete arr;
			size = other.size;
			arr = new char* [maxSize];
			for (int i = 0; i < size; i++)
			{
				arr[i] = new char[strlen(other.arr[i]) + 1];
				strcpy_s(arr[i], strlen(other.arr[i]) + 1, other.arr[i]);
			}
		}
		return *this;
	}

	int getSize() const {
		return size;
	}

	int getMaxSize() const {
		return maxSize;
	}

	friend  ostream& operator<<(ostream& os, InitDynArr<char*, maxSize>& arr) {
		for (int i = 0; i < arr.getSize(); ++i)
			os << arr[i] << " ";
		return os;
	}

	void sort(bool bAscending);
	void insert(const char* elem, int n);
	void remove(int n);

	char*& operator[](int nindex);
	void operator+(const char* elem);
	void operator-(const char* elem);
	bool operator<(const InitDynArr& other) const;
	bool operator>(const InitDynArr& other) const;
};

template <int maxSize>
char*& InitDynArr<char*, maxSize>::operator[](int index){
	if (index > size) {
		cout << "Index outside array" << endl;
	}
	else {
		return arr[index];
	}
}

template <int maxSize>
void InitDynArr<char*, maxSize>::sort(bool bAscending) {
	if (bAscending) {
		for (int i = 0; i < size - 1; i++) {
			int min = i;
			for (int j = i + 1; j < size; j++)
				if (strcmp(arr[j], arr[min]) > 0)
					min = j;
			char* temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
	else {
		for (int i = 0; i < size -1; i++) {
			int min = i;
			for (int j = i + 1; j < size; j++)
				if (strcmp(arr[j],arr[min]) < 0)
					min = j;
			char* temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}


template <int maxSize>
void InitDynArr<char*, maxSize>::insert(const char* elem, int n) {
	if (n > size) {
		cout << "You are trying to add an element to a position that is outside the array" << endl;
		return;
	}
	else {
		for (int i = size; i > n; i--)
		{
			delete[] arr[i];
			arr[i] = new char[strlen(arr[i - 1]) + 1];
			strcpy_s(arr[i], strlen(arr[i - 1]) + 1, arr[i - 1]);
		}
		arr[n] = new char[strlen(elem) + 1];
		strcpy_s(arr[n], strlen(elem) + 1, elem);
		size++;
	}
}

template <int maxSize>
void InitDynArr<char*, maxSize>::remove(int n) {
	if (n > size) {
		cout << "You are trying to remove an element from a position that is outside the array" << endl;
		return;
	}
	else {
		for (int i = n; i < size - 1; i++) {
			delete[] arr[i];
			arr[i] = new char[strlen(arr[i + 1]) + 1];
			strcpy_s(arr[i], strlen(arr[i + 1]) + 1, arr[i + 1]);
		}
		delete[] arr[size-1];
		size--;
	}
}

template <int maxSize>
void InitDynArr<char*, maxSize>::operator+(const char* elem) {
	insert(elem, size);
}

template <int maxSize>
void InitDynArr<char*, maxSize>::operator-(const char* elem) {
	for (int i = 0; i < size; i++){
		if (strcmp(arr[i], elem) == 0){
			remove(i);
			return;
		}
	}
}

template <int maxSize>
bool InitDynArr<char*, maxSize>::operator<(const InitDynArr& other) const{
	if (size != other.size) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		if (strcmp(arr[i], other.arr[i]) > 0) {
			return false;
		}
	}
	return true;
}

template <int maxSize>
bool InitDynArr<char*, maxSize>::operator>(const InitDynArr& other) const
{
	if (size != other.size) {
		return false;
	}

	for (int i = 0; i < size; i++) {
		if (strcmp(arr[i], other.arr[i]) < 0) {
			return false;
		}
	}
	return true;
}