#include "MyListViewClass.h"

MyListViewClass::MyListViewClass(MyListTableModel* model, QWidget *parent)
	: QWidget(parent),model{model}
{
	ui.setupUi(this);

	ui.myListTableView->setModel(model);
}

void MyListViewClass::update()
{
	Repository* repository = &this->model->repo;
	MyListTableModel* newModel = new MyListTableModel(repository);
	this->ui.myListTableView->setModel(newModel);
}

MyListViewClass::~MyListViewClass()
{
}
