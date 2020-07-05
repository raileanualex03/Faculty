#pragma once
#include <string>
class Screenwriter
{
private:
	std::string name;
	std::string expertise;
public:

	Screenwriter(std::string n, std::string e) :name{ n }, expertise{ e }{};
	std::string getName() {
		return name;
	}
	std::string getExpertise() {
		return expertise;
	}

	std::string toString() {
		std::string s;
		s += name + ',';
		s += expertise;
		return s;
	}
	std::string setExpertise(std::string e) {
		expertise = e;
	}
};

