#pragma once
#include <string>
#include <vector>
#include "utils.h"
# include <istream>
class Astronomer
{
private:
	std::string name;
	std::string constellation;
public:
	Astronomer() { name = ""; constellation = ""; }
	Astronomer(std::string name, std::string constelation) : name{ name }, constellation{ constellation }{};
	std::string getName() {
		return name;
	}

	std::string getConstellation() {
		return constellation;
	}

	void setConstellation(std::string c) {
		constellation = c;
	}

	std::string toString() {
		std::string s;
		s += name + ",";
		s += constellation;
		return s;
	}

	friend std::istream& operator>>(std::istream& is, Astronomer& astronomer) {
		std::string line;
		getline(is, line);
		if (line.length() == 0)
			return is;
		std::vector<std::string> params = tokenize2(line, ',');
		std::string name, constellation;
		astronomer.name = params[0];
		astronomer.constellation = params[1];
		return is;
	};
};
