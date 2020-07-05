#include "controller.h"
#include <iostream>
# pragma once

vector<Bot> Controller::getElements()
{
	return this->repository.getElements(); 
}


unsigned Controller::addBot(const std::string& ID, const std::string& size, const std::string& radioactivityLevel, double& quantityOfMicrofragments, const std::string& digitizedScan)
{
	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
	if (this->repository.existsBot(ID) == 1)
		throw ExistenceException("This ID is already being used!\n");

	bool result = this->validator.validateAll(ID, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
	if (result == false)
		throw ExistenceException("This bot already exists!");
	return this->repository.addBot(bot);
}

unsigned Controller::removeBot(const std::string& ID)
{
	bool result = this->validator.checkID(ID);
	
	if (this->repository.existsBot(ID) == 0)
		throw ExistenceException("No bots found with this ID\n");
	Bot bot = this->repository.searchBot(ID);
	return this->repository.removeBot(bot);
	
}

unsigned Controller::updateBot(const std::string& ID, const std::string& size, const std::string& radioactivityLevel, double& quantityOfMicrofragments, const std::string& digitizedScan)
{
	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
	bool result = this->validator.validateAll(ID, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
	if (result == false)
		return 0;
	if (this->repository.existsBot(ID) == 0)
		throw ExistenceException("No bot found with this ID\n");
	return this->repository.updateBot(bot);
}

unsigned Controller::assistantAddBot(std::string ID)
{
	if (this->repository.existsBot(ID) == false)
		throw ExistenceException("No bot found with this ID!\n");
	Bot bot = this->repository.searchBot(ID);
	return this->repositoryAssistant.addBot(bot);
}

vector<Bot> Controller::assistantGetBots()
{
	return this->repositoryAssistant.getElements();

}

Bot Controller::getNextBot()
{
	if (this->positionRepositoryAssistant < this->repository.getElements().size() )
		this->positionRepositoryAssistant++;
	else
		this->positionRepositoryAssistant = 1;
	return this->repository.getElements().at(this->positionRepositoryAssistant-1);
	
}

unsigned Controller::setFilename(const std::string filename)
{
	return this->repository.setFilename(filename);
}

unsigned Controller::setFilenameAssistant(const std::string filename)
{
	return this->repositoryAssistant.setFilename(filename);
}

std::string Controller::getTypeAssistant()
{
	return this->repositoryAssistant.getType();
}

