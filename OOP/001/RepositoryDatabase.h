#pragma once
#include "genericRepository.h"
# include <vector>
class RepositoryDatabase : public Repository
{
private:
	std::string databaseName;
public:
	RepositoryDatabase() {};

	unsigned addBot(const Bot& bot)override;

	unsigned removeBot(const Bot& bot) override;

	unsigned updateBot(const Bot& bot) override;

	std::vector<Bot> getElements();

	Bot searchBot(const std::string ID);

	unsigned setFilename(std::string DBName);

	std::string getType();

	unsigned existsBot(const std::string ID) override;

	void createTable();

	
};

