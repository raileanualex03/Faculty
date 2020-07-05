#pragma once
#include "genericRepository.h"
class Action
{
public:
	void virtual executeUndo() = 0;
	void virtual executeRedo() = 0;
};

