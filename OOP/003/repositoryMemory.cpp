#include "repositoryMemory.h" 
# pragma once


unsigned RepositoryMemory::addBot(const Bot& bot)
{	
	// returns 1 if the bot were added, 0 otherwise
	if (this->existsBot(bot.getID()) == 1)
		return 0;
	this->elements.push_back(bot);
	return 1;
}

unsigned RepositoryMemory::removeBot(const Bot& bot)
{
	if (this->existsBot(bot.getID()) == 0)
		return 0;
	auto iterator = this->elements.begin();
	while (iterator < this->elements.end() ) {
		if (this->elements.at(iterator - this->elements.begin()).getID() == bot.getID()) {
			this->elements.erase(iterator);
			break;
		}
		iterator += 1;
	}
	return 1;
}
unsigned RepositoryMemory::updateBot(const Bot& bot)
{
	if (this->existsBot(bot.getID()) == 0)
		return 0;
	this->removeBot(bot);
	this->addBot(bot);
	return 1;
}

vector<Bot> RepositoryMemory::getElements()
{
	return this->elements;
}

Bot RepositoryMemory::searchBot(const std::string ID) {
	for (auto i: this->elements) 
		if (i.getID() == ID)
			return i;
}

unsigned RepositoryMemory::existsBot(const std::string ID)
{
	for (auto bot : this->elements) 
		if (bot.getID() == ID)
			return 1;
	return 0;
}

unsigned RepositoryMemory::setFilename(std::string filename)
{
	return 0;
}

std::string RepositoryMemory::getFilename()
{
	return std::string();
}

std::string RepositoryMemory::getType()
{
	return std::string();
}


