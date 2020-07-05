#include "Hazardaguess.h"
# include <qmessagebox.h>
#include <iostream>
# include <fstream>
#include "utils.h"
# include <qshortcut.h>
#include "MyListTableModel.h"
#include "MyListViewClass.h"
# include "PictureDelegate.h"

Hazardaguess::Hazardaguess(Controller* controller, QWidget *parent)
	: QMainWindow(parent)
{
	this->controller = controller;
	ui.setupUi(this);
	this->ui.ModeA->setEnabled(false);
	this->ui.modeB->setEnabled(false);
	this->initShortcuts();
	this->makeConnections();
	this->getDataFromConfigFile();
	this->controller->addObserver(this);

	
}

void Hazardaguess::populateList()
{	
	// first clear it
	this->ui.botsListWidget->clear();
	
	vector<Bot> allBots = this->controller->getElements();
	int index = 0;
	for (Bot& bot : allBots){
		this->ui.botsListWidget->addItem(QString::fromStdString("Bot: " + bot.getID() + " - " + bot.getSize() + " - " + bot.getRadioactivityLevel()
			+ " - " + std::to_string(bot.getQuantityOfMicrofragments()) + " - " + bot.getDigitizedScan()));
		std::string color = "white";
		this->ui.botsListWidget->item(index)->setForeground(QColor(color.c_str()));
		index++;
	}

}

void Hazardaguess::makeConnections()
{
	QObject::connect(this->ui.botsListWidget, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = this->getSelectedIndex();
		if (selectedIndex < 0)
			return;
		Bot bot = this->controller->getElements()[selectedIndex];
		this->ui.IDLineEdit->setText(QString::fromStdString(bot.getID()));
		this->ui.SizeLineEdit->setText(QString::fromStdString(bot.getSize()));
		this->ui.RadioactivityLevelLineEdit->setText(QString::fromStdString(bot.getRadioactivityLevel()));
		this->ui.QuantityOfMicrofragmentsLineEdit->setText(QString::fromStdString(std::to_string(bot.getQuantityOfMicrofragments())));
		this->ui.DigitizedScanLineEdit->setText(QString::fromStdString(bot.getDigitizedScan()));
		});

	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &Hazardaguess::addBot);
	QObject::connect(this->ui.DeleteButton, &QPushButton::clicked, this, &Hazardaguess::deleteBot);
	QObject::connect(this->ui.updateButton, &QPushButton::clicked, this, &Hazardaguess::updateBot);
	QObject::connect(this->ui.fileModeAButton, &QPushButton::clicked, this, &Hazardaguess::fileModeA);
	QObject::connect(this->ui.fileModeBButton, &QPushButton::clicked, this, &Hazardaguess::fileModeB);
	QObject::connect(this->ui.memoryModeAButton, &QPushButton::clicked, this, &Hazardaguess::memoryModeA);
	QObject::connect(this->ui.memoryModeBButton, &QPushButton::clicked, this, &Hazardaguess::memoryModeB);
	QObject::connect(this->ui.pushButton_4, &QPushButton::clicked, this, &Hazardaguess::startApplication);
	QObject::connect(this->ui.saveFilenameModeA, &QPushButton::clicked, this, &Hazardaguess::setFilenameModeA);
	QObject::connect(this->ui.saveFilenameModeB, &QPushButton::clicked, this, &Hazardaguess::setFilenameModeB);
	QObject::connect(this->ui.openButton, &QPushButton::clicked, this, &Hazardaguess::openFile);
	QObject::connect(this->ui.nextButton, &QPushButton::clicked, this, &Hazardaguess::showNext);
	QObject::connect(this->ui.saveBotModeB, &QPushButton::clicked, this, &Hazardaguess::saveModeB);
	QObject::connect(this->ui.showModeBButton, &QPushButton::clicked, this, &Hazardaguess::showModeBBots);
	QObject::connect(this->ui.pushButton, &QPushButton::clicked, this, &Hazardaguess::showCertainBots);
	QObject::connect(this->ui.undoButton, &QPushButton::clicked, this, &Hazardaguess::executeUndo);
	QObject::connect(this->ui.redoButton, &QPushButton::clicked, this, &Hazardaguess::executeRedo);
	QObject::connect(this->ui.undoButtonAssistant, &QPushButton::clicked, this, &Hazardaguess::executeUndoAssistant);
	QObject::connect(this->ui.redoButtonAssistant, &QPushButton::clicked, this, &Hazardaguess::executeRedoAssistant);
	QObject::connect(this->ui.openMyListButton, &QPushButton::clicked, this, &Hazardaguess::openMyList);
	QObject::connect(this->shortcutUndoModeA, &QShortcut::activated, this, &Hazardaguess::executeUndo);
	QObject::connect(this->shortcutRedoModeA, &QShortcut::activated, this, &Hazardaguess::executeRedo);

}

int Hazardaguess::getSelectedIndex() const
{
	QModelIndexList selectedIndexes = this->ui.botsListWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		this->ui.IDLineEdit->clear();
		this->ui.SizeLineEdit->clear();
		this->ui.RadioactivityLevelLineEdit->clear();
		this->ui.QuantityOfMicrofragmentsLineEdit->clear();
		this->ui.DigitizedScanLineEdit->clear();

		return -1;


	}
	int selectedIndex = selectedIndexes.at(0).row();


	return selectedIndex;
}

void Hazardaguess::addBot()
{
	double quantityOfMicrofragments = 0;
	std::string id = this->ui.IDLineEdit->text().toStdString();
	std::string size = this->ui.SizeLineEdit->text().toStdString();
	std::string radioactivityLevel = this->ui.RadioactivityLevelLineEdit->text().toStdString();
	try {
		quantityOfMicrofragments = std::stod(this->ui.QuantityOfMicrofragmentsLineEdit->text().toStdString());
	}
	catch (...)
	{
		QMessageBox::critical(this, "Error", "Empty space");
		return;

	}
	std::string digitizedScan = this->ui.DigitizedScanLineEdit->text().toStdString();

	// the addition
	try {
		this->controller->addBot(id, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
	}
	catch (ValidationException& e) {
		QMessageBox::critical(this, "Error", e.getMessage().c_str());
		return;
	}
	catch (ExistenceException& e) {
		QMessageBox::critical(this, "Error", e.getMessage().c_str());
		return;
	}
	// change in the GUI
	this->populateList();

	int lastElement = this->controller->getElements().size() - 1;
	this->ui.botsListWidget->setCurrentRow(lastElement);
	QMessageBox::information(this, "Succesfully added!", "The item has been added!");
}

void Hazardaguess::deleteBot()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No bot selected! ");
		return;
	}

	Bot bot = this->controller->getElements()[selectedIndex];
	this->controller->removeBot(bot.getID());

	// change in the GUI
	this->populateList();
	QMessageBox::information(this, "Succesfully removed!", "The item has been removed!");
}

void Hazardaguess::updateBot()
{
	double quantityOfMicrofragments;
	std::string id = this->ui.IDLineEdit->text().toStdString();
	std::string size = this->ui.SizeLineEdit->text().toStdString();
	std::string radioactivityLevel = this->ui.RadioactivityLevelLineEdit->text().toStdString();
	try {
		quantityOfMicrofragments = std::stod(this->ui.QuantityOfMicrofragmentsLineEdit->text().toStdString());
	}
	catch (...)
	{
		QMessageBox::critical(this, "Error", "Empty space");
		return;


	}
	std::string digitizedScan = this->ui.DigitizedScanLineEdit->text().toStdString();
	try {
		this->controller->updateBot(id, size, radioactivityLevel, quantityOfMicrofragments, digitizedScan);
	}
	catch (ValidationException& e) {
		QMessageBox::critical(this, "Error", e.getMessage().c_str());
	}
	catch (ExistenceException& e) {
		QMessageBox::critical(this, "Error", e.getMessage().c_str());
	}
	// change in the GUI
	this->populateList();

	int lastElement = this->controller->getElements().size() - 1;
	this->ui.botsListWidget->setCurrentRow(lastElement);
	QMessageBox::information(this, "Succesfully updated!", "The item has been updated!");
}

void Hazardaguess::fileModeA()
{
	this->ui.memoryModeAButton->setEnabled(false);
	// 1 will be for the repository file
	this->codeRepositoryModeA = 1;
}

void Hazardaguess::fileModeB()
{
	this->ui.memoryModeBButton->setEnabled(false);
	// 1 will be for the file
	this->codeRepositoryModeB = 1;
}

void Hazardaguess::memoryModeA()
{
	this->ui.fileModeAButton->setEnabled(false);
	// 2 will be for in memory;
	this->codeRepositoryModeA = 2;

}

void Hazardaguess::memoryModeB()
{
	this->ui.fileModeBButton->setEnabled(false);
	// 2 will be for in memory :)
	this->codeRepositoryModeB = 2;
}

void Hazardaguess::startApplication()
{
	if (this->codeRepositoryModeA == -1 || this->codeRepositoryModeB == -1) {
		QMessageBox::critical(this, "Error", "No button pressed");
		return;
	}
	if (this->codeRepositoryModeA == 1) {
		RepositoryFiles* repo = new RepositoryFiles();
		if (this->codeRepositoryModeB == 1) {
			RepositoryFiles* repoAssistant = new RepositoryFiles();
			Controller* controller = new Controller(repo, repoAssistant);
			this->controller = controller;
			
		}
		else {
			RepositoryMemory* repoAssistant = new RepositoryMemory();
			Controller* controller = new Controller(repo, repoAssistant);
			this->controller = controller;
			this->ui.filenameModeB->setEnabled(false);
			this->ui.saveFilenameModeB->setEnabled(false);
			this->ui.openButton->setEnabled(false);
			this->ui.openButton->setText("Open not available!");
		}


	}
	else {
		RepositoryMemory* repo = new RepositoryMemory();

		if (this->codeRepositoryModeB == 1) {
			RepositoryFiles* repoAssistant = new RepositoryFiles();
			Controller* controller =  new Controller(repo, repoAssistant);
			this->controller = controller;
			
			this->ui.filenameModeA->setEnabled(false);
			this->ui.saveFilenameModeA->setEnabled(false);
		}
		else {
			RepositoryMemory* repoAssistant = new RepositoryMemory();
			Controller* controller = new Controller(repo, repoAssistant);
			this->controller = controller;
			this->ui.filenameModeA->setEnabled(false);
			this->ui.saveFilenameModeA->setEnabled(false);
			this->ui.filenameModeB->setEnabled(false);
			this->ui.saveFilenameModeB->setEnabled(false);
		}
	}
	this->ui.pushButton_4->setEnabled(false);
	this->ui.Start->setEnabled(false);
	this->ui.ModeA->setEnabled(true);
	this->ui.modeB->setEnabled(true);

}

void Hazardaguess::setFilenameModeA()
{
	std::string filename;
	filename = this->ui.filenameModeA->text().toStdString();
	this->controller->setFilename(administratorRepositoryName);
	this->populateList();
	this->ui.filenameModeA->setEnabled(false);
	this->ui.saveFilenameModeA->setEnabled(false);
}

void Hazardaguess::setFilenameModeB()
{
	std::string filename;
	filename = this->ui.filenameModeB->text().toStdString();
	this->controller->setFilenameAssistant(assistantRepositoryName);

	this->ui.filenameModeB->setEnabled(false);
	this->ui.saveFilenameModeB->setEnabled(false);
}

void Hazardaguess::openFile()
{
	std::string command = "start ";
	std::string type = this->controller->getTypeAssistant();
	if (type == "html")
		command += "chrome " + this->controller->getFilenameAssistant();
	else if (type == "csv")
		command += " excel " + this->controller->getFilenameAssistant();
	else if (type == "txt")
		command += " notepad " + this->controller->getFilenameAssistant();
	
	system(command.c_str());
}

void Hazardaguess::populateListModeB(std::vector<Bot> bots)
{
	this->ui.botsModeBListWidget->clear();

	int index = 0;
	for (Bot bot: bots) {
			this->ui.botsModeBListWidget->addItem(QString::fromStdString("Bot: " + bot.getID() + " - " + bot.getSize() + " - " + bot.getRadioactivityLevel()
				+ " - " + std::to_string(bot.getQuantityOfMicrofragments()) + " - " + bot.getDigitizedScan()));
			this->ui.botsModeBListWidget->item(index)->setForeground(Qt::white);
			index++;
	}
}

void Hazardaguess::showNext()
{
	Bot bot;
	try {
		bot = this->controller->getNextBot();
	}
	catch (std::exception e) {
		QMessageBox::critical(this, "Error", e.what());
		return;
	}
	std::vector<Bot> bots;
	bots.push_back(bot);
	this->populateListModeB(bots);
}

