# include <assert.h>
# include "domain.h"

// test domain

void test_getSerialNumber__GoodInput__ReturnsValue() {
	Bot* bot = createBot(10, "abc", "def", 20);
	unsigned number = getSerialNumber(bot);
	assert(number == 10);
	printf("GetSerialNumber ->checked\n");
	destroyBot(bot);
	_CrtDumpMemoryLeaks();
}

void test_getState__GoodInput__ReturnsState() {
	Bot* bot = createBot(10, "Abc", "def", 20);
	char state[10];
	strcpy(state, getState(bot));
	assert(strcmp(state, "Abc") == 0);
	printf("GetState -> checked\n");
	destroyBot(bot);
	_CrtDumpMemoryLeaks();
}

void test_getSpecialization__GoodInput__ReturnsSpecialization() {
	Bot* bot = createBot(10, "Abc", "def", 20);
	char specialization[10];
	strcpy(specialization, getSpecialization(bot));
	assert(strcmp(specialization, "def") == 0);
	printf("GetSpecialization -> checked\n");
	destroyBot(bot);
	_CrtDumpMemoryLeaks();
}

void test_getEnergyCapacity__GoodInput__ReturnsValue() {
	Bot* bot = createBot(10, "Abc", "def", 20);
	unsigned energyCapacity = getEnergyCapacity(bot);
	assert(energyCapacity == 20);
	printf("GetEnergyCapacity -> checked\n");
	destroyBot(bot);
	_CrtDumpMemoryLeaks();
}

//void main() {
//	test_getSerialNumber__GoodInput__ReturnsValue();
//	test_getState__GoodInput__ReturnsState();
//	test_getSpecialization__GoodInput__ReturnsSpecialization();
//	test_getEnergyCapacity__GoodInput__ReturnsValue();
//}