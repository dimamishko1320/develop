
#include "Container.h"
#include <stdio.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using namespace std;
namespace Storages {

	Container::Container(int length, int width, int height, double maxWeight) {
		this->length = length;
		this->width = width;
		this->height = height;
		this->maxWeight = maxWeight;
		this->boxArr.clear();
	}

	//�������� ���������� ������� � ����������
	unsigned Container::getBoxCount() {
		return this->boxArr.size();
	}
	//��������� ��������� �����������
	long Container::priceOfContainer() {
		long result = 0;
		for (Box temp : this->boxArr) {
			result += temp.getValue();
		}
		return result;
	}
	//��������� ��� ����������� ����������
	double Container::weightOfContainer() {
		double result = 0;
		for (Box temp : this->boxArr) {
			result += temp.getWeight();
		}
		return result;
	}
	//��������� ������� �� �������
	Box Container::getBox(unsigned indexOfBox) {
		if ((indexOfBox <= this->boxArr.size() - 1) || (indexOfBox > 0)) {
			return this->boxArr[indexOfBox];
		}
		else {
			throw "������������ ������";
		}
	}
	//���������� ������� � ���������
	unsigned Container::addBox(Box obj) {
		if (obj.getWeight() + this->weightOfContainer() < maxWeight &&
			obj.getLength() + this->getLengthOfAll() <= this->length &&
			obj.getHeight() + this->getHeightOfAll() <= this->height &&
			obj.getWidth() + this->getWidthOfAll() <= this->width) {
			this->boxArr.push_back(obj);
			return this->boxArr.size() - 1;
		}
		else {
			throw "������� ������� ������ �������";
		}
	}

	//������� ������� �� �������
	void Container::deleteBox(unsigned indexOfBox) {
		if (indexOfBox <= this->boxArr.size() - 1) {
			this->boxArr.erase(this->boxArr.begin() + indexOfBox);
		}
		else {
			throw"������������ ������";
		}
	}
	//�������� ������
	ostream& operator<<(ostream& out, const Container& obj) {
		out << "������� � ����������\n";
		for (int i = 0; i < (int)(obj.boxArr.size()); i++) {
			out << "[" << i << "]." << obj.boxArr[i] << "\n";
		}
		out << "����� ����������:" << obj.length << "\n";
		out << "������ ����������:" << obj.width << "\n";
		out << "������ ����������" << obj.height << "\n";
		out << "������������ ��� ����������:" << obj.maxWeight << "\n";
		return out;
	}
	//�������� �����
	istream& operator>>(istream& in, Container& obj) {
		Box tempBox;
		bool tempBool = true;
		while (tempBool) {
			in >> tempBox;
			if (((obj.getWidthOfAll() + tempBox.getWeight()) < obj.maxWeight) && ((obj.getHeightOfAll() + tempBox.getHeight()) < obj.height) && ((obj.getLengthOfAll() + tempBox.getLength()) < obj.length)) {
				obj.addBox(tempBox);
				tempBool = false;
			}
			else {
				cout << "������� �� ����������" << endl;
			}
		}
		return in;
	}
	// ���������|��������� ������� �� �������
	Box& Container::operator[](unsigned index) {
		if (index <= this->boxArr.size() - 1) {
			return this->boxArr[index];
		}
		else {
			throw "������������ ������ �������";
		}
	}

	long Container::getLengthOfAll() {
		long result = 0;
		for (Box temp : this->boxArr) {
			result += temp.getLength();
		}
		return result;
	}

	long Container::getWidthOfAll() {
		long result = 0;
		for (Box temp : this->boxArr) {
			result += temp.getWidth();
		}
		return result;
	}

	long Container::getHeightOfAll() {
		long result = 0;
		for (Box temp : this->boxArr) {
			result += temp.getHeight();
		}
		return result;
	}
}