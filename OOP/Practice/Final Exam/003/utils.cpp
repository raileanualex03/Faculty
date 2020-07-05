# pragma once
# include <vector>
# include <sstream>
# include <string>

std::vector<std::string> tokenize(std::string str, char delimiter) {
	std::vector <std::string> result;
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}