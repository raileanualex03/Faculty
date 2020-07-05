#include "ActionAdd.h"

void ActionAdd::executeUndo()
{
	this->repo.removeBot(bot);
}

void ActionAdd::executeRedo()
{
	this->repo.addBot(bot);
}
