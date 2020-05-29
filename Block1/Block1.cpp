#include <iostream>
#include "DynamicArray.h"
using namespace std;


int main() {
	DynamicArray arr1(4, 3);
	DynamicArray arr2(5, 2);
	DynamicArray arr3;
	DynamicArray arr4;
	cout << "arr1 " << arr1 << endl << "array2 " << arr2 << endl << "arr3 " << arr3 << endl << "arr4 " << arr4 << endl;
	arr1 = arr1 + arr2;
	cout << "arr1 + arr2 = " << arr1 << endl;
	cout << "arr3 < arr4 ? " << (arr3 < arr4) << endl;
	cout << "arr3 <= arr4 ? " << (arr3 <= arr4) << endl;
	cout << "arr3 == arr4 ? " << (arr3 == arr4) << endl;
	cout << "arr3 != arr4 ?" << (arr3 != arr4) << endl;
	arr4.resize(7);
	cout << arr4 << endl;
	cout << "Введите размер и элементы массива " << endl;
	cin >> arr4;
	cout << arr4 << endl;
	cout << arr1[1];


	return 0;
}

