#include "controller.h"
#include <stdio.h>
#include <stdlib.h>

Controller* createController(Repository* repository)
{
	Controller* controller = (Controller*)malloc(sizeof(Controller));
	if (controller == NULL)
		return -1;
	controller->repository = repository;
	controller->stack = createStack();

	return controller;
}

int controllerAddBot(Controller* controller, unsigned serialNumber, char state[], char specialization[], unsigned energyCapacity)
{
	if (controller == NULL)
		return -1;
	Bot* bot = createBot(serialNumber, state, specialization, energyCapacity);
	unsigned number = repositoryAddBot(controller->repository, bot);
	if (number == 1) {
		// this manages the stack for undo/redo
		stackAddList(controller->stack, repositoryGetAllBots(controller->repository));
	}
	else {
		destroyBot(bot);
	}
	return number;
}

int controllerDeleteBot(Controller* controller, unsigned serialNumber)
{
	if (controller == NULL)
		return -1;
	Bot* botToRemove = createBot(serialNumber, " ", " ", 0);
	Bot* bot = createCopyBot(repositoryGetBot(controller->repository, botToRemove));
	unsigned number = repositoryDeleteBot(controller->repository, bot);

	if (number == 1) {
		// this manages the stack for undo/redo
		stackAddList(controller->stack, repositoryGetAllBots(controller->repository));
		destroyBot(botToRemove);
	}

	destroyBot(bot);
	return number;
}

int controllerUpdateBot(Controller* controller, unsigned serialNumber, char state[], char specialization[], unsigned energyCapacity)
{
	if (controller == NULL)
		return -1;
	Bot* bot = createBot(serialNumber, state, specialization, energyCapacity);
	unsigned number = repositoryUpdateBot(controller->repository, bot);
	if (number == 1) {
		// this manages the stack for undo/redo
		stackAddList(controller->stack, repositoryGetAllBots(controller->repository));
		return 1;
	}
	destroyBot(bot);
	return number;
}


Bot* getAllBots(Controller* controller)
{
	if (controller == NULL)
		return -1;
	return repositoryGetAllBots(controller->repository);
}

unsigned getRepositoryCurrentPosition(Controller* controller, Bot* bot)
{
	if (controller == NULL || bot == NULL)
		return -1;
	return getPositionBot(controller->repository, bot);
}

unsigned controllerUndo(Controller* controller) {
	if (controller == NULL)
		return -1;
	unsigned number = stackUndo(controller->stack);
	if (number == 0)
		return 0;
	else {
		Repository* repository = controller->repository;
		destroyDynamicArrayOfBots(repository->bots);
		DynamicArray* undoList = createCopyArray(stackGetLastList(controller->stack));
		repository->bots = undoList;
	}
}

unsigned controllerRedo(Controller* controller) {
	if (controller == NULL)
		return -1;
	unsigned number = stackRedo(controller->stack);
	if (number == 0)
		return 0;
	else {
		Repository* repository = controller->repository;
		destroyDynamicArrayOfBots(repository->bots);
		DynamicArray* redoList = createCopyArray(stackGetLastList(controller->stack));
		repository->bots = redoList;
	}
}
void destroyController(Controller* controller)
{
	destroyRepository(controller->repository);
	destroyStack(controller->stack);
	free(controller);
}