void Hazardaguess::saveModeB()
{
	std::string ID = this->ui.IDModeBLineEdit->text().toStdString();
	try {
		this->controller->assistantAddBot(ID); 
		QMessageBox::information(this, "Succesfully saved!", "The item has been saved!");
	}
	catch (ExistenceException e) {
		QMessageBox::critical(this, "Error", e.getMessage().c_str());
	}
	
}

void Hazardaguess::showModeBBots()
{
	std::vector<Bot> bots = this->controller->assistantGetBots();
	this->populateListModeB(bots);
}

void Hazardaguess::showCertainBots()
{
	std::string size = this->ui.radioactivityLevelModeBEdit->text().toStdString();
	if (size.length() <= 0) {
		QMessageBox::critical(this, "Error", "No size provided");
		return;
	}
	std::string quantityString = this->ui.quantityModeBLineEdit->text().toStdString();
	if (quantityString.length() <= 0) {
		QMessageBox::critical(this, "Error", "No quantity provided");
		return;
	}
	double quantity = std::stod(quantityString);
	std::vector<Bot> bots = this->controller->getBotsWithCertainSize(size, quantity);
	this->populateListModeB(bots);
}

void Hazardaguess::executeUndo()
{
	try {
		this->controller->undo();
	}
	catch (std::exception& e) {
		QMessageBox::critical(this, "Error", e.what());
	}
	this->populateList();
}

void Hazardaguess::executeRedo()
{
	try {
		this->controller->redo();
	}
	catch (std::exception& e) {
		QMessageBox::critical(this, "Error", e.what());
	}
	this->populateList();
}

void Hazardaguess::executeUndoAssistant()
{
	try {
		this->controller->undoAssistant();
		this->populateListModeB(this->controller->assistantGetBots());
	}
	catch (std::exception& e) {
		QMessageBox::critical(this, "Error", e.what());
	}
}

void Hazardaguess::executeRedoAssistant()
{
	try {
		this->controller->redoAssistant();
		this->populateListModeB(this->controller->assistantGetBots());
	}
	catch (std::exception& e) {
		QMessageBox::critical(this, "Error", e.what());
	}
}

void Hazardaguess::initShortcuts()
{
	this->shortcutUndoModeA = new QShortcut(QKeySequence("CTRL+Z"), this->ui.ModeA);
	this->shortcutRedoModeA = new QShortcut(QKeySequence("CTRL+Y"), this->ui.ModeA);

}

void Hazardaguess::openMyList()
{
	
	MyListTableModel* model = new MyListTableModel(*this->controller);
	MyListViewClass* view = new MyListViewClass(model);
	
	// set the custom delegate
	view->ui.myListTableView->setItemDelegate(new PictureDelegate{});

	// force the columns to resize, according to the size of their contents
	view->ui.myListTableView->resizeColumnsToContents();
	view->ui.myListTableView->resizeRowsToContents();
	// hide the vertical header
	this->controller->addObserver(view);
	view->ui.myListTableView->verticalHeader()->hide(); 
	view->show();
}

void Hazardaguess::getDataFromConfigFile()
{
	std::ifstream fileInput("settings.txt");
	std::string firstLine, secondLine;
	
	std::getline(fileInput, firstLine);
	std::getline(fileInput, secondLine);

	std::vector<std::string> parametersFirstLine = tokenize2(firstLine, '=');
	std::vector<std::string> parametersSecondLine = tokenize2(secondLine, '=');

	if (parametersFirstLine[1] == "memory") {
		this->codeRepositoryModeA = 2;
	}
	else {
		this->codeRepositoryModeA = 1;
		this->ui.filenameModeA->setText(QString::fromStdString(parametersFirstLine[1]));
		administratorRepositoryName = parametersFirstLine[1];
	}
	if (parametersSecondLine[1] == "memory") {
		this->codeRepositoryModeB = 2;
	}
	else {
		this->codeRepositoryModeB = 1;
		this->ui.filenameModeB->setText(QString::fromStdString(parametersSecondLine[1]));
		assistantRepositoryName = parametersSecondLine[1];
	}

	startApplication();
	setFilenameModeA();
	setFilenameModeB();
}

void Hazardaguess::update()
{

	//this->populateList();
}




