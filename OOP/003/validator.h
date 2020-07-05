
#include <string>

class Validator
{
public:

	// this will init the validator class
	Validator() {};

	// this function will check if the ID is okay ( it is true anyway)
	bool checkID(std::string);

	// this function will check if the size is okay, returns true if it's fine, false otherwise
	bool checkSize(std::string);

	// this function checks if the radioactivityLevel is okay, returns true if it's fine, false otherwise
	bool checkRadioactivityLevel(std::string);

	// this function checks if the quantityOfMicrofragments is okay, returns true if it's fine, false otherwise
	bool checkQuantityOfMicrofragments(double);

	// this function checks if the digitizedScan is okay, returns true if it's fine, false otherwise
	bool checkDigitizedScan(std::string);

	// this function will return true if all of the above functions will return true, returns false otherwise 
	bool validateAll(std::string, std::string, std::string, double, std::string);

};

class ValidationException
{
private:
	std::string message;

public:
	ValidationException(std::string _message);
	std::string getMessage() const;
};

class ExistenceException
{
private:
	std::string message;

public:
	ExistenceException(std::string _message);
	ExistenceException(char* _message);
	std::string getMessage() const;
};



