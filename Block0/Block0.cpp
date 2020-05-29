
#include "Storages.h"
#include <iostream>
#include "Box.h"
#include "Container.h"
using namespace Storages;
using namespace std;

int main()
{

	{
		setlocale(LC_ALL, "Russian");
		Box box1(1, 2, 3, 4.0, 5);
		Box box2(2, 3, 5, 7.3, 1);
		Box box3(3, 4, 6, 9, 4);
		Box box4(22, 13, 90, 12.2, 1);
		Box boxArr[4] = { box1, box2, box3, box4 };

		cout << "Суммарная стоимость всех коробок =" << totalValue(boxArr, 4) << endl;

		if (noMoreThan(boxArr, 4,200)) {
			cout << "Сумма длины ширины высоты всех коробок не превосходит 200" << endl;
		}
		else {
			cout << "Сумма длины ширины высоты всех коробок превосходит 50" << endl;
		}

		if (noMoreThan(boxArr, 4, 1)) {
			cout << "Сумма длины ширины высоты всех коробок не превосходит 1" << endl;
		}
		else {
			cout << "Сумма длины ширины высоты всех коробок превосходит 1" << endl;
		}


		cout << "Максимальный вес коробки, не превышающий 100 = " << maxWeightOfBoxes(boxArr, 4, 100) << endl;


		Box boxt1(1, 2, 3, 4, 5);
		Box boxt2(2, 3, 4, 5, 6);
		Box boxArrA1[2] = { boxt1, boxt2 };

		if (theFit(boxArrA1, 2)) {
			cout << "Коробки можно вложить друг в друга" << endl;
		}
		else {
			cout << "Коробки нельзя вложить друг в друга" << endl;
		}
		Box box5(1, 1, 3, 4, 5);
		Box box6(2, 2, 4, 5, 6);
		Box box7(3, 3, 5, 6, 7);
		Box box8(4, 6, 7, 10, 7);
		Box box9(5, 1, 1, 6, 7);
		Box boxArrA3[5] = { box5, box6, box7, box8, box9 };

		if (theFit(boxArrA3, 5)) {
			cout << "Коробки можно вложить друг в друга" << endl;
		}
		else {
			cout << "Коробки нельзя вложить друг в друга" << endl;
		}

		Box boxC1;
		Box boxC2;
		cout << "Введите данные первой коробки" << endl;
		cin >> boxC1;
		cout << "Введите данные второй коробки" << endl;
		cin >> boxC2;
		if (equalsOfBoxes(boxC1, boxC2) == true) cout << "Коробки равны" << endl;
		else cout << "Коробки не равны"<<endl;
	}


	{
		Container container(930, 900, 700, 200);
		container.addBox(Storages::Box(1, 3, 2, 10, 3));
		container.addBox(Storages::Box(2, 3, 4, 11, 10));
		container.addBox(Storages::Box(4, 5, 1, 12, 31));

		cout << "Количество коробок = " << container.getBoxCount() << endl;

		cout << "суммарный вес содержимого контейнера= " << container.weightOfContainer() << endl;

		cout << "суммарная стоимость содержимого = " << container.priceOfContainer() << endl;

		cout << container.getBox(1).getWidth() << endl;
		cout << container.getBox(2).getWidth() << endl;

		Container container1(930, 900, 700, 200);
		container1.addBox(Storages::Box(1, 3, 2, 10, 3));
		container1.addBox(Storages::Box(2, 3, 4, 11, 10));
		container1.addBox(Storages::Box(4, 5, 1, 12, 31));

		cout << container1.getBox(1).getLength() << endl;

		container1.deleteBox(1);
		cout << container1.getBox(1).getLength() << endl;
		cout << container1 << endl;
		cin >> container1;
		cout << container1 << endl;
		Storages::Container container2(930, 900, 700, 200);
		container2.addBox(Storages::Box(1, 3, 2, 10, 3));
		cout << container[0].getHeight() << endl;

	}


}