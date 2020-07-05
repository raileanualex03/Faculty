#include "ScreenWriting20.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository r{ "screenwriters.txt", "ideas.txt" };
    Controller c{ r };

    for (auto writer : c.getWriters()) {
        ScreenWriting20* w = new ScreenWriting20(c, writer);
        c.addObserver(w);
        w->show();
    }
    return a.exec();
}
