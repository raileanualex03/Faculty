#include "RepositoryDatabase.h"
# include <sqlite3.h>
#include <iostream>

int getBots(void* , int , char** , char**);
unsigned RepositoryDatabase::addBot(const Bot& bot)
{
    sqlite3* database;
    std::string query = "INSERT INTO Bots"
        " VALUES('" + bot.getID() + "' , '" + bot.getSize() + "', '" + bot.getRadioactivityLevel() + "', '" + 
        std::to_string(bot.getQuantityOfMicrofragments()) + "', '" + bot.getDigitizedScan() + "');";
    std::cout << query << "\n";
    int result = 0;
    result = sqlite3_open(this->databaseName.c_str(), &database);
    char* messaggeError;
    result = sqlite3_exec(database, query.c_str(), NULL, 0, &messaggeError);

    return 1;
}

unsigned RepositoryDatabase::removeBot(const Bot& bot)
{
    sqlite3* database;
    std::string query = " DELETE FROM Bots WHERE ID=" + bot.getID()+";";
    int result = 0;
    result = sqlite3_open(this->databaseName.c_str(), &database);
    char* messaggeError;
    result = sqlite3_exec(database, query.c_str(), NULL, 0, &messaggeError);

    return 1;
}

unsigned RepositoryDatabase::updateBot(const Bot& bot)
{
    sqlite3* database;
    std::string query = "UPDATE Bots SET ID='" + bot.getID() + "', size='" 
        + bot.getRadioactivityLevel() + "', radioactivityLevel='" + bot.getRadioactivityLevel() 
        + "', quantityOfMicrofragments='" + std::to_string(bot.getQuantityOfMicrofragments()) 
        + "', digitizedScan=' " + bot.getDigitizedScan() + "' WHERE ID='" + bot.getID() + "';";
    int result = 0;
    std::cout << query;
    result = sqlite3_open(this->databaseName.c_str(), &database);
    char* messaggeError;
    result = sqlite3_exec(database, query.c_str(), NULL, 0, &messaggeError);

    return 1;
}

std::vector<Bot> RepositoryDatabase::getElements()
{
    sqlite3* database;
    std::string query = "SELECT * FROM Bots";
    std::vector<Bot> bots;
    auto result = sqlite3_open(this->databaseName.c_str(), &database);
    char* messageError;
    sqlite3_exec(database, query.c_str(), getBots, &bots, &messageError);

   
    return bots;
}

Bot RepositoryDatabase::searchBot(const std::string ID)
{
    sqlite3* database;
    std::string query = "SELECT * FROM Bots WHERE ID='" + ID + "';";
    int result = 0;
    result = sqlite3_open(this->databaseName.c_str(), &database);
    char* messaggeError;
    std::vector<Bot> bots;
    result = sqlite3_exec(database, query.c_str(), getBots, &bots, &messaggeError);

    return bots[0];
}
unsigned RepositoryDatabase::setFilename(std::string DBName)
{
    this->databaseName = DBName;
    this->createTable();
    return 1;
}
std::string RepositoryDatabase::getType()
{
    return std::string("database");
}
unsigned RepositoryDatabase::existsBot(const std::string ID)
{
    sqlite3* database;
    std::string query = "SELECT * FROM Bots WHERE ID='" + ID + "';";
    int result = 0;
    result = sqlite3_open(this->databaseName.c_str(), &database);
    char* messaggeError;
    std::vector<Bot> bots;
    result = sqlite3_exec(database, query.c_str(), getBots, &bots, &messaggeError);
    
    if (result != NULL)
        return 1;
    return 0;

}
void RepositoryDatabase::createTable()
{
    sqlite3* database;
    std::string query = "CREATE TABLE IF NOT EXISTS Bots("
        "ID TEXT,"
        "size TEXT,"
        "radioactivityLevel TEXT,"
        "quantityOfMicrofragments FLOAT,"
        "digitizedScan TEXT"
        ");";
    int result = 0;
    result = sqlite3_open(this->databaseName.c_str(), &database);
    char* messaggeError;
    std::vector<Bot> bots;
    result = sqlite3_exec(database, query.c_str(),NULL, NULL, &messaggeError);
}
int getBots(void* bots, int argc, char** lines, char** columns)
{
    std::string ID, Size, radioactivityLevel, DigitizedScan;
    double QuantityOfMicrofragments;
    std::cout <<"ARGC:" <<argc<<"\n";
    unsigned counterParametersOrder = 0;
    for (int i = 0; i < argc; i++) {
        if (i % 5 == 0) {
            // this will set the ID;
            ID = lines[i];
        }
        if (i % 5 == 1) {
            Size = lines[i];
        }
        if (i % 5 == 2) {
            radioactivityLevel = lines[i];
        }
        if (i % 5 == 3) {
            QuantityOfMicrofragments = std::stod(lines[i]);
        }
        if (i % 5 == 4) {
            DigitizedScan = lines[i];
            Bot bot = Bot(ID, Size, radioactivityLevel, QuantityOfMicrofragments, DigitizedScan);
            ((std::vector<Bot>*)bots)->push_back(bot);
        }
    }
    return 0;
  }
