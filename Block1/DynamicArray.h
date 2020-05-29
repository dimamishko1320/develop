#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <ostream>
#include <istream>

using namespace std;

class DynamicArray {
private:
	int *arr;
	int size;
public:
	DynamicArray();

	DynamicArray(int n);

	DynamicArray(int n, int CONST);

	DynamicArray(const DynamicArray &dynamicArray);

	~DynamicArray();

	int getSize() const;

	int &operator[](int i);

	void resize(int newSize);

	bool operator==(DynamicArray &array);

	bool operator!=(DynamicArray &array);

	bool operator>(DynamicArray &array);

	bool operator<(DynamicArray &array);

	bool operator>=(DynamicArray &array);

	bool operator<=(DynamicArray &array);

	void operator=(DynamicArray const &array);

	void operator=(DynamicArray &&array);

	DynamicArray operator+(DynamicArray &array1);

	friend ostream &operator<<(ostream &os, const DynamicArray &array);

	friend istream &operator>>(istream &is, DynamicArray &array);
};



#endif 
