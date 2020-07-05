#include "Matrix.h"
#include <exception>
#include <stdio.h>
#include <iostream>
# include<vector>
using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
	this->lines = nrLines;
	this->columns = nrCols;
	head = NULL;
}
// time complexity is theta(1)


int Matrix::nrLines() const {
	return this->lines;
}
// time complexity is theta(1)


int Matrix::nrColumns() const {
	return this->columns;
}
// time complexity is theta(1)


TElem Matrix::element(int i, int j) const {
	if (i > this->nrLines() || i < 0)
		throw exception();
	if (j > this->nrColumns() || j < 0)
		throw exception();
	if (head != NULL) {
		Node* currentNode = head;
		while (currentNode != NULL)
		{

			// because it was sorted :)
			if (currentNode->line > i)
				return NULL_TELEM;
			if (currentNode->line == i && currentNode->column > j)
				return NULL_TELEM;
			if (currentNode->line == i && currentNode->column == j) {
				return currentNode->data;
			}

			currentNode = currentNode->next;
		}

	}
	return NULL_TELEM;


}// time complexity is O(n) where n is the number of elements modified

TElem Matrix::modify(int i, int j, TElem e) {

	if (i > this->nrLines() || i < 0)
		throw exception();
	if (j > this->nrColumns() || j < 0)
		throw exception();

	//check if the head is null

	if (head == NULL) {
		// if it is just create the first Node
		head = new Node{ i, j, e, NULL };
		return NULL_TELEM;
	}
	else
	{
		Node* lastNode = head;
		// here I get the last node :)
		while (lastNode->next != NULL)
			lastNode = lastNode->next;

		Node* currentNode = head;
		// here I check again if the currentNode in order not to dereference a nullptr
		if (currentNode == NULL)
			return NULL_TELEM;

		// here i get the Node with the same i and j
		Node* previousNode = head;
		while (currentNode->line != i || currentNode->column != j)
		{
			currentNode = currentNode->next;
			if (currentNode == NULL)
				break;
			previousNode = previousNode->next;
		}

		if (currentNode != NULL) {
			// check if the last element has i and j
			TElem oldData = currentNode->data;
			
			if (currentNode->line == i && currentNode->column == j)
			{
				
				// if the modifying data is NULL_TELEM we change it 
				if (e == NULL_TELEM) {
					currentNode->data = e;
					if (previousNode != NULL)
						previousNode->next = currentNode->next;
					else
						head = currentNode->next;
					//delete currentNode;
					
					return oldData;
				}
				oldData = currentNode->data;

				return oldData;
			}
		}

		if (e == NULL_TELEM)
			return NULL_TELEM;
		
		// node(0,1,1)->node(3,3,5)
		// last node contains the last element = "tail" 
		Node* newNode = new Node{ i, j, e, NULL };

		Node* prevNode = head;
		currentNode = head->next;
		if (head->next != NULL)
			while (currentNode != NULL) {
				if (prevNode->line > i) {
					head = newNode;
					head->next = prevNode;
					return NULL_TELEM;
				}
				if (prevNode->line == i && prevNode->column > j) {
					head = newNode;
					head->next = prevNode;
					return NULL_TELEM;
				}
				if (currentNode->line > i) {
					prevNode->next = newNode;
					newNode->next = currentNode;
					return NULL_TELEM;
				}
				if (currentNode->line == i && currentNode->column > j) {
					prevNode->next = newNode;
					newNode->next = currentNode;
					return NULL_TELEM;
				}
				prevNode = currentNode;
				currentNode = currentNode->next;
			}

		// if none of the cases of above were fine, we just put him at the end
		// these two if s take care if we have just one element and add the second one 
		lastNode->next = newNode;
		if (head->line > i) {
			Node* aux = head;
			head = newNode;
			head->next = aux;
			aux->next = NULL;
			return NULL_TELEM;
		}
		if (head->line == i && head->column > j) {
			Node* aux = head;
			head = newNode;
			head->next = aux;
			aux->next = NULL;
			return NULL_TELEM;
		}
		return NULL_TELEM;


	}
	//time complexity is theta(n)

}

void Matrix::transpose()
{
	vector<int> linesAdded;
	vector<int> columnsAdded;
	Node* currentNode = head;
	while (currentNode != NULL) {
		// node(0,2,1)
		// 0-2 
		bool checkIfAlreadyAdded = false;
		for (unsigned index = 0; index < linesAdded.size(); index++) {
			// check if every line added is equal to current column and every column added is equal to the line
			if (linesAdded[index] == currentNode->column && columnsAdded[index] == currentNode->line)
				// it means that we already changed them
				checkIfAlreadyAdded = true;
		}
		if (checkIfAlreadyAdded == false) {
			linesAdded.push_back(currentNode->line);
			columnsAdded.push_back(currentNode->column);
			TElem data1 = currentNode->data;
			TElem data2 = this->element(currentNode->column, currentNode->line);
			this->modify(currentNode->line, currentNode->column, data2);
			this->modify(currentNode->column, currentNode->line, data1);

			currentNode = currentNode->next;
		}
		else
			currentNode = currentNode->next;
	}

	// time complexity is theta(n^2);
	// where n is the number of elements in the linked list
}







