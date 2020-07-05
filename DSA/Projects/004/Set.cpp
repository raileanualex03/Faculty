#include "Set.h"
#include "SetITerator.h"
# define EMPTY_SPACE -100
int Set::hashFunction(TElem number, int i)
{
	return (number % m + i * (1 +  number % (m - 1))) % m;
}

Set::Set() {
	this->elems = new TElem[this->m];
	for (auto& elem : elems)
		elem = EMPTY_SPACE;
	this->m = 17;
}


bool Set::add(TElem elem) {
	//TODO - Implementation
	int i = 0;
	int position = this->hashFunction(e, i);
	while (i < this->m && this->elems[position] != EMPTY_SPACE) {
		i++;
		position = hashFunction(elem, i);
	}

	if (i == this->m)
		// resize
		this->resize();
	this->elems[position] = e;
}


bool Set::remove(TElem elem) {
	//TODO - Implementation
	return false;
}

bool Set::search(TElem elem) const {
	int i = 0, position;
	while (i < m) {
		position = hashFunction(elem, i);
		if (elems[position == elem])
			return true;
	}
	return false;
}


int Set::size() const {
	int size = 0;
	for (TElem elem : elems) {
		if (elem != EMPTY_SPACE)
			size += 1;
	}
	return size;
}


bool Set::isEmpty() const {
	
	if (this->size() == 0)
		return true;
	return false;
}


Set::~Set() {
	//TODO - Implementation
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


