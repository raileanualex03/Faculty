#pragma once
#include "Repository.h"
# include "Observer.h"
#include "Astronomer.h"
#include "Star.h"
class Controller : public Observable
{
private:
	Repository<Astronomer> repositoryAstronomers;
	Repository<Star> repositoryStars;
public:
	Controller(Repository<Astronomer> rA, Repository<Star> rS)
		: repositoryAstronomers{ rA }, repositoryStars{ rS }{};

	std::vector<Astronomer> getAstronomers() {
		return this->repositoryAstronomers.getAll();
	}
	std::vector<Star> getStars() {
		return this->repositoryStars.getAll();
	}

	// this function checks every needed condition for the star to be valid
	// throws exception if a condition isnt okay:)
	// then calls the add function from the repositoryStars
	void addStar(std::string name, std::string constelation, std::string ascension, std::string declination, std::string diameter);

	std::vector<Star> search(std::string name);

	void saveFile();

	friend class MyListTableModel;
};

