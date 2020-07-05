#include "ViewWidget.h"

ViewWidget::ViewWidget(Controller& c, Star& star, QWidget *parent)
	: controller{ c }, star {star}, QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(star.getName()));
	this->ui.starLabel->setText(QString::fromStdString(star.getName()));
	this->ui.constellationLabel->setText(QString::fromStdString(star.getConstellation()));
	this->populateList();
}

void ViewWidget::populateList()
{
	std::vector<Star> elems;
	for (auto s : this->controller.getStars())
		if (s.getConstellation() == star.getConstellation())
			elems.push_back(s);
	int index = 0;
	for (Star s : elems) {
		this->ui.listWidget->addItem(QString::fromStdString(s.toString()));
		std::string color = "red";
		this->ui.listWidget->item(index)->setForeground(QColor(color.c_str()));
		index++;
	}
	
}

ViewWidget::~ViewWidget()
{
}
