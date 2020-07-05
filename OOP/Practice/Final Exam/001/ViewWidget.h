#pragma once

#include <QWidget>
#include "ui_ViewWidget.h"
#include "Star.h"
# include "Controller.h"
class ViewWidget : public QWidget
{
	Q_OBJECT

public:
	ViewWidget(Controller& c, Star & star, QWidget *parent = Q_NULLPTR);
	void populateList();
	~ViewWidget();

private:
	Ui::ViewWidget ui;
	Star& star;
	Controller& controller;
};
