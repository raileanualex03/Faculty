#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
#pragma comment(linker, "/subsystem:Windows")
using namespace std;
#include <exception>
# define INIT_SIZE 10000

SortedIteratedList::SortedIteratedList(Relation r) {
	//TODO - Implementation
	this->relation = r;
	capacity = INIT_SIZE;
	this->elems = (TComp*)malloc(INIT_SIZE * sizeof(TComp));
	this->next = (TComp*)malloc(INIT_SIZE * sizeof(TComp));
	head = -1;
	counterPairs = 0;
	for (int i = 0; i < capacity; i++)
		next[i] = i + 1;
	next[capacity] = -1;
	firstEmpty = 0;
}

int SortedIteratedList::size() const {
	//TODO - Implementation
	return counterPairs;
}

bool SortedIteratedList::isEmpty() const {
	//TODO - Implementation
	if (this->counterPairs == 0)
		return true;
	return false;
}

ListIterator SortedIteratedList::first() const {
	ListIterator it{ *this };
	it.first();

	return it;
}

TComp SortedIteratedList::getElement(ListIterator poz) const {
	if (poz.valid() == false)
		throw exception();
	//TODO - Implementation
	ListIterator it{*this};
	while (it.currentPosition != poz.currentPosition)
		it.next();
	return it.getCurrent();

}

TComp SortedIteratedList::remove(ListIterator& poz) {
	//TODO - Implementation
	return NULL_TCOMP;
}

ListIterator SortedIteratedList::search(TComp e) const{
	ListIterator it{ *this };
	while (it.valid() == true && it.getCurrent() != e)
		it.next();

	return it;
}

void SortedIteratedList::add(TComp e) {
	// check first if it is empty
	int pozCurrent;
	TComp nodCurrent;
	if (head == -1) {
		TComp newPosition = this->firstEmpty;
		this->elems[newPosition] = e;
		firstEmpty = this->next[firstEmpty];
		next[newPosition] = this->head;
		this->head = newPosition;
	}
	else {
		ListIterator it{ *this };
		it.first();
		TComp previous = -1;
		TComp current = it.getCurrent();
		while (current != -1 && relation(current, e) == true) {
			previous = it.getCurrent();
			it.next();
			current = it.getCurrent();
		}
		if (current == -1) {
			throw exception();
		}
		else {
			TComp newElem = this->firstEmpty;
			this->firstEmpty = this->next[firstEmpty];
			this->elems[newElem] = this->next[current];
			this->next[current] = newElem;
		}
	}
}

SortedIteratedList::~SortedIteratedList() {
	delete[] &this->elems;
	delete[] &this->next;
}

