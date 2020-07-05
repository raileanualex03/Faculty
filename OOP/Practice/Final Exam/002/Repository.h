#pragma once
# include <vector>
#include "Programmer.h"
#include "Task.h"
class Repository
{
private:
	std::string filenameProgrammer;
	std::string filenameTask;
public:
	Repository(std::string filenameP, std::string filenameT) : filenameProgrammer{ filenameP }, filenameTask{ filenameT } {};
	
	void addProgrammer(Programmer& programmer);
	
	void addTask(Task& task);
	
	void removeTask(Task& task);
	
	std::vector<Programmer> getProgrammers();
	
	std::vector<Task> getTasks();
};

