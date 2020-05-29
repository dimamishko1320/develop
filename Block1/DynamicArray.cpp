#include "DynamicArray.h"
#include <iostream>
#include <algorithm>

using namespace std;

DynamicArray::DynamicArray() {
	size = 4;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

DynamicArray::DynamicArray(int n) {
	size = n;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

DynamicArray::DynamicArray(int n, int CONST) {
	size = n;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = CONST;
	}
}

DynamicArray::DynamicArray(const DynamicArray &dynamicArray) {
	arr = new int[dynamicArray.size];
	size = dynamicArray.size;
	for (int i = 0; i < size; i++) {
		arr[i] = dynamicArray.arr[i];
	}
}


DynamicArray::~DynamicArray() {
	delete[] arr;
}

int DynamicArray::getSize() const {
	return size;
}

int &DynamicArray::operator[](int i) {
	if (i < 0 || i >= size) {
		throw "Неккоректный индекс";
	}
	else {
		return arr[i];
	}
}

void DynamicArray::resize(int newSize) {
	if (newSize < 0) {
		throw "Недопустимое новое значение размера массив!";
	}
	else {
		int *tmp = arr;
		arr = new int[newSize];
		for (int i = 0; i < min(size, newSize); i++) {
			arr[i] = tmp[i];
		}
		for (int i = min(size, newSize); i < newSize; i++) {
			arr[i] = 0;
		}
		size = newSize;
		delete tmp;
	}
}

bool DynamicArray::operator==(DynamicArray &array) {
	if (size == array.size) {
		for (int i = 0; i < size; i++) {
			if (arr[i] != array.arr[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		throw "Разные размеры массивов";
	}
}

bool DynamicArray::operator!=(DynamicArray &array) {
	if (size == array.size) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == array.arr[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		throw "Разные размеры массивов";
	}
}

bool DynamicArray::operator<(DynamicArray &array) {
	if (size < array.size) {
		for (int i = 0; i < size; i++) {
			if (arr[i] < array.arr[i]) {
				return true;
			}
			if (arr[i] > array.arr[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		for (int i = 0; i < array.size; i++) {
			if (arr[i] < array.arr[i]) {
				return true;
			}
			if (arr[i] > array.arr[i]) {
				return false;
			}
		}
		return false;
	}
}

bool DynamicArray::operator<=(DynamicArray &array) {
	if (size <= array.size) {
		for (int i = 0; i < size; i++) {
			if (arr[i] < array.arr[i]) {
				return true;
			}
			if (arr[i] > array.arr[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		for (int i = 0; i < array.size; i++) {
			if (arr[i] < array.arr[i]) {
				return true;
			}
			if (arr[i] > array.arr[i]) {
				return false;
			}
		}
		return false;
	}
}

bool DynamicArray::operator>(DynamicArray &array) {
	if (size <= array.size) {
		for (int i = 0; i < size; i++) {
			if (arr[i] < array.arr[i]) {
				return false;
			}
			if (arr[i] > array.arr[i]) {
				return true;
			}
		}
		return false;
	}
	else {
		for (int i = 0; i < array.size; i++) {
			if (arr[i] < array.arr[i]) {
				return false;
			}
			if (arr[i] > array.arr[i]) {
				return true;
			}
		}
		return true;
	}
}

bool DynamicArray::operator>=(DynamicArray &array) {
	if (size < array.size) {
		for (int i = 0; i < size; i++) {
			if (arr[i] < array.arr[i]) {
				return false;
			}
			if (arr[i] > array.arr[i]) {
				return true;
			}
		}
		return false;
	}
	else {
		for (int i = 0; i < array.size; i++) {
			if (arr[i] < array.arr[i]) {
				return false;
			}
			if (arr[i] > array.arr[i]) {
				return true;
			}
		}
		return true;
	}
}

DynamicArray DynamicArray::operator+(DynamicArray &dynamicArray) {
	DynamicArray array(dynamicArray.size + size);
	array.size = dynamicArray.size + size;
	for (int i = 0; i < array.size; i++) {
		if (i < size) {
			array.arr[i] = arr[i];
		}
		else {
			array.arr[i] = dynamicArray.arr[i - size];
		}
	}
	return array;
}

void DynamicArray::operator=(DynamicArray const &dynamicArray) {
	delete[]arr;
	arr = new int[dynamicArray.size];
	size = dynamicArray.size;
	for (int i = 0; i < size; i++) {
		arr[i] = dynamicArray.arr[i];
	}
}

void DynamicArray::operator=(DynamicArray &&dynamicArray) {
	delete[]arr;
	size = dynamicArray.size;
	arr = dynamicArray.arr;
	dynamicArray.arr = nullptr;
	dynamicArray.size = 0;
}


ostream &operator<<(ostream &os, const DynamicArray &array) {
	os << "size: " << array.size << " arr: ";
	for (int i = 0; i < array.size; i++) {
		os << array.arr[i] << ' ';
	}

	return os;
}

istream &operator>>(istream &is, DynamicArray &array) {
	int n;
	is >> n;
	array.resize(n);
	for (int i = 0; i < array.size; i++) {
		is >> array.arr[i];
	}
	return is;
}
