#pragma once
#include "Action.h"
class ActionDelete :
	public Action
{
private:
	Repository& repo;
	Bot bot;
public:
	ActionDelete(Repository& repo, Bot bot) :repo{ repo }, bot{ bot }{};

	void executeUndo() override;
	void executeRedo() override;
};

