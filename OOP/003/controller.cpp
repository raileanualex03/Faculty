#include "controller.h"
#include <iostream>
#include "ActionAdd.h"
#include "ActionDelete.h"
#include "ActionUpdate.h"
# pragma once

vector<Bot> Controller::getElements()
{
	return this->repository->getElements(); 
}


unsigned Controller::addBot(const std::string& ID, const std::string& size, const std::string& radioactivityLevel, double& quantityOfMicrofragments, const std::string& digitizedScan)
{
	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
	if (this->repository->existsBot(ID) == 1)
		throw ExistenceException("This ID is already being used!\n");

	bool result = this->validator.validateAll(ID, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
	if (result == false)
		throw ExistenceException("This bot already exists!");

	// for undo & redo
	ActionAdd* action = new ActionAdd(*repository, bot);
	this->undoStack.push_back(action);
	// that's it for undo redo
	return this->repository->addBot(bot);
}

unsigned Controller::removeBot(const std::string& ID)
{
	bool result = this->validator.checkID(ID);
	
	if (this->repository->existsBot(ID) == 0)
		throw ExistenceException("No bots found with this ID\n");
	Bot bot = this->repository->searchBot(ID);

	// for undo & redo
	ActionDelete* action = new ActionDelete(*repository, bot);
	this->undoStack.push_back(action);
	// that's it

	return this->repository->removeBot(bot);
	
}

unsigned Controller::updateBot(const std::string& ID, const std::string& size, const std::string& radioactivityLevel, double& quantityOfMicrofragments, const std::string& digitizedScan)
{
	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
	bool result = this->validator.validateAll(ID, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
	if (result == false)
		return 0;
	if (this->repository->existsBot(ID) == 0)
		throw ExistenceException("No bot found with this ID\n");

	// for undo & redo
	Bot oldBot = this->repository->searchBot(ID);
	ActionUpdate* action = new ActionUpdate(*repository, oldBot, bot);
	this->undoStack.push_back(action);
	// that's it

	return this->repository->updateBot(bot);
}

unsigned Controller::assistantAddBot(std::string ID)
{
	if (this->repository->existsBot(ID) == false)
		throw ExistenceException("No bot found with this ID!\n");
	if (this->repositoryAssistant->existsBot(ID) == true)
		throw ExistenceException("This bot already exists!");
	Bot bot = this->repository->searchBot(ID);

	ActionAdd* action = new ActionAdd(*repositoryAssistant, bot);
	undoStackAssistant.push_back(action);

	int result = this->repositoryAssistant->addBot(bot);

	// for the synchronization
	this->notify();


	return result;
}

vector<Bot> Controller::assistantGetBots()
{
	return this->repositoryAssistant->getElements();

}

Bot Controller::getNextBot()
{
	if (this->positionRepositoryAssistant < this->repository->getElements().size() )
		this->positionRepositoryAssistant++;
	else
		this->positionRepositoryAssistant = 1;
	return this->repository->getElements().at(this->positionRepositoryAssistant-1);
	
}

unsigned Controller::setFilename(const std::string filename)
{
	return this->repository->setFilename(filename);
}

unsigned Controller::setFilenameAssistant(const std::string filename)
{
	return this->repositoryAssistant->setFilename(filename);
}

std::string Controller::getFilenameAssistant()
{
	return this->repositoryAssistant->getFilename();
}

std::string Controller::getTypeAssistant()
{
	return this->repositoryAssistant->getType();
}

std::vector<Bot> Controller::getBotsWithCertainSize(std::string size, double quantityOfMicrofragments)
{
	std::vector<Bot> elements;
	for (Bot bot : this->getElements()) {
		if (bot.getSize() == size && quantityOfMicrofragments <= bot.getQuantityOfMicrofragments())
			elements.push_back(bot);
	}

	return elements;
}

void Controller::undo()
{
	if (this->undoStack.size() == 0)
		throw std::exception("Unable to undo!");
	Action* action = this->undoStack.back();
	this->undoStack.pop_back();
	action->executeUndo();
	this->redoStack.push_back(action);
}

void Controller::redo()
{
	if (this->redoStack.size() == 0)
		throw std::exception("Unable to redo!");
	Action* action = this->redoStack.back();
	this->redoStack.pop_back();
	action->executeRedo();
	this->undoStack.push_back(action);
}

void Controller::undoAssistant()
{
	if (this->undoStackAssistant.size() == 0)
		throw std::exception("No elems added");
	Action* action = this->undoStackAssistant.back();
	
	action->executeUndo();
	this->redoStackAssistant.push_back(action); this->undoStackAssistant.pop_back();

	// for the synchronization
	this->notify();

}

void Controller::redoAssistant()
{
	if (this->redoStackAssistant.size() == 0)
		throw std::exception("No elems added");
	Action* action = this->redoStackAssistant.back(); 
	action->executeRedo();
	this->undoStackAssistant.push_back(action); 
	this->redoStackAssistant.pop_back();

	// for the synchronization
	this->notify();

}


