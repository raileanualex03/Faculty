# include <string>
# pragma once

class Bot
{
private:
	std::string ID;
	std::string size;
	std::string radioactivityLevel;
	double quantityOfMicrofragments;
	std::string digitizedScan;


public:

	// this is the default constructor
	Bot();

	// this will create an object Bot with specified parameters
	Bot(const std::string& ID, const std::string& size, const std::string& radioactivityLevel, double& quantityOfMicrofragments, const std::string& digitizedScan);

	// this will return the ID
	std::string getID()const { return ID; }

	// this will return the size
	std::string getSize()const { return size; }

	// this will return the radioactivityLevel
	std::string getRadioactivityLevel()const { return radioactivityLevel; }

	// this will return the quantityOfMicrofragments
	double getQuantityOfMicrofragments()const { return quantityOfMicrofragments; }

	// this will return the digitizedScan
	std::string getDigitizedScan()const { return digitizedScan; }


	// this will create a string for this bot :)
	std::string ToString();

	friend std::istream & operator>>(std::istream& is, Bot & bot);

	friend std::ostream & operator<<(std::ostream & os, const Bot & bot);

};	