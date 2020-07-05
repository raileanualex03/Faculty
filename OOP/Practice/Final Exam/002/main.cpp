#include "TaskManager.h"
#include <QtWidgets/QApplication>
#include "Controller.h"

int main(int argc, char *argv[])
{
    Repository r{ "programmers.txt", "tasks.txt" };
    Controller c{ r };
    QApplication a(argc, argv);
    std::vector<Programmer> ps = c.getProgrammers();
    for (int i = 0; i < ps.size();i++) {
        TaskManager* w = new TaskManager(c, ps[i]);
        c.addObserver(w);
        w->show();
    }
    return a.exec();
}
