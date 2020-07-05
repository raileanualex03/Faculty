#pragma once
#include "Action.h"
class ActionUpdate :
	public Action
{
private:
	Repository& repo;
	Bot newBot, oldBot;
public:
	ActionUpdate(Repository& repo, Bot oldBot, Bot newBot) :repo{ repo }, oldBot{ oldBot }, newBot{ newBot }{};

	void executeUndo() override;
	void executeRedo() override;
};

