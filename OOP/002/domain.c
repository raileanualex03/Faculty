# include "domain.h"
# include <string.h>

#include <stdlib.h>


Bot* createBot(unsigned serialNumber, char state[], char specialization[], unsigned energyCapacity)
{
	Bot* bot = (Bot*)malloc(sizeof(Bot));
	if (bot == NULL)
		return -1;
	bot->serialNumber = serialNumber;
	strcpy(bot->state, state);
	strcpy(bot->specialization, specialization);
	bot->energyCapacity = energyCapacity;

	return bot;
}

Bot* createCopyBot(Bot* bot) {
	if (bot == NULL)
		return -1;

	Bot* newBot = (Bot*)malloc(sizeof(Bot));
	if (newBot == NULL)
		return -1;
	newBot->serialNumber = getSerialNumber(bot);
	strcpy(newBot->state, getState(bot));
	strcpy(newBot->specialization, getSpecialization(bot));
	newBot->energyCapacity = getEnergyCapacity(bot);

	return newBot;
}
unsigned getSerialNumber(Bot* bot)
{	
	if (bot == NULL)
		return -1;
	return bot->serialNumber;
}

unsigned getEnergyCapacity(Bot* bot)
{
	if (bot == NULL)
		return -1;
	return bot->energyCapacity;
}

char* getState(Bot* bot)
{
	if (bot == NULL)
		return -1;
	return bot->state;
}

char* getSpecialization(Bot* bot)
{
	if (bot == NULL)
		return -1;
	return bot->specialization;
}

void destroyBot(Bot* bot)
{
	free(bot);
}


//
//Operation* createOperation(Bot* botUndo, Bot* botRedo, char stringOperation[])
//{
//	Operation* operation = (Operation*)malloc(sizeof(Operation));
//	if (operation == NULL)
//		return -1;
//	operation->botRedo = botRedo;
//	operation->botUndo = botUndo;
//	strcpy(operation->stringOperation, stringOperation);
//
//	return operation;
//}
//
//Bot* getBotUndo(Operation* operation)
//{
//	if (operation == NULL)
//		return -1;
//	return operation->botUndo;
//}
//
//Bot* getBotRedo(Operation* operation)
//{
//	if (operation == NULL)
//		return -1;
//	return operation->botRedo;
//}
//
//char* getStringOperation(Operation* operation)
//{
//	if (operation == NULL)
//		return -1;
//}
//	return operation->stringOperation;
