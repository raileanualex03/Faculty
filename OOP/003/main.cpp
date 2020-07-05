
#include <QtWidgets/QApplication>
#include "repositoryFiles.h"
#include "controller.h"
# include "Hazardaguess.h"
#include <fstream>
# include <sstream>
#include "utils.h"
# include "MyListViewClass.h"
#include "AppConfigurations.h"



int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setWindowIcon(QIcon("./21047.jpg"));

	// config reads the settings from the file
	AppConfigurations config = AppConfigurations("settings.txt");
	std::vector<Repository*> repositories = config.getRepositories();

	Repository* repository = repositories[0];
	Repository* repositoryAssistant = repositories[1];

	Controller* controller = new Controller(repository, repositoryAssistant); 



	Hazardaguess gui{ controller };
	gui.show();

//	MyListTableModel* model = new MyListTableModel(*controller);
//	MyListViewClass view{ model };
//	view.show();
	

	return app.exec();
}
		