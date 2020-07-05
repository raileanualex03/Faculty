#include "ScreenWriting20.h"
# include <qmessagebox.h>

ScreenWriting20::ScreenWriting20(Controller& c, Screenwriter w, QWidget *parent)
    : controller{ c }, writer{ w }, QMainWindow(parent)
{
    ui.setupUi(this);
    makeConnections();
    this->setWindowTitle(QString::fromStdString(writer.getName()));
    this->model = new MyListTableModel(&controller);
    this->ui.IdeasTableView->setModel(model);
}

void ScreenWriting20::update()
{
    delete this->model;
    this->model = new MyListTableModel(&controller);
    this->ui.IdeasTableView->setModel(model);
}

void ScreenWriting20::makeConnections()
{
    QObject::connect(this->ui.IdeasTableView, &QTableView::SelectedClicked [this]() {
        int selectedIndex = this->getSelectedIndex();
        if (selectedIndex < 0)
            return;
        });
     QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &ScreenWriting20::add);
     QObject::connect(this->ui.acceptButton, &QPushButton::clicked, this, &ScreenWriting20::accept);

}

void ScreenWriting20::add()
{
    std::string description, status, creator, act;
    description = this->ui.descriptionLineEdit->text().toStdString();
    if (description.length() == 0) {
        QMessageBox::critical(this, "Error", "provide description!");
        return;
    }
    act = this->ui.actLineEdit->text().toStdString();
    if (act.length() == 0) {
        QMessageBox::critical(this, "Error", "provide act");
        return;
    }
    creator = this->writer.getName();
    status = "proposed";
    try {
        this->controller.addIdea(description, status, creator, act);
    }
    catch (std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
        return;
    }
}

void ScreenWriting20::accept()
{
    std::string description, act, creator;
    description = this->ui.descriptionLineEdit->text().toStdString();
    if (description.length() == 0) {
        QMessageBox::critical(this, "Error", "provide description!");
        return;
    }
    act = this->ui.actLineEdit->text().toStdString();
    if (act.length() == 0) {
        QMessageBox::critical(this, "Error", "provide act");
        return;
    }

    creator = this->writer.getName();
    if (this->writer.getExpertise() == "Senior") {
        this->controller.updateIdea(description, act);
    }
    else {
        QMessageBox::critical(this, "ERROR", "You can not do this! (ONLY SENIORS)");
    }
}

int ScreenWriting20::getSelectedIndex()
{
    QModelIndexList selectedIndexes = this->ui.IdeasTableView->selectionModel()->selectedIndexes();
    if (selectedIndexes.size() == 0)
    {
        this->ui.descriptionLineEdit->clear();
        this->ui.actLineEdit->clear();
      

        return -1;


    }
    int selectedIndex = selectedIndexes.at(0).row();


    return selectedIndex;
}
