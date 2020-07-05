#pragma once
#include "Action.h"
class ActionAdd :
	public Action
{
private:
	Repository& repo;
	Bot bot;
public:
	ActionAdd(Repository& repo, Bot bot) :repo{ repo }, bot{ bot }{};

	void executeUndo() override;
	void executeRedo() override;
};

