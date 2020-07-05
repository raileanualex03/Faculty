
# include "domain.h"
# pragma once
# include <vector>

class Repository
{

public:
	
	// this function gets the bot as a parameter, then calls dynamicVector->addElementToVector
	// returns 0 if there is another bot with this ID
	// returns 1 if it's okay everything
	virtual unsigned addBot(const Bot& bot) = 0;

	// this function gets the bot as a parameter, then calls dynamicVector->removeElement
	// throws 10 if there is not any bot with that ID
	// returns 1 if everything is okay
	virtual unsigned removeBot(const Bot& bot) = 0;

	// this function gets the bot as a parameter, then removes the oldBot and adds Bot 
	// returns 1 if everything was fine
	// returns 0 otherwise
	virtual unsigned updateBot(const Bot& bot) = 0;

	// this function returns all the elements of the repository 
	virtual std::vector<Bot> getElements() = 0;

	// this function returns a bot if 
	virtual Bot searchBot(const std::string ID) = 0;

	virtual unsigned existsBot(const std::string ID) = 0;

	virtual unsigned setFilename(const std::string) = 0;

	virtual std::string getFilename() = 0;
	virtual std::string getType() = 0;

};