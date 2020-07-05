#include "AppConfigurations.h"
# include <fstream>
# include <sstream>
#include "utils.h"
#include "repositoryFiles.h"
#include "repositoryMemory.h"
void AppConfigurations::checkFile()
{
	std::ifstream fileInput(this->settingsFilename);
	std::string firstLine, secondLine;

	std::getline(fileInput, firstLine);
	std::getline(fileInput, secondLine);

	std::vector<std::string> parametersFirstLine = tokenize2(firstLine, '=');
	std::vector<std::string> parametersSecondLine = tokenize2(secondLine, '=');

	if (parametersFirstLine[1] == "memory") {
		this->codeRepositoryModeA = 2;
	}
	else {
		this->codeRepositoryModeA = 1;
		administratorRepositoryName = parametersFirstLine[1];
	}
	if (parametersSecondLine[1] == "memory") {
		this->codeRepositoryModeB = 2;
	}
	else {
		this->codeRepositoryModeB = 1;
		assistantRepositoryName = parametersSecondLine[1];
	}
	
}

std::vector<Repository*> AppConfigurations::getRepositories()
{
	checkFile();
	std::vector<Repository*> repositories;
	if (this->codeRepositoryModeA == 1) {
		RepositoryFiles* repo = new RepositoryFiles(this->administratorRepositoryName);
		if (this->codeRepositoryModeB == 1) {
			RepositoryFiles* repoAssistant = new RepositoryFiles(this->assistantRepositoryName);
			repositories.push_back(repo);
			repositories.push_back(repoAssistant);

		}
		else {
			RepositoryMemory* repoAssistant = new RepositoryMemory();
			repositories.push_back(repo);
			repositories.push_back(repoAssistant);
		}


	}
	else {
		RepositoryMemory* repo = new RepositoryMemory();

		if (this->codeRepositoryModeB == 1) {
			RepositoryFiles* repoAssistant = new RepositoryFiles(this->assistantRepositoryName);
			repositories.push_back(repo);
			repositories.push_back(repoAssistant);

	
		}
		else {
			RepositoryMemory* repoAssistant = new RepositoryMemory();
			repositories.push_back(repo);
			repositories.push_back(repoAssistant);
		}
	}

	return repositories;
}
