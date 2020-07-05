#include "Repository.h"
# include <fstream>
#include "utils.h"
# include <ostream>
void Repository::addProgrammer(Programmer& programmer)
{
	for (auto p : this->getProgrammers()) {
		if (p.getID() == programmer.getID())
			throw std::exception("already existing programmer!");
	}
	std::ofstream fout(this->filenameProgrammer, std::ios::app);
	fout << programmer.toString()<<"\n";
	fout.close();
}

void Repository::addTask(Task& task)
{
	std::ofstream fout(this->filenameTask, std::ios::app);
	for (auto t : this->getTasks()) {
		if (t.getDescription() == task.getDescription())
			throw std::exception("Already existing task!");
	}
	fout << task.toString() << "\n";
}

void Repository::removeTask(Task& task)
{
	std::vector<std::string> lines;
	std::string line;
	bool ok = false;
	std::ifstream fin(this->filenameTask);
	while (std::getline(fin, line)) {
		lines.push_back(line);
	}
	fin.close();
	std::ofstream foutn(this->filenameTask);
	foutn.close();
	std::ofstream fout(this->filenameTask, std::ios::app);
	for (auto line : lines) {
		if (line != task.toString()) {
			
			fout << line<<"\n";
		}
		else {
			ok = true;
		}
	}
	fout.close();
	if (ok == false)
		throw std::exception("No task found!");
}

std::vector<Programmer> Repository::getProgrammers()
{
	std::vector<Programmer> programmers;
	std::string line;
	std::ifstream fin(this->filenameProgrammer);
	while (std::getline(fin, line)) {
		std::vector<std::string> parameters= tokenize(line, ',');
		std::string name;
		int id;
		name = parameters[0];
		id = std::stoi(parameters[1]);
		Programmer p{ name, id };
		programmers.push_back(p);
	}

	return programmers;
}

std::vector<Task> Repository::getTasks()
{
	std::vector<Task> tasks;
	std::string line;
	std::ifstream fin(this->filenameTask);
	while (std::getline(fin, line)) {
		std::vector<std::string> parameters = tokenize(line, ',');
		std::string description;
		std::string name;
		int id;
		description = parameters[0];
		name = parameters[1];
		id = std::stoi(parameters[2]);
		Task t{ description, name, id };
		tasks.push_back(t);
	}

	return tasks;
}
