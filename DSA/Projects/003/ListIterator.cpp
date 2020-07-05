#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

using namespace std;

ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
	//TODO - Implementation
	this->currentPosition = 0;
}

void ListIterator::first(){
	//TODO - Implementation
	this->currentPosition = list.head;
}

void ListIterator::next(){
	//TODO - Implementation
	this->currentPosition = list.next[currentPosition];
}

bool ListIterator::valid() const{
	//TODO - Implementation
	if (currentPosition < 0)
		return false;
	return true;
}

TComp ListIterator::getCurrent() const{
	//TODO - Implementation
	return list.elems[currentPosition];
}


