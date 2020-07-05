#pragma once
#include "Repository.h"
# include "Observer.h"
class Controller: public Observable
{
private:
	Repository& repository;
public:
	Controller(Repository& r) :repository{ r } {};
	void addProgrammer(std::string id, std::string name);

	void addTask(std::string description, std::string status, std::string id);

	void removeTask(std::string description, std::string status, std::string id);

	std::vector<Programmer> getProgrammers();

	std::vector<Task> getTasks();
	
	void updateTask(Task& task, Programmer& p);

	void finishTask(Task& task);
};

