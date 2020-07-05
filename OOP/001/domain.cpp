#include "domain.h"
#include <vector>
#include <sstream>
# include <iostream>
# pragma once

Bot::Bot() : ID{ "" }, size{ "" }, radioactivityLevel{ "" }, quantityOfMicrofragments{ 0 }, digitizedScan{ "" }{}

Bot::Bot(const std::string& ID, const std::string& size, const std::string& radioactivityLevel, double& quantityOfMicrofragments, const std::string& digitizedScan)
{
	this->ID = ID;		
	this->size = size;
	this->radioactivityLevel = radioactivityLevel;
	this->quantityOfMicrofragments = quantityOfMicrofragments;
	this->digitizedScan = digitizedScan;
}

std::string Bot::ToString()
{
	return "Bot with ID: " + this->ID + ", size: " + this->size + ", radioactivityLevel: " + this->radioactivityLevel + ", quantity: " + std::to_string(this->getQuantityOfMicrofragments())+ ", digitizedScan: " + this->digitizedScan;
}

std::vector<std::string> tokenize(std::string str, char delimiter)
{
	std::vector<std::string> result;
	std::stringstream ss(str);
	std::string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

std::istream & operator>>(std::istream &is, Bot& bot)
{
	std::string line;
	getline(is, line);
	std::vector<std::string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return is;
	bot.ID = tokens[0];
	bot.size = tokens[1];
	bot.radioactivityLevel = tokens[2];
	bot.quantityOfMicrofragments = stod(tokens[3]);
	bot.digitizedScan = tokens[4];

	return is;
}

std::ostream& operator<<(std::ostream& os, const Bot& bot) {
	os << bot.getID() << "," << bot.getSize() << "," << bot.getRadioactivityLevel() << "," << bot.getQuantityOfMicrofragments() << "," << bot.getDigitizedScan()+"\n";
	return os;
}