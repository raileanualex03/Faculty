#include "ActionDelete.h"

void ActionDelete::executeUndo()
{
	this->repo.addBot(bot);
}

void ActionDelete::executeRedo()
{
	this->repo.removeBot(bot);
}
