#include "dynamicArray.h"
#include "repository.h"
#include "stack.h"


typedef struct Controller {
	Repository* repository;
	Stack* stack;
}Controller;

Controller* createController(Repository* repository);

int controllerAddBot(Controller* controller, unsigned, char state[], char specialization[], unsigned);

int controllerDeleteBot(Controller* controller, unsigned);

int controllerUpdateBot(Controller* controller, unsigned, char, char, unsigned);

Bot* getAllBots(Controller* controller);

unsigned getRepositoryCurrrentPosition(Controller* controller);

void destroyController(Controller* controller);
