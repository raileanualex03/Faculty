
# include <vector>
# pragma once
# include "genericRepository.h"
using std::vector;

class RepositoryMemory: public Repository 
{
private:
	vector<Bot> elements;
public:
	RepositoryMemory() {};

	unsigned addBot(const Bot& bot)override;

	unsigned removeBot(const Bot& bot) override;

	unsigned updateBot(const Bot& bot) override;

	vector<Bot> getElements();

	Bot searchBot(const std::string ID);

	unsigned existsBot(const std::string ID) override;

	unsigned setFilename(std::string filename) override;
	
	std::string getFilename() override;

	std::string getType() override;
};