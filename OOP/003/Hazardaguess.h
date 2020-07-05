#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Hazardaguess.h"
#include "controller.h"

class Hazardaguess : public QMainWindow, public Observer
{

public:
	Hazardaguess(Controller* controller, QWidget *parent = Q_NULLPTR);
	int codeRepositoryModeA = -1;
	int codeRepositoryModeB = -1;
	std::string administratorRepositoryName, assistantRepositoryName;
	QShortcut* shortcutUndoModeA;
	QShortcut* shortcutRedoModeA;
	//QShortcut* undoModeB;
	//QShortcut* redoModeB;

private:
	Controller* controller;
	
	Ui::HazardaguessClass ui;

	void populateList();
	void makeConnections();

	int getSelectedIndex() const;
	void addBot();
	void deleteBot();
	void updateBot();

	void fileModeA();
	void fileModeB();

	void memoryModeA();
	void memoryModeB();

	void startApplication();
	
	void setFilenameModeA();
	void setFilenameModeB();

	void openFile();
	void populateListModeB(std::vector<Bot> bots);
	
	void showNext();

	void saveModeB();
	void showModeBBots();
	void showCertainBots();

	void executeUndo();
	void executeRedo();

	void executeUndoAssistant();
	void executeRedoAssistant();

	void initShortcuts();
	void openMyList();
	void getDataFromConfigFile();

	void update() override;
};
