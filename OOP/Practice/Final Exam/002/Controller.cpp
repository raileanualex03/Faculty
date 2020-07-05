#include "Controller.h"

void Controller::addProgrammer(std::string id, std::string name)
{
	Programmer p{ name, std::stoi(id) };
	this->repository.addProgrammer(p);
}

void Controller::addTask(std::string description, std::string status, std::string id)
{
	if (status != "open" && status != "in progress" && status != "closed")
		throw std::exception("bad status!");
	Task t{ description, status, std::stoi(id) };
	this->repository.addTask(t);
	this->notify();

}

void Controller::removeTask(std::string description, std::string status, std::string id)
{
	if (status != "open" && status != "in progress" && status != "closed")
		throw std::exception("bad status!");
	Task t{ description, status, std::stoi(id) };
	this->repository.removeTask(t);
	this->notify();


}

std::vector<Programmer> Controller::getProgrammers()
{
	return this->repository.getProgrammers();
}

std::vector<Task> Controller::getTasks()
{
	return this->repository.getTasks();
}

void Controller::updateTask(Task& task, Programmer& p)
{
	Task t = task;
	/*if (t.getID() != -1) {
		throw std::exception("task already has programmer!");
	}*/
	this->repository.removeTask(task);
	t.setStatus("in progress");
	t.setID(p.getID());
	this->repository.addTask(t);
	this->notify();
	
}

void Controller::finishTask(Task& task)
{
	Task t = task;
	this->repository.removeTask(task);
	t.setStatus("closed");
	this->repository.addTask(t);
	this->notify();
}
