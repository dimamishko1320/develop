#include "RingBuffer.h"

RingBuffer::RingBuffer(int size) {
	this->size = size;
	this->bufferSize = size + 1;
	array = new int[bufferSize];
	if (size <= 0) {
		throw "Not enough memory";
	}
	write_index = 0; 
	read_index = 0;  
}               

RingBuffer::~RingBuffer() {
	delete[]array;
	write_index = 0;
	read_index = 0;
}


void RingBuffer::addElem(int element) {
	if (isFull()) {
		throw "Queue is full";
	}
	array[write_index] = element;
	write_index = (write_index + 1) % bufferSize;
}

int RingBuffer::takeElem() {
	if (isEmpty()) {
		throw "Queue is empty";
	}
	int output = array[read_index];
	read_index = (read_index + 1) % bufferSize;
	return output;
}

int RingBuffer::getElem() {
	if (isEmpty()) {
		throw "Queue is empty";
	}
	return array[read_index];
}
bool RingBuffer::isEmpty() {
	return write_index == read_index;
}
bool RingBuffer::isFull() {
	return write_index == (read_index - 1 + bufferSize) % bufferSize;
}


int RingBuffer::getSize() const {
	return size;
}

void RingBuffer::clear() {
	write_index = read_index;
}
