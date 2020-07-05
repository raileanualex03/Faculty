#pragma once
#include <string>
class Programmer
{
private:
	std::string _name;
	int _id;
public:
	Programmer(std::string name, int id) :_name{ name }, _id{ id }{};
	std::string getName() {
		return _name;
	}

	int getID() {
		return _id;
	}
	
	std::string toString() {
		std::string s;
		s += _id + ',';
		s += _name;
		return s;
	}
};

