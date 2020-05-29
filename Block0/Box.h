#ifndef TASK0_BOX_H
#define TASK0_BOX_H

#include <ostream>
#include <istream>
namespace Storages {
	class Box {
	private:
		int length;
		int width;
		int height;
		int value;
		double weight;
	public:
		Box();
		Box(int length, int width, int height, double weight, int value);

		friend std::ostream& operator << (std::ostream& out, const Box& obj);
		friend std::istream& operator >> (std::istream& in, Box& obj);

		friend int totalValue(Box boxes[], unsigned size);
		friend bool noMoreThan(Box boxes[], unsigned size, int valueCheck);
		friend double maxWeightOfBoxes(Box boxes[], unsigned size, int maxV);
		friend bool theFit(Box boxes[], unsigned size);
		friend bool equalsOfBoxes(Box box1, Box box2);

		int getLength() const;
		int getWidth() const;
		int getHeight() const;
		double getWeight() const;
		int getValue() const;
		void setLength(int length);
		void setWidth(int width);
		void setHeight(int height);
		void setWeight(double wight);
		void setValue(int value);
	};
}
#endif
