#pragma once

// this is the header
template <typename TElem>
class DynamicVector
{
private:
	TElem* elements;
	int size;
	int capacity;

public:
	// default constructor for a DynamicVector
	DynamicVector(int capacity = 2);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& vector);

	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& vector);

	/*
		this function adds an element to the dynamicVector
		input: element -> type Bot
		output: 1 if it were added, 0 otherwise
	*/
	int addElement(const TElem& element);


	/*
		Deletes an element from the dynamic vector.
		input: element -> Bot
		output: 1 if it were removed, 0 otherwise
	*/
	int deleteElement(const std::string& title);

	/*
		Returns the size of the dynamicVector
	*/
	int getSize() const;

	/*
		Returns the element from a given position.
	*/
	Bot getElement(int position);

	/*
		This function searches for a bot with a specific ID, returns him if found, 0 otherwise 
	*/
	TElem searchElement(std::string ID);

private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};

// this is the cpp

template <typename TElem>
DynamicVector<TElem>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new Bot[capacity];
}


template <typename TElem>
DynamicVector<TElem>::DynamicVector(const DynamicVector& vector)
{
	this->size = vector.size;
	this->capacity = vector.capacity;
	this->elements = new Bot[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = vector.elements[i];
}

template <typename TElem>
DynamicVector<TElem>::~DynamicVector()
{
	delete[] this->elements;
}

template <typename TElem>
DynamicVector<TElem>& DynamicVector<TElem>::operator=(const DynamicVector& vector)
{
	if (this == &vector)
		return *this;

	this->size = vector.size;
	this->capacity = vector.capacity;

	delete[] this->elements;
	this->elements = new Bot[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = vector.elements[i];

	return *this;
}

template <typename TElem>
int DynamicVector<TElem>::addElement(const TElem& element)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->elements[i].getID() == element.getID())
			return 0;
	}
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size] = element;
	this->size++;
	return 1;
}

template <typename TElem>
int DynamicVector<TElem>::deleteElement(const std::string& ID)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->elements[i].getID() == ID)
		{
			this->elements[i] = this->elements[this->size - 1];
			this->size--;
			return 1;
		}
	}
	return 0;
}

template <typename TElem>
void DynamicVector<TElem>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	Bot* newElements = new Bot[this->capacity];
	for (int i = 0; i < this->size; i++)
		newElements[i] = this->elements[i];

	delete[] this->elements;
	this->elements = newElements;
}

template <typename TElem>
int DynamicVector<TElem>::getSize() const
{
	return this->size;
}

template <typename TElem>
TElem DynamicVector<TElem>::searchElement(std::string ID) {
	for (unsigned i = 0; i < this->size; i++) {
		if (this->elements[i].getID() == ID)
			return this->elements[i];
	}
	throw(10);
}

template <typename TElem>
Bot DynamicVector<TElem>::getElement(int position)
{
	return this->elements[position];
}
