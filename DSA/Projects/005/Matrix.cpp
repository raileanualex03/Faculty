#include "Matrix.h"
#include <exception>
#include <iostream>
#include <vector>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
	this->head = NULL;
	this->lines = nrLines;
	this->columns = nrCols;
}  // time complexity is theta(1)


int Matrix::nrLines() const {
	
	return this->lines;
}  // time complexity is theta(1)


int Matrix::nrColumns() const {
	//TODO - Implementation
	return this->columns;
} // time complexity is theta(1)


TElem Matrix::element( int i, int j) {
	
	if (i > this->nrLines() || i < 0 || j >this->nrColumns() || j < 0)
		throw std::exception();

	Elem* elemFound = search_recursively(head, i, j);
	if (elemFound == NULL) {
		// it means that the element is not in the list
		return NULL_TELEM;
	}
	else {
		return elemFound->value;
	}
}// time complexity is O(n)

Elem* Matrix::search_recursively(Node* node, int i, int j)
{
	// check if we haven't reached a dead end
	if (node == NULL)
		return NULL;
	if (node->elem->line == i && node->elem->column == j)
		return node->elem;
	if (node->elem->line < i)
		search_recursively(node->left, i, j);
	else
		search_recursively(node->right, i, j);
}		// time complexity is O(n)

TElem Matrix::modify(int i, int j, TElem e) {
	// preconditions :)
	if (i > this->nrLines() || i < 0 || j >this->nrColumns() || j < 0)
		throw std::exception();

	if (head == NULL) {
		Elem* elem = new Elem{ e, i, j };
		Node* node = new Node{ elem, NULL, NULL, NULL };
		// created the node;
		head = node;
		return NULL_TELEM;
	}
	else {
		// if the head is not NULL
		Node* parent = insert_recursively(head, i, j);

		TElem oldValue;
		if (parent->elem->line == i && parent->elem->column == j) {
			oldValue = parent->elem->value;
			parent->elem->value = e;
			return oldValue;
		}
		else {
			oldValue = NULL_TELEM;
			

			if (parent->left == NULL) {
				Elem* elem = new Elem{ e, i, j };
				Node* node = new Node{ elem, parent, NULL, NULL };
				parent->left = node;
			}
			if (parent->right == NULL) {
				Elem* elem = new Elem{ e, i, j };
				Node* node = new Node{ elem, parent, NULL, NULL };
				parent->right = node;
			}

			return oldValue;
		}

		return oldValue;
	}
} // time complexity is O(n)

Node* Matrix::insert_recursively(Node* node, int i, int j)
{
	if (node->elem->line == i && node->elem->column == j)
		return node;
	if (node->left == NULL || node->right == NULL)
		return node;
	if (node->elem->line < i)
		insert_recursively(node->left, i, j);
	else
		insert_recursively(node->right, i, j);

} // time complexity is O(n)

int Matrix::numberOfNonZeroElems(int col)
{
	int counter = 0;
	int linesIndex = 0;
	while (linesIndex < this->nrLines()) {
		int result = element(linesIndex, col);
		if (result != NULL_TELEM)
			counter += 1;
		linesIndex++;
	}

	return counter;
	
} // time complexity is theta(k*n)


