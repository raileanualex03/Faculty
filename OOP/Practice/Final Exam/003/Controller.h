#pragma once
#include "Repository.h"
#include <algorithm>
# include "Observer.h"

class Controller: public Observable
{
private:
	Repository& repository;
public:
	Controller(Repository& r) :repository{ r } {};
	void addIdea(std::string description, std::string status, std::string creator, std::string act) {
		if (status != "proposed" && status != "accepted")
			throw std::exception("Invalid status!");
		Idea i{ description, status, creator, std::stoi(act) };
		this->repository.addIdea(i);
		this->notify();
	}

	std::vector<Idea> getIdeas() {
		std::vector<Idea> ideas = this->repository.getIdeas();
		sort(ideas.begin(), ideas.end(), [](Idea i1, Idea i2) {
			return i1.getAct() < i2.getAct();
			});
		return ideas;
	}

	std::vector<Screenwriter> getWriters() {
		return this->repository.getWriters();
	}

	void updateIdea(std::string description, std::string act) {
		this->repository.updateIdea(description, std::stoi(act));
		this->notify();
	}
};

