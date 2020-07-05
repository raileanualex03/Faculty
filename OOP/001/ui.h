

# include "controller.h"
# pragma once


class UserInterface 
{
private:
	Controller controller;
public:
	void run();

	UserInterface(const Controller& controller) : controller(controller){};


private:
	// this function will get the input and creates all the parameters needed from the input, then calls the controller->remove
	void addBot(char command[]);

	// this function will get the input and creates all the parameters needed from the input, then calls the controller->remove
	void removeBot(char command[]);

	// this function will get the input and creates all the parameters needed from the input, then calls the controller->update
	void updateBot(char command[]);

	// this function will print all the bots :)
	void showBots(char command[]);

	// this function will show the next bot
	void assistantNextBot();

	// this function will save the bot with this id
	void assistantSaveBot(char[]);

	// this function will show my list of bots
	void assistantMyList();

	// void show bots with specific size 
	void assistantShowAllBotsWithSize(char[]);

	void setFilename(std::string filename);

	void setFilenameAssistant(std::string filename);

	vector<std::string> getFunctionAndParameters(std::string input);

	void openWithApplication(std::string filename);
	
};
