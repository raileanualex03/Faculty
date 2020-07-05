#include "ui.h"
# pragma once
# include <iostream>
# include <sstream>

using namespace std;

void UserInterface::run()
{
	std::string input, mode, filename, filenameAssistant;
	getline(cin, filename);
	vector<string> parameters = getFunctionAndParameters(filename);
	this->setFilename(parameters[1]);
	getline(cin, filenameAssistant);
	vector<string> parametersAssistant = getFunctionAndParameters(filenameAssistant);
	this->setFilenameAssistant(parametersAssistant[1]);
	char inputAsChars[64];
	getline(cin, mode);
		while (true) {
			try
			{
				
				if (mode == "mode A") {
					getline(cin, input);
					if (input == "exit")
						return;
					strcpy(inputAsChars, input.c_str());
					if(strstr(inputAsChars, "exit") != 0)
						return;
					if (strstr(inputAsChars, "add") != 0)
						addBot(inputAsChars);
					else if (strstr(inputAsChars, "delete") != 0)
						removeBot(inputAsChars);
					else if (strstr(inputAsChars, "update") != 0)
						updateBot(inputAsChars);
					else if (strstr(inputAsChars, "list") != 0)
						showBots(inputAsChars);
					else if (input == "mode B") {
						mode = "mode B";
					}
					else throw(999);
				}
				else if (mode == "mode B") {
					getline(cin, input);
					if (input == "exit")
						return;
					strcpy(inputAsChars, input.c_str());
					if (strstr(inputAsChars, "save"))
						assistantSaveBot(inputAsChars);
					else if (strstr(inputAsChars, "next"))
						assistantNextBot();
					else if (strstr(inputAsChars, "mylist"))
						assistantMyList();
					else if (strstr(inputAsChars, "list"))
						assistantShowAllBotsWithSize(inputAsChars);
					else if (strstr(inputAsChars, "mode A\n"))
						mode = "mode A";
					else if (strstr(inputAsChars, "open"))
						this->openWithApplication(parametersAssistant[1]);
					else throw(999);
				}
			}
			catch (ValidationException& exception) {
				cout << exception.getMessage();
			}
			catch (ExistenceException& exception) {
				cout << exception.getMessage();
			}
				
			catch (int errorCode)
				{
				if (errorCode == 999) {
					cout << "Invalid command! \n";
				}
					if (errorCode == 1)
						cout << "add Failed! \n";
					if (errorCode == 2)
						cout << "remove Failed! \n";
					if (errorCode == 3)
						cout << "update Failed! \n";

				}
				
			
		}
	
		exit(0);
}

void UserInterface::addBot(char command[])
{
	char* words;
	std::string ID, size, radioactivityLevel, digitizedScan;
	double quantityOfMicrofragments = 0;
	unsigned counterParametersOrder = 0;
	words = strtok(command, " , ");
	while (words || counterParametersOrder < 5) {
		if (counterParametersOrder == 1)
			ID = words;

		else if (counterParametersOrder == 2)
			size = words;

		else if (counterParametersOrder == 3)
			radioactivityLevel = words;

		else if (counterParametersOrder == 4) 
			quantityOfMicrofragments = atof(words);

		else if (counterParametersOrder == 5)
			digitizedScan = words;
	
		counterParametersOrder++;
		words = strtok(NULL, " , ");
	}
	int result = this->controller.addBot(ID, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
	if (result == 0)
		throw(1);
}

void UserInterface::removeBot(char command[])
{
	char* words;
	std::string ID;
	unsigned counterParametersOrder = 0;
	words = strtok(command, " , ");
	while (words) {
		if (counterParametersOrder == 1)
			ID = words;

		counterParametersOrder += 1;
		words = strtok(NULL, " , ");
	}
	int result = this->controller.removeBot(ID);
	if (result == 0)
		throw(2);
}

void UserInterface::updateBot(char command[])
{
	char* words;
	std::string ID, size, radioactivityLevel, digitizedScan;
	double quantityOfMicrofragments = 0;
	unsigned counterParametersOrder = 0;
	words = strtok(command, " , ");
	while (words || counterParametersOrder < 5) {
		if (counterParametersOrder == 1)
			ID = words;

		else if (counterParametersOrder == 2)
			size = words;

		else if (counterParametersOrder == 3)
			radioactivityLevel = words;

		else if (counterParametersOrder == 4)
			quantityOfMicrofragments = atof(words);

		else if (counterParametersOrder == 5)
			digitizedScan = words;

		counterParametersOrder++;
		words = strtok(NULL, " , ");
	}

	int result = this->controller.updateBot(ID, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
	if (result == 0)
		throw(3);

}

void UserInterface::showBots(char command[])
{
	vector<Bot> vector = this->controller.getElements();
	for (unsigned index = 0; index < vector.size();  index++) {
		cout << vector.at(index).ToString();
		cout << '\n';
	}
}

void UserInterface::assistantNextBot()
{
	Bot bot = this->controller.getNextBot();
	cout << bot.ToString()<< '\n';
}


void UserInterface::assistantSaveBot(char command[])
{
	char* words = strtok(command, " ,");
	unsigned counterParametersOrder = 0;
	std::string ID;
	while (words) {
		if (counterParametersOrder == 1)
			ID = words;
		counterParametersOrder++; 
		words = strtok(NULL, " , ");
	}
	this->controller.assistantAddBot(ID);
}

void UserInterface::assistantMyList()
{
	vector<Bot> vector = this->controller.assistantGetBots();
	for (unsigned index = 0; index < vector.size(); index++) {
		cout << vector.at(index).ToString() << '\n';
	}
}

void UserInterface::assistantShowAllBotsWithSize(char command[])
{
	char* words = strtok(command, " , ");
	unsigned counterParametersOrder = 0;
	std::string size;
	double quantityOfMicrofragments=0;
	while (words) {
		if (counterParametersOrder == 1)
			size = words;
		if (counterParametersOrder == 2)
			quantityOfMicrofragments = atof(words);
		words = strtok(NULL, " , ");
		counterParametersOrder++;
	}

	vector<Bot> vector = this->controller.getElements();
	for (unsigned index = 0; index < vector.size(); index++) {
		Bot bot = vector.at(index);
		if (bot.getSize() == size && bot.getQuantityOfMicrofragments() > quantityOfMicrofragments)
			cout << bot.ToString() << '\n';
	}
}

void UserInterface::setFilename(std::string filename)
{
	this->controller.setFilename(filename);
}

void UserInterface::setFilenameAssistant(std::string filename)
{
	this->controller.setFilenameAssistant(filename);
}

vector<string> UserInterface::getFunctionAndParameters(std::string input)
{
	
		vector<string> vectorOfParameters;
		stringstream streamToGetParameters(input);
		string parameter;
		getline(streamToGetParameters, parameter, ' ');
		vectorOfParameters.push_back(parameter);
		while (getline(streamToGetParameters, parameter, ','))
		{
			if (vectorOfParameters.size() != 1)
				parameter.erase(parameter.begin());
			vectorOfParameters.push_back(parameter);
		}
		return vectorOfParameters;
	
}

void UserInterface::openWithApplication(std::string filename)
{	
	std::string command = "start chrome " + filename;
	if (this->controller.getTypeAssistant() == "html")
		system(command.c_str());
	command = "start excel " + filename;
	if (this->controller.getTypeAssistant() == "csv")
		system(command.c_str());
}


