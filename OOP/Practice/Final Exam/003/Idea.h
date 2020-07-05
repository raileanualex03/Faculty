#pragma once
#include <string>
class Idea
{
private:
	std::string description;
	std::string status;
	std::string nameOfCreator;
	int act;
public:
	Idea(std::string d, std::string s, std::string n, int a)
		:description{ d }, status{ s }, nameOfCreator{ n }, act{ a }{};
	std::string getDescription() {
		return description;
	}
	std::string getStatus() {
		return status;
	}
	std::string getNameOfCreator() {
		return nameOfCreator;
	}
	int getAct() {
		return act;
	}

	void setStatus(std::string s) {
		status = s;
	}

	std::string toString() {
		std::string s;
		s += description + ',';
		s += status + ',';
		s += nameOfCreator + ',';
		s += std::to_string(act);
		return s;
	}
};

