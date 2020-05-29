#ifndef TASK0_CONTAINER_H
#define TASK0_CONTAINER_H

#include "Box.h"
#include <vector>
#include "Storages.h"

namespace Storages {
	class Container {
	private:
		std::vector<Box> boxArr;
		int length, width, height;
		double maxWeight;
		long getLengthOfAll();
		long getWidthOfAll();
		long getHeightOfAll();

	public:
		Container(int length, int width, int height, double maxWeight);
		void deleteBox(unsigned indexOfBox);
		unsigned getBoxCount();
		long priceOfContainer();
		double weightOfContainer();
		Box getBox(unsigned indexOfBox);
		unsigned addBox(Box obj);
		friend std::ostream& operator<<(std::ostream& out, const Container& obj);
		friend std::istream& operator>>(std::istream& in, Container& obj);
		Box& operator[](unsigned index);
	};
}
#endif