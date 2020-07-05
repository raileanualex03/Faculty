#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ScreenWriting20.h"
#include "Controller.h"
#include "MyListTableModel.h"

class ScreenWriting20 
    : public QMainWindow, public Observer
{


public:
    ScreenWriting20(Controller& c, Screenwriter w, QWidget *parent = Q_NULLPTR);

    void update() override;
    void makeConnections();
    void add();
    void accept();

private:
    Ui::ScreenWriting20Class ui;
    Controller& controller;
    Screenwriter writer;
    MyListTableModel* model;
    int getSelectedIndex();
};
