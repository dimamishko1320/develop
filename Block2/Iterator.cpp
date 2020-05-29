#include "Iterator.h"

Iterator::Iterator(RingBuffer* &buffer) {
	this->ringBuffer = buffer;
	this->index = buffer->read_index;
}

void Iterator::start() {
	index = ringBuffer->read_index;
}

void Iterator::next() {
	index = (index + 1) % ringBuffer->bufferSize;
}

bool Iterator::finish() {
	return index == ringBuffer->write_index;
}

int Iterator::getValue() {
	return ringBuffer->array[index];
}