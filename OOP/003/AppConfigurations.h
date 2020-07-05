#pragma once
#include <string>
#include <vector>
# include "genericRepository.h"
class AppConfigurations
{
private:
	std::string settingsFilename;
public:
	AppConfigurations(std::string file) :settingsFilename{file}{}
	std::string administratorRepositoryName="";
	std::string assistantRepositoryName="";
	int codeRepositoryModeA = 0;
	int codeRepositoryModeB = 0;

	void checkFile();
	std::vector<Repository*> getRepositories();

};

