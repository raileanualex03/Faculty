#include "ActionUpdate.h"

void ActionUpdate::executeUndo()
{
	this->repo.updateBot(oldBot);
}

void ActionUpdate::executeRedo()
{
	this->repo.updateBot(newBot);
}
