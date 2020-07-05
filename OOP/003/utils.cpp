#include <vector>
#include <string>
# include <sstream>

std::vector<std::string> tokenize2(std::string str, char delimiter) {
	std::vector <std::string> result;
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}