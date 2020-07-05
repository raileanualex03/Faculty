#pragma once
#include "dynamicArray.h"
#include "domain.h"


// this will contain the stack for lists :)
typedef struct
{
	DynamicArray* lists;
	int index;
	int lengthOfLists;
} Stack;

Stack* createStack();
void stackAddList(Stack* stack, DynamicArray* list);
int stackUndo(Stack* stack);
int stackRedo(Stack* stack);
DynamicArray* stackGetLastList(Stack* stack);
void destroyStack(Stack* stack);

