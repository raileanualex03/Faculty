#include "repository.h"

Repository* createRepository()
{
	Repository* repository = (Repository*)malloc(sizeof(Repository));
	if (repository == NULL)
		return NULL;
	repository->bots = createDynamicArray(CAPACITY);
	return repository;
}

int repositoryAddBot(Repository* repository, Bot* bot)
{
	if (repository == NULL || bot == NULL)
		return -1;
	if (existBotArray(repository->bots, bot) == 0) {
		addElementArray(repository->bots, bot);
		return 1;
	}
	return 0;
}

int repositoryDeleteBot(Repository* repository, Bot* bot)
{
	if (repository == NULL || bot == NULL)
		return -1;
	if (existBotArray(repository->bots, bot) == 1) {
		unsigned position = getPositionBot(repository->bots, bot);
		deleteElementArray(repository->bots, position);
		return 1;
	}
	else return 0;
}

int repositoryUpdateBot(Repository* repository, Bot* bot)
{
	if (repository == NULL || bot == NULL)
		return -1;
	if (existBotArray(repository->bots, bot) == 0) {
		unsigned position = getPositionBot(repository->bots, bot);
		updateElementArray(repository->bots, position, bot);
		return 1;
	}
	return 0;
}

int getRepositorySize(Repository* repository)
{
	if (repository == NULL)
		return -1;
	return getSizeArray(repository->bots);
}

Bot* getBotOnPosition(Repository* repository, unsigned position)
{
	if (repository == NULL)
		return -1;
	return getElementOnPositionArray(repository->bots, position);
}

Bot* repositoryGetBot(Repository* repository, Bot* bot)
{
	if (repository == NULL || bot == NULL)
		return -1;
	if (existBotArray(repository->bots, bot) == 1) {
		unsigned position = getPositionBot(repository->bots, bot);
		return getBotOnPosition(repository->bots, bot);
	}

}

DynamicArray* repositoryGetAllBots(Repository* repository)
{
	if (repository == NULL)
		return -1;
	DynamicArray* bots = createDynamicArray(10);
	unsigned size = getSizeArray(repository->bots);
	for (unsigned index = 0; index < repository->bots->size; index++) {

		Bot* bot = getElementOnPositionArray(repository->bots, index);
		bot = createCopyBot(bot);
		addElementArray(bots, bot);
	}
	return bots;
}

void destroyRepository(Repository* repository)
{
	if (repository == NULL)
		return -1;
	destroyDynamicArrayOfBots(repository->bots);
	free(repository);
}
