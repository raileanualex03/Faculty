# include "ui.h"
# include <iostream>
# include <string.h>
# include "repositoryFiles.h"
# include "tests.h"
# include <sstream>
# include <string>
using namespace std;


int main()
{
	//testAll();
	
	RepositoryDatabase repository{};
	RepositoryFiles repositoryAssistant{};
	Controller controller{ repository , repositoryAssistant};
    UserInterface ui{ controller };
	ui.run();

	
    return 0;
}