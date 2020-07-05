#pragma once
#include <string>
# include <fstream>
#include <vector>
#include "utils.h"
#include "Screenwriter.h"
#include "Idea.h"
class Repository
{
private:
	std::string filenameWriters;
	std::string filenameIdeas;
public:
	Repository(std::string f1, std::string f2) :filenameWriters{ f1 }, filenameIdeas{ f2 }{};

	void addIdea(Idea& idea) {
		std::ofstream fout(this->filenameIdeas, std::ios::app);
		for (auto i : this->getIdeas()) {
			if (i.getDescription() == idea.getDescription() && i.getAct() == idea.getAct())
				throw std::exception("already existing idea!");
		}
		fout << idea.toString()<<"\n";
		fout.close();
	}

	std::vector<Screenwriter> getWriters() {
		std::ifstream fin(this->filenameWriters);
		std::string line;
		std::vector<Screenwriter> writers;
		while (std::getline(fin, line)) {
			std::vector<std::string> params = tokenize(line, ',');
			std::string name, expertise;
			name = params[0];
			expertise = params[1];
			Screenwriter sw{ name, expertise };
			writers.push_back(sw);
		}

		return writers;
	}

	std::vector<Idea> getIdeas() {
		std::ifstream fin(this->filenameIdeas);
		std::string line;
		std::vector<Idea> ideas;
		while (std::getline(fin, line)) {
			std::vector<std::string> params = tokenize(line, ',');
			std::string description, status, creator;int act;
			description = params[0];
			status = params[1];
			creator = params[2];
			act = std::stoi(params[3]);
			Idea i{ description, status, creator, act };
			ideas.push_back(i);
		
		}
		return ideas;
	}

	void updateIdea(std::string description, int act) {
		std::vector<Idea> ideas;
		for (auto i : getIdeas()) {
			if (!(i.getDescription() == description && act == i.getAct())) {
				ideas.push_back(i);
			}
			else{
				Idea idea{ i.getDescription(), "accepted", i.getNameOfCreator(), i.getAct() };
				ideas.push_back(idea);
			}
		}
		std::ofstream fout(this->filenameIdeas);
		fout.close();
		for (auto i : ideas)
			this->addIdea(i);
	}

};

