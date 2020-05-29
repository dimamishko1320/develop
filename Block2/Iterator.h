#include "RingBuffer.h"

#ifndef ITERATOR_H
#define ITERATOR_H


class Iterator {
private:
	int index;
	RingBuffer *ringBuffer;
public:
	friend class RingBuffer;
	Iterator(RingBuffer* &buffer);
	void start();
	void next();
	bool finish();
	int getValue();

};


#endif
