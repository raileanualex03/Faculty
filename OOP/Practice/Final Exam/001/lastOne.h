#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lastOne.h"
#include "Controller.h"
# include "Observer.h"
# include "MyListTableModel.h"
class lastOne : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    lastOne(Controller& controller, Astronomer astronomer, QWidget *parent = Q_NULLPTR);
    ~lastOne() {
        this->controller.saveFile();
    }
    void makeConnections();
    void update() override;
    void add();
    void search();
    void quit();
    void showStars();
    void view();

private:
    Ui::lastOneClass ui;
    Controller& controller;
    Astronomer astronomer;
    MyListTableModel* model;

};
