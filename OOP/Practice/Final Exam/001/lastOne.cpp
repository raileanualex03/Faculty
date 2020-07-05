#include "lastOne.h"
# include "qmessagebox.h"
#include "ViewWidget.h"
lastOne::lastOne(Controller& controller, Astronomer astronomer, QWidget *parent)
    : controller{ controller }, astronomer{ astronomer }, QMainWindow(parent)
{
    this->controller.saveFile();
    ui.setupUi(this);
    this->model = new MyListTableModel(controller, false, astronomer.getConstellation());
    this->ui.starsTable->setModel(model);
    this->setWindowTitle(QString::fromStdString(astronomer.getName()));

    makeConnections();
}

void lastOne::makeConnections()
{
    QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &lastOne::add);
    QObject::connect(this->ui.checkBox, &QCheckBox::stateChanged, this, &lastOne::showStars);
    QObject::connect(this->ui.lineEdit, &QLineEdit::textChanged, this, &lastOne::search);
    QObject::connect(this->ui.exitButton, &QPushButton::clicked, this, &lastOne::quit);
    QObject::connect(this->ui.viewButton, &QPushButton::clicked, this, &lastOne::view);

}

void lastOne::update()
{
    if (this->ui.checkBox->isChecked() == true) {
        this->model = new MyListTableModel(controller, true, this->astronomer.getConstellation());
        this->ui.starsTable->setModel(model);
    }
    else {
        this->model = new MyListTableModel(controller, false, this->astronomer.getConstellation());
        this->ui.starsTable->setModel(model);
    }
}

void lastOne::add()
{
    std::string description, constellation, ascension, declination, diameter;
    description = this->ui.nameLineEdit->text().toStdString();
    if (description.length() == 0) {
        QMessageBox::critical(this, "error", "prove description");
        return;
    }
    constellation = this->astronomer.getConstellation();
    ascension = this->ui.ascensionLneEdit->text().toStdString();
    if (ascension.length() == 0) {
        QMessageBox::critical(this, "error", "prove description");
        return;
    }
    declination = this->ui.declinationLineEdit->text().toStdString();
    if (ascension.length() == 0) {
        QMessageBox::critical(this, "error", "prove declination");
        return;
    }
    diameter = this->ui.diameterLineEdit->text().toStdString();
    if (ascension.length() == 0) {
        QMessageBox::critical(this, "error", "prove diameter");
        return;
    }
    try {
        this->controller.addStar(description, constellation, ascension, declination, diameter);
    }
    catch (std::exception& e) {
        QMessageBox::critical(this, "error", e.what());
        return;
    }

    this->controller.saveFile();
    this->update();
}

void lastOne::search()
{
    std::string name = this->ui.lineEdit->text().toStdString();
    this->ui.listWidget->clear();
    std::vector<Star> elems = this->controller.search(name);
    int index = 0;
    for (Star s : elems) {
            this->ui.listWidget->addItem(QString::fromStdString(s.toString()));
            std::string color = "red";
            this->ui.listWidget->item(index)->setForeground(QColor(color.c_str()));
            index++;
        
    }
}

void lastOne::quit()
{
    this->controller.saveFile();
    exit(0);
}

void lastOne::showStars()
{
    if (this->ui.checkBox->isChecked()== true) {
        delete this->model;
        this->model = new MyListTableModel(controller, true, this->astronomer.getConstellation());
        this->ui.starsTable->setModel(model);
    }
    else {
        this->model = new MyListTableModel(controller, false, this->astronomer.getConstellation());
        this->ui.starsTable->setModel(model);
    }
}

void lastOne::view()
{
    Star* st;
    std::string name = this->ui.nameLineEdit->text().toStdString();
    if (name.length() ==0) {
        QMessageBox::critical(this, "error", "Provide name for the star before pressing view!");
        return;
    }
    for (auto s : this->controller.getStars()) {
        if (s.getName() == name) {
            st = new Star{s};
            ViewWidget* vw = new ViewWidget(this->controller, *st);
            vw->show();
        }
    }
    delete model;
    this->model = new MyListTableModel(controller, true, this->astronomer.getConstellation(), st->getName());
    this->ui.starsTable->setModel(model);
}
