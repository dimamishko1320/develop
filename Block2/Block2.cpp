#include <iostream>
#include "RingBuffer.h"
#include "Iterator.h"
using namespace std;

int main() {
	setlocale(LC_CTYPE, "Ru");
	RingBuffer ringBuffer1(5);

	cout << "Размер очереди: " << ringBuffer1.getSize() << endl;

	ringBuffer1.addElem(1); 
	ringBuffer1.addElem(2);
	ringBuffer1.addElem(3);
	ringBuffer1.addElem(4);
	
	cout << "Получение элемента с начала очереди: " << ringBuffer1.getElem() << endl;
	
	cout << "Изъятие элемента с начала очереди: " << ringBuffer1.takeElem() << endl;
	
	ringBuffer1.addElem(5);
	
	ringBuffer1.addElem(6);
	
	cout << "Очередь полна?  " << ringBuffer1.isFull() << endl;
	cout << "Очередь пуста?  " << ringBuffer1.isEmpty() << endl;

	RingBuffer *ringBuffer2 = new RingBuffer(4);
	ringBuffer2->addElem(12);
	ringBuffer2->addElem(23);
	ringBuffer2->addElem(34);
	ringBuffer2->addElem(45);
	Iterator iterator1 = Iterator(ringBuffer2);
	cout << iterator1.getValue() << endl;
	iterator1.start();
	while (!iterator1.finish()) {
		cout << iterator1.getValue() << " ";
		iterator1.next();

	}



	cout << endl << "______________________________________" << endl;
	return 0;
}