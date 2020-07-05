#include "SetIterator.h"
#include "Set.h"
# include <exception>


SetIterator::SetIterator(const Set& m) : set(m)
{
	iterator = 0;
}


void SetIterator::first() {
	this->iterator = 0;
	// time complexity theta(1)
}


void SetIterator::next() {
	if (this->iterator + 1 > this->set.length)
		throw std::exception();
	else
		this->iterator++;
	// time complexity Theta(1)
}

TElem SetIterator::getCurrent()
{
	if (this->iterator == this->set.length)
		throw std::exception();
	else
		return this->set.elements[this->iterator];
	return NULL_TELEM;

	// time complexity Theta(1)
}

bool SetIterator::valid() const {

	if (this->iterator < this->set.length)
		return true;
	return false;
}	// time complexity Theta(1)




