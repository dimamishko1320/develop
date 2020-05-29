#include "Box.h"
#include <iostream>
using namespace std;

namespace Storages {

	Box::Box() {
		length = 0;
		width = 0;
		height = 0;
		weight = 0;
		value = 0;
	}

	Box::Box(int length, int width, int height, double weight, int value) {
		if (length < 0 || width < 0 || height < 0 || weight < 0 || value < 0)throw ("Error");
		this->length = length;
		this->width = width;
		this->height = height;
		this->weight = weight;
		this->value = value;
	}
	//Оператор ввода для коробки в произвольный поток
	istream& operator>>(std::istream& in, Box& obj) {
		in >> obj.length;
		in >> obj.width;
		in >> obj.height;
		in >> obj.weight;
		in >> obj.value;
		return in;
	}
	//Оператор вывода для коробки в произвольный поток
	ostream& operator<<(std::ostream& out, const Box& obj) {
		out << "Коробка:(Длина:" << obj.length << ", Ширина:" << obj.width << ", Высота:" << obj.height;
		out << ", Вес:" << obj.weight << ", Стоимость:" << obj.value << ")";
		return out;
	}
	//Суммарная стоимость всего содержимого
	int totalValue(Box *boxes, unsigned sizeOfMassWhithBoxes) {
		int totalValue = 0;
		for (unsigned i = 0; i < sizeOfMassWhithBoxes; i++) {
			totalValue += boxes[i].value;
		}
		return totalValue;
	}
	//функция проверяет, что сумма длины, ширины и высоты всех коробок
	//не превосходит заданного значения.
	bool noMoreThan(Box *boxes, unsigned sizeOfMassWhithBoxes, int valueCheck) {
		int totalSizeOfBoxes = 0;
		for (unsigned i = 0; i < sizeOfMassWhithBoxes; i++) {
			totalSizeOfBoxes += boxes[i].getHeight() + boxes[i].getWidth() + boxes[i].getLength();
		}
		if (totalSizeOfBoxes <= valueCheck) {
			return true;
		}
		return false;
	}
	//функция, которая определяет максимальный вес коробок, объем которых не 
	//больше параметра maxV.
	double maxWeightOfBoxes(Box* boxes, unsigned size, int maxVolume) {
		double maxWeightOfBoxes = 0;
		double temp = 0;
		for (unsigned i = 0; i < size; i++) {
			if (boxes[i].getHeight() * boxes[i].getWidth() * boxes[i].getLength() <= maxVolume) {
				temp = boxes[i].getWeight();
				if (temp > maxWeightOfBoxes) {
					maxWeightOfBoxes = temp;
				}
			}
		}
		return maxWeightOfBoxes;
	}
	//функцию, которая проверяет, что все
	//коробки массива можно вложить друг в друга по одной штуке
	bool theFit(Box *boxes, unsigned sizeOfMassWhithBoxes) {
		int temp = 0;
		Box tempBox(0, 0, 0, 0, 0);
		for (unsigned i = 0; i < (sizeOfMassWhithBoxes - 1); i++) {
			for (unsigned j = 0; j < (sizeOfMassWhithBoxes - i - 1); j++) {
				if (boxes[j].getLength() > boxes[j + 1].getLength()) {
					tempBox = boxes[j];
					boxes[j] = boxes[j + 1];
					boxes[j + 1] = tempBox;
				}
				if (boxes[j].getLength() == boxes[j + 1].getLength()) {
					return false;
				}
			}
		}
		for (unsigned i = 0; i < sizeOfMassWhithBoxes - 1; i++) {
			if (boxes[i].getWidth() >= boxes[i + 1].getWidth()) {
				return false;
			}
			if (boxes[i].getHeight() >= boxes[i + 1].getHeight()) {
				return false;
			}
		}
		return true;
	}
	//Функция проверяет, равны ли 2 коробки
	bool equalsOfBoxes(Box box1, Box box2) {
		if ((box1.getHeight() != box2.getHeight()) || (box1.getLength() != box2.getLength()) || (box1.getWidth() != box2.getWidth()) || (box1.getValue() != box2.getValue()) || (box1.getWeight() != box2.getWeight())) {
			return false;
		}
		return true;
	}
	//геттеры и сеттеры
	int Box::getLength() const {
		return length;
	}

	int Box::getWidth() const {
		return width;
	}

	int Box::getHeight() const {
		return height;
	}

	double Box::getWeight() const {
		return weight;
	}

	int Box::getValue() const {
		return value;
	}

	void Box::setLength(int length) {
		this->length = length;
	}

	void Box::setWidth(int width) {
		this->width = width;
	}

	void Box::setHeight(int height) {
		this->height = height;
	}

	void Box::setWeight(double weight) {
		this->weight = weight;
	}

	void Box::setValue(int value) {
		this->value = value;
	}
}