#pragma once
#include "Domain.h"
#define CAPACITY 10

typedef void* TypeElement;

typedef struct
{
	int capacity;
	int size;
	TypeElement* elements;
} DynamicArray;

DynamicArray* createDynamicArray(int capacity);

DynamicArray* createCopyArray(DynamicArray* vector);

int resizeArray(DynamicArray* vector);

void addElementArray(DynamicArray* vector, TypeElement element);

int existBotArray(DynamicArray* vector, Bot* archive);

int getPositionBot(DynamicArray* vector, Bot* archive);

void deleteElementArray(DynamicArray* vector, int position);

void updateElementArray(DynamicArray* vector, int position, TypeElement element);

int getSizeArray(DynamicArray* vector);

TypeElement getElementOnPositionArray(DynamicArray* vector, int position);

void destroyDynamicArrayOfBots(DynamicArray* vector);

void destroyDynamicArrayOfLists(DynamicArray* vector);

void destroyDynamicArrayOfOperations(DynamicArray* vector);
