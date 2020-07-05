#include "Controller.h"
# include <algorithm>
void Controller::addStar(std::string name, std::string constelation, std::string ascension, std::string declination, std::string diameter)
{
	if (name.length() == 0)
		throw std::exception("provide name");
	if (std::stoi(diameter) < 0)
		throw std::exception("diameter must be greater than 0");
	for (auto s : this->repositoryStars.getAll()) {
		if (s.getName() == name)
			throw std::exception("already existing star with this name");
	}
	Star s{ name, constelation, std::stoi(ascension), std::stoi(declination), std::stoi(diameter) };
	this->repositoryStars.add(s);


	this->notify();
}

std::vector<Star> Controller::search(std::string name)
{
	std::vector<Star> elems;
	for (auto s : this->getStars()) {
		if (s.getName().find(name) != std::string::npos)
			elems.push_back(s);
	}

	return elems;
}

void Controller::saveFile()
{
	std::vector<Star> stars = this->getStars();
	std::ofstream f("stars.txt");
	f.close();
	std::sort(stars.begin(), stars.end(), [](Star s1, Star s2) {
		return s1.getConstellation() < s2.getConstellation();
		});
	for (auto s : stars)
		this->repositoryStars.add(s);
}
