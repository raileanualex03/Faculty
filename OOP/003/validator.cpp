#include "validator.h"
#include <iostream>




bool Validator::checkID(std::string ID)
{
	return true;
}
bool Validator::checkSize(std::string size)
{

	// this function checks if the size is fine( has 2X and only digits)
	char sizeChars[32];
	strcpy(sizeChars, size.c_str());
	unsigned counterX = 0, counterDigits = 0;
	for (unsigned index = 0; index < size.length(); index++) {
		if ((sizeChars[index] < '0' || sizeChars[index] > '9') && sizeChars[index] != 'X')
			return false;
		
		if (sizeChars[index] == 'X')
			counterX++;
	}
	if (counterX == 2)
		return true;
	return false;

}

bool Validator::checkRadioactivityLevel(std::string radioactivityLevel)
{
	// this function checks if radioactivityLevel has only digits and maximum one .
	char radioactivityChars[32];
	strcpy(radioactivityChars, radioactivityLevel.c_str());
	unsigned counterPoint = 0;
	for (unsigned index = 0; index < radioactivityLevel.size(); index++) {
		if ((radioactivityChars[index] < '0' || radioactivityChars[index] > '9') && radioactivityChars[index] != '.')
			return false;

		if (radioactivityChars[index] == '.')
			counterPoint++;
	}
	if (counterPoint == 1 || counterPoint == 0)
		return true;
	return false;
}

bool Validator::checkQuantityOfMicrofragments(double quantityOfMicrofragments)
{
	return true;
}

bool Validator::checkDigitizedScan(std::string)
{
	return true;
}

bool Validator::validateAll(std::string ID, std::string size, std::string radioactivityLevel, double quantityOfMicrofragments, std::string digitizedScan)
{	
	std::string errors;
	if (this->checkID(ID) == false)
		errors += "Invalid ID\n";
	if (this->checkRadioactivityLevel(radioactivityLevel) == false)
		errors += "Invalid Radioactivity Level \n";
	if (this->checkSize(size) == 0)
		errors += "Invalid Size \n";
	if (this->checkQuantityOfMicrofragments(quantityOfMicrofragments) == false)
		errors += "Invalid Quantity Of Microfragments\n";
	if(this->checkDigitizedScan(digitizedScan) == false)
		errors += "Invalid Digitized Scan";
	if( errors.size() > 0)
		throw ValidationException(errors);
	return true;
}


// this is the class that will contain validation errors
ValidationException::ValidationException(std::string _message) : message{ _message }
{
}

std::string ValidationException::getMessage() const
{
	return this->message;
}



// this is the class that will contain existence errors
ExistenceException::ExistenceException(std::string _message) : message{ _message }
{
}

ExistenceException::ExistenceException(char* _message) : message{ _message }
{

}

std::string ExistenceException::getMessage() const
{
	return this->message;
}
