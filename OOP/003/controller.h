# include "repositoryMemory.h"
#include "validator.h"
#include "repositoryFiles.h"
#include "Action.h"
# pragma once
# include "Observer.h"

class Controller:public Observable
{
private:
	Repository* repository;
	Validator validator;
	Repository* repositoryAssistant;
	unsigned positionRepositoryAssistant = 0;
	std::vector<Action*> undoStack;
	std::vector<Action*> redoStack;
	std::vector<Action*> undoStackAssistant;
	std::vector<Action*> redoStackAssistant;
public:
	// this is the default constructor 
	Controller(Repository* repository, Repository* repositoryAssistant) : repository{ repository }, validator{ Validator() }, repositoryAssistant{ repositoryAssistant } {};

	// this function wil return all the elements from the repository
	vector<Bot> getElements();

	// this function will get all the parameters needed for a bot
	// returns 1 if everything was fine
	// returns 0 if the parameters aren't valid or there is another bot with this ID
	unsigned addBot(const std::string& ID, const std::string& size, const std::string& radioactivityLevel, double& quantityOfMicrofragments, const std::string& digitizedScan);

	// this function will get the ID 
	// returns 1 if everything was fine
	// returns 0 if there is not any bot with this ID
	unsigned removeBot(const std::string& ID);

	// this function will get all the parameters needed for a bot to be updated
	// returns 1 if everything was fine
	// returns 0 if any of the newParameters weren't valid or if there is not any bot with this ID
	unsigned updateBot(const std::string& ID, const std::string& size, const std::string& radioactivityLevel, double& quantityOfMicrofragments, const std::string& digitizedScan);

	// this function will add a bot into the repositoryAssistant if the assistant saves him :)
	unsigned assistantAddBot(std::string);

	// this function will return all the bots :)
	vector<Bot> assistantGetBots();

	// this function will go to the next bot ;
	Bot getNextBot();

	unsigned setFilename(const std::string filename);

	unsigned setFilenameAssistant(const std::string filename);

	std::string getFilenameAssistant();

	std::string getTypeAssistant();

	std::vector<Bot> getBotsWithCertainSize(std::string size, double quantityOfMicrofragments);

	void undo();
	void redo();

	void undoAssistant();
	void redoAssistant();
	friend class MyListTableModel;
	
};