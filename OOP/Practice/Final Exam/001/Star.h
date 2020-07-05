#pragma once
#include <string>
#include <vector>
#include "utils.h"
# include <istream>
class Star
{
private:
	std::string name;
	std::string constellation;
	int rightAscension;
	int declination;
	int diameter;
public:
	Star() {
		name = "";
		constellation = "";
		rightAscension = 0;
		declination = 0;
		diameter = 0;
	}
	Star(std::string name, std::string constellation, int rightAscension, int declination, int diameter)
		: name{ name }, constellation{ constellation }, rightAscension{ rightAscension }, declination{ declination }, diameter{ diameter }{};

	std::string getName() {
		return name;
	}
	std::string getConstellation() {
		return constellation;
	}
	int getAscension() {
		return rightAscension;
	}

	int getDeclination() {
		return declination;
	}

	int getDiameter() {
		return diameter;
	};

	std::string toString() {
		std::string s;
		s += name + ',';
		s += constellation + ',';
		s += std::to_string(rightAscension) + ',';
		s += std::to_string(declination) + ',';
		s += std::to_string(diameter);
		return s;
	}

	friend std::istream& operator>>(std::istream& is, Star& s) {
	
		std::string line;
		std::string name, constelation, rightAscension, declination, diameter;
		std::getline(is, line);
		if (line.length() == 0)
			return is;
		std::vector<std::string> params = tokenize2(line, ',');
		s.name = params[0];
		s.constellation = params[1];
		s.rightAscension = std::stoi(params[2]);
		s.declination = std::stoi(params[3]);
		s.diameter = std::stoi(params[4]);
		return is;
	};


};

