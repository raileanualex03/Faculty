#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManager.h"
#include "Programmer.h"
#include "Controller.h"

class TaskManager : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    TaskManager(Controller& c, Programmer& p, QWidget *parent = Q_NULLPTR);
    void populateList();
    int getSelectedIndexes();

    void makeConnections();
    void addTask();
    void removeTask();
    void start();
    void done();

    void update() override;


private:
    Ui::TaskManagerClass ui;
    Programmer& programmer;
    Controller& controller;
};
