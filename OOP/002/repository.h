# include "domain.h"
# include "dynamicArray.h"

typedef struct {
	DynamicArray* bots;
}Repository;

Repository* createRepository();

int repositoryAddBot(Repository* repository, Bot* bot);

int repositoryDeleteBot(Repository* repository, Bot* bot);

int repositoryUpdateBot(Repository* repository, Bot* bot);

int getRepositorySize(Repository* repository);

Bot* getBotOnPosition(Repository* repository, unsigned position);

Bot* repositoryGetBot(Repository* repository, Bot* bot);

DynamicArray* repositoryGetAllBots(Repository* repository);

void destroyRepository(Repository* repository);

