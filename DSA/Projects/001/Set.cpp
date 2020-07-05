#include "Set.h"
#include "SetITerator.h"
#include <iostream>

Set::Set() {
	this->length = 0;
	this->capacity = 10;
	this->elements = new TElem[10];
}


bool Set::add(TElem elem) {
	// this function checks if the element is unique
	for (unsigned index = 0; index < this->length; index++)
		if (this->elements[index] == elem)
			return false;
	if (this->length == this->capacity)
		this->resize(2);
	this->elements[this->length] = elem;
	this->length++;
	return true;
	// time complexity is O(n)
	// BC: if the first element is the first one existing	
}



bool Set::remove(TElem elem){
	// this function checks if the elem exists
	for (unsigned index = 0; index < this->length; index++) {
		if (this->elements[index] == elem)
		{
				this->elements[index] = this->elements[this->length - 1];
				this->length--;
				return true;
			
		}
	}
	return false;
	// time complexity is O(n)
	// BC: element is the first one
	// WC: element is the last one
}

bool Set::search(TElem elem) const {
	for (unsigned index = 0; index < this->length; index++) {
		if (this->elements[index] == elem)
			return true;
	}
	return false;
	// time complexity is : O(n)
}


int Set::size() const {
	return this->length;
	// time complexity is theta(1)
}


bool Set::isEmpty() const {
	if (this->length == 0)
		return true;
	return false;

	// time complexity is theta(1)

}


Set::~Set() {
	delete[] this->elements;
}

void Set::resize(double factor = 2)
{
	this->capacity *= static_cast<int>(factor);

	TElem* newElements = new TElem[this->capacity];
	for (int i = 0; i < this->length; i++)
		newElements[i] = this->elements[i];
	delete[] this->elements;
	this->elements = newElements;
	// time complexity is O(n)
}
SetIterator Set::iterator() const {
	return SetIterator(*this);
}

int Set::findBiggestElement()
{
	int number = this->elements[0];
	for (unsigned index = 1; index < this->length; index++)
		if (this->elements[index] > number)
			number = this->elements[index];
	return number;
	// time complexity is O(n)
}

int Set::findSmallestElement()
{
	int  number = this->elements[0];
	for (unsigned index = 1; index < this->length; index++)
		if (this->elements[index] < number)
			number = this->elements[index];
	return number;
	// time complexity is O(n)
}

int Set::getRange()
{
	if (this->length == 0)
		return -1;
	return this->findBiggestElement() - this->findSmallestElement();
	// time complexity is Theta(n)
	// BC: the set is empty
}


