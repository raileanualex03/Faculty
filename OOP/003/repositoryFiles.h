#pragma once
# include <vector>
#include "genericRepository.h"
class RepositoryFiles :
	public Repository
{
public:
	std::string filename;
	char type[4];
public:

	RepositoryFiles(std::string filename) { this->filename = filename; };

	RepositoryFiles() { this->filename = "noinput.txt"; };

	unsigned addBot(const Bot& bot) override;

	unsigned removeBot(const Bot& bot) override;

	unsigned updateBot(const Bot& bot) override;

	std::vector<Bot> getElements() override;

	Bot searchBot(const std::string ID) override;
	
	unsigned existsBot(const std::string ID) override;

	unsigned setFilename(const std::string filename);

	unsigned setTypeOfFile();

	std::string getType() override;

	std::string getFilename() override;

	void writeHeadHTML();

	void writeTailHTML();

	unsigned addBotToHTML(const Bot& bot);

	std::vector<Bot> getElementsFromHTML();

	bool isEmptyHTML();

	~RepositoryFiles() {};

	
};

