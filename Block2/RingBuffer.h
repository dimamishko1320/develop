#ifndef RINGBUFFER_H
#define RINGBUFFER_H
#include <ostream>

class RingBuffer {
private:
	int *array;
	int size;
	int bufferSize;
	int write_index;
	int read_index;

public:
	friend class Iterator;

	RingBuffer(int size);
	~RingBuffer();
	void addElem(int element);
	int takeElem();
	int getElem();
	int getSize() const;
	void clear();
	bool isEmpty();
	bool isFull();
};


#endif 
