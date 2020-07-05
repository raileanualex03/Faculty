# include <stdio.h>
# include <stdlib.h>
#pragma once

typedef struct Bot {
	unsigned serialNumber;
	char state[10];
	char specialization[10];
	unsigned energyCapacity;
}Bot;

Bot* createBot(unsigned serialNumber, char state[], char specialization[], unsigned energyCapacity);

Bot* createCopyBot(Bot* bot);

unsigned getSerialNumber(Bot* bot);

unsigned getEnergyCapacity(Bot* bot);

char* getState(Bot* bot);

char* getSpecialization(Bot* bot);

void destroyBot(Bot* bot);

//
//typedef struct Operation {
//	 Bot* botUndo;
//	 Bot* botRedo;
//	 char stringOperation[10];
//}Operation;
//
//Operation* createOperation(Bot* botUndo, Bot* botRedo, char stringOperation[]);
//
//Bot* getBotUndo(Operation* operation);
//
//Bot* getBotRedo(Operation* operation);
//
//char* getStringOperation(Operation* operation);
//	