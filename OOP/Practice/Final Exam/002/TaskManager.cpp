#include "TaskManager.h"
# include <qmessagebox.h>

TaskManager::TaskManager(Controller& c, Programmer& p, QWidget* parent )
    :programmer{ p }, controller{ c }, QMainWindow(parent)
{
    ui.setupUi(this);
    this->makeConnections();
    this->populateList();
    this->setWindowTitle(QString::fromStdString(p.getName()));
}

void TaskManager::populateList()
{
    this->ui.TasksList->clear();
    std::vector<Task> tasks = this->controller.getTasks();
    sort(tasks.begin(), tasks.end(), [](Task t1, Task t2) {
        return t1.getStatus() > t2.getStatus();
        });
    int index = 0;
    for (auto task : tasks) {
        if (task.getStatus() == "in progress" && task.getID() == this->programmer.getID()) {
            this->ui.TasksList->addItem(QString::fromStdString(task.toString() + " name:" + this->programmer.getName()));
            this->ui.TasksList->item(index)->setForeground(QColor("red"));
            index++;
        }
        else {
            this->ui.TasksList->addItem(QString::fromStdString(task.toString()));
            this->ui.TasksList->item(index)->setForeground(QColor("red"));
            index++;
        }
    }
}

int TaskManager::getSelectedIndexes()
{
    QModelIndexList selectedIndexes = this->ui.TasksList->selectionModel()->selectedIndexes();
    if (selectedIndexes.size() == 0) {
        this->ui.descriptionLineEdit->clear();
        this->ui.IDLineEdit->clear();
        this->ui.statusLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();

    return selectedIndex;
}

void TaskManager::makeConnections()
{
    QObject::connect(this->ui.TasksList, &QListWidget::itemSelectionChanged, [this]() {
        int selectedIndex = this->getSelectedIndexes();
        if (selectedIndex < 0)
            return;
        Task task = this->controller.getTasks()[selectedIndex];
        this->ui.descriptionLineEdit->setText(QString::fromStdString(task.getDescription()));
        this->ui.statusLineEdit->setText(QString::fromStdString(task.getStatus()));
        this->ui.IDLineEdit->setText(QString::fromStdString(std::to_string(task.getID())));
        std::string status = this->ui.statusLineEdit->text().toStdString();
        if (status == "closed") {
            this->ui.doneButton->setEnabled(false);
        }
        else {
            this->ui.doneButton->setEnabled(true);
        }
        });
    QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &TaskManager::addTask);
    QObject::connect(this->ui.removeButton, &QPushButton::clicked, this, &TaskManager::removeTask);
    QObject::connect(this->ui.startButton, &QPushButton::clicked, this, &TaskManager::start);
    QObject::connect(this->ui.doneButton, &QPushButton::clicked, this, &TaskManager::done);
}

void TaskManager::addTask()
{
    std::string description, status, id;
    description = this->ui.descriptionLineEdit->text().toStdString();
    status = this->ui.statusLineEdit->text().toStdString();
    id = this->ui.IDLineEdit->text().toStdString();
    if (id.length() == 0) {
        QMessageBox::critical(this, "error", "provide ID! ( -1 for empty programmer)");
        return;
    }
    if (description.length() == 0) {
        QMessageBox::critical(this, "error", "provide description!");
        return;
    }
    if (status.length() == 0) {
        QMessageBox::critical(this, "error", "provide status");
        return;
    }
    try {
        this->controller.addTask(description, status, id);
    }
    catch (std::exception e) {
        QMessageBox::critical(this, "error", e.what());
    }
    this->populateList();

}

void TaskManager::removeTask()
{
    std::string description, status, id;
    description = this->ui.descriptionLineEdit->text().toStdString();
    status = this->ui.statusLineEdit->text().toStdString();
    id = this->ui.IDLineEdit->text().toStdString();
    if (id.length() == 0) {
        QMessageBox::critical(this, "error", "provide ID! ( -1 for empty programmer)");
        return;
    }
    if (description.length() == 0) {
        QMessageBox::critical(this, "error", "provide description!");
        return;
    }
    if (status.length() == 0) {
        QMessageBox::critical(this, "error", "provide status");
        return;
    }
    try {
        this->controller.removeTask(description, status, id);
    }
    catch (std::exception e) {
        QMessageBox::critical(this, "error", e.what());
    }
    this->populateList();

}

void TaskManager::start()
{
    std::string description, status, id;
    description = this->ui.descriptionLineEdit->text().toStdString();
    status = this->ui.statusLineEdit->text().toStdString();
    id = this->ui.IDLineEdit->text().toStdString();
    Task t{ description, status, std::stoi(id) };
    try {
        this->controller.updateTask(t, this->programmer);
        this->populateList();
    }
    catch (std::exception e) {
        QMessageBox::critical(this, "error", e.what());
    }
}

void TaskManager::done()
{
    std::string description, status, id;
    description = this->ui.descriptionLineEdit->text().toStdString();
    status = this->ui.statusLineEdit->text().toStdString();
    id = this->ui.IDLineEdit->text().toStdString();
    Task t{ description, status, std::stoi(id) };
    try {
        this->controller.finishTask(t);
        this->populateList();
    }
    catch (std::exception e) {
        QMessageBox::critical(this, "error", e.what());
    }
}

void TaskManager::update()
{
    this->populateList();
}
