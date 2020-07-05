#include "repositoryFiles.h"
# include <iostream>
# include <fstream>
# include "domain.h"
# include <sstream>


unsigned RepositoryFiles::addBot(const Bot& bot)
{
	
	std::ofstream fileOutput(this->filename, std::ios::app);
	if (strcmp(this->type, "html")==0) {
		this->addBotToHTML(bot);
		return 1;
	}
	if (this->existsBot(bot.getID()) == 1)
		return 0;
	fileOutput << bot;

	fileOutput.close();
	return 1;
}

unsigned RepositoryFiles::removeBot(const Bot& bot)
{
	Bot botRead;
	if (this->existsBot(bot.getID()) == 0)
		return 0;
	std::ifstream fileInput(this->filename);
	std::vector<Bot> bots;
	while (fileInput >> botRead) {
		if (botRead.getID() != bot.getID()) {
			bots.push_back(botRead);
		}
	}
	fileInput.close();

	std::ofstream fileOutput(this->filename);
	for (auto bot :bots)
		fileOutput << bot;
	fileOutput.close();
	return 1;
}

unsigned RepositoryFiles::updateBot(const Bot& bot)
{
	Bot botRead;
	if (this->existsBot(bot.getID()) == 0)
		return 0;
	this->removeBot(bot);
	this->addBot(bot);

	return 1;
}

std::vector<Bot> RepositoryFiles::getElements()
{
	if (strcmp(this->type, "html") == 0)
		return this->getElementsFromHTML();
	else {
		Bot botRead;
		std::vector<Bot> botsFromFile;
		std::ifstream fileInput(this->filename);
		while (fileInput >> botRead)
			botsFromFile.push_back(botRead);

		fileInput.close();
		return botsFromFile;
	}
}

Bot RepositoryFiles::searchBot(const std::string ID)
{
	Bot botRead;
	std::ifstream fileInput(this->filename);
	while (fileInput >> botRead)
		if (botRead.getID() == ID) {
			fileInput.close();
			return botRead;
		}
}

unsigned RepositoryFiles::existsBot(const std::string ID)
{
	Bot botRead;
	std::ifstream fileInput(this->filename);
	while (fileInput >> botRead)
		if (botRead.getID() == ID) {
			fileInput.close();
			return 1;
		}
	fileInput.close();
	return 0;
}

unsigned RepositoryFiles::setFilename(const std::string filename)
{
	this->filename = filename;
	this->setTypeOfFile();
	return 1;
}

unsigned RepositoryFiles::setTypeOfFile()
{
		int number = filename.length();
		char filenameInChars[256];
		strcpy(filenameInChars, filename.c_str());
		if (strcmp(filenameInChars + number - 4, ".txt") == 0)
			strcpy(this->type, "txt");
		else if (strcmp(filenameInChars + number - 4, ".csv") == 0)
			strcpy(this->type,"csv");
		else if (strcmp(filenameInChars + number - 4, "html") == 0) {
			strcpy(this->type, "html");
			if (this->isEmptyHTML() == true) {
				this->writeHeadHTML();
				this->writeTailHTML();
			}
		}
		else return 0;
		return 1;
}

std::string RepositoryFiles::getType()
{
	return this->type;
}

void RepositoryFiles::writeHeadHTML()
{
	std::ofstream FileOutput(this->filename);
	FileOutput << "<!DOCTYPE html>\n";
	FileOutput << "<html>\n";
	FileOutput << "<head>";
	FileOutput << "<title>Bots</title>\n";
	FileOutput << "</head>\n";
	FileOutput << "<body>\n";
	FileOutput << "<table border=\"1\">\n";
	FileOutput << "<tr>\n";
	FileOutput << "<th>"<< "ID"<<"</th>\n";
	FileOutput << "<th>" << "Size" << "</th>\n";
	FileOutput << "<th>" << "Radioactivity Level" << "</th>\n";
	FileOutput << "<th>" << "Quantity Of Microfragments" << "</th>\n";
	FileOutput << "<th>" << "Digitized Scan" << "</th>\n";
	FileOutput << "</tr>\n";

}

void RepositoryFiles::writeTailHTML()
{
	std::ofstream FileOutput(this->filename, std::ios::app);
	FileOutput << "</table>\n";
	FileOutput << "</body>\n";
	FileOutput << "</html>\n";
}

unsigned  RepositoryFiles::addBotToHTML(const Bot& bot)
{	
	std::string line;
	std::vector<std::string> lines;
	std::ifstream FileInput(this->filename);
	while (getline(FileInput, line))
		lines.push_back(line);
	std::ofstream FileOutput(this->filename);
	for (int index = 0; index < lines.size() - 3; index++) 
		FileOutput << lines[index]<<"\n";
	
	FileOutput << "<tr>\n";
	FileOutput << "<td>" << "\n" << bot.getID() << "\n" << "</td>\n";
	FileOutput << "<td>" << "\n" << bot.getSize() << "\n" << "</td>\n";
	FileOutput << "<td>" << "\n" << bot.getRadioactivityLevel() << "\n" << "</td>\n";
	FileOutput << "<td>" << "\n" << bot.getQuantityOfMicrofragments() << "\n" << "</td>\n";
	FileOutput << "<td>" << "\n" << bot.getDigitizedScan() << "\n" << "</td>\n";
	FileOutput << "</tr>\n";
	FileOutput << "</table>\n";
	FileOutput << "</body>\n";
	FileOutput << "</html>\n";
	return 1;
	
}

std::vector<Bot> RepositoryFiles::getElementsFromHTML()
{
	std::string line;
	std::vector<std::string> lines;
	std::ifstream FileInput(this->filename);
	while (getline(FileInput, line)) {
		if (line.find("<") == std::string::npos) {
			lines.push_back(line);
		}
	}

	std::vector<Bot> bots;
	std::string ID, Size, radioactivityLevel, DigitizedScan;
	double QuantityOfMicrofragments;
	unsigned counterParametersOrder;
	unsigned numberOfParametersBot = 5;
	for (int counterParametersOrder = 0; counterParametersOrder < lines.size();counterParametersOrder++) {
		
		if (counterParametersOrder % numberOfParametersBot == 0) {
			// this will set the ID;
			ID = lines[counterParametersOrder];
		}
		if (counterParametersOrder % numberOfParametersBot == 1) {
			Size = lines[counterParametersOrder];
		}
		if (counterParametersOrder % numberOfParametersBot== 2) {
			radioactivityLevel = lines[counterParametersOrder];
		}
		if (counterParametersOrder % numberOfParametersBot == 3) {
			QuantityOfMicrofragments = std::stod(lines[counterParametersOrder]);
		}
		if (counterParametersOrder % numberOfParametersBot == 4) {
			DigitizedScan = lines[counterParametersOrder];
			Bot bot = Bot(ID, Size, radioactivityLevel, QuantityOfMicrofragments, DigitizedScan);
			bots.push_back(bot);
		}
	}
	return bots;


}

bool RepositoryFiles::isEmptyHTML()
{	
	std::string line;
	std::ifstream FileInput(this->filename);
	while (getline(FileInput, line))
		if (line.size() != 0)
			return false;
	return true;
	
}

