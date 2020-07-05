#include "utils.h"

using namespace std;
std::vector<std::string> getFunctionAndParameters(std::string input)
{

	vector<string> vectorOfParameters;
	stringstream streamToGetParameters(input);
	string parameter;
	getline(streamToGetParameters, parameter, ' ');
	vectorOfParameters.push_back(parameter);
	while (getline(streamToGetParameters, parameter, ','))
	{
		if (vectorOfParameters.size() != 1)
			parameter.erase(parameter.begin());
		vectorOfParameters.push_back(parameter);
	}
	return vectorOfParameters;

}

std::vector<std::string> tokenize(std::string str, char delimiter)
{
	std::vector <std::string> result;
	std::stringstream ss(str);
	std::string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
};