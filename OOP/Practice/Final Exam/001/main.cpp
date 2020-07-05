#include "lastOne.h"
#include <QtWidgets/QApplication>
#include "Star.h"
#include "Astronomer.h"
#include "Repository.h"
#include "Controller.h"
# include "test.h"

int main(int argc, char *argv[])
{
  // testAddController();
  //  testAddRepository();
    QApplication a(argc, argv);
    Repository<Star> rS{ "stars.txt" };
    Repository<Astronomer> rA{ "astronomers.txt" };
    Controller c{ rA, rS };
    std::vector<Astronomer> astronomers = c.getAstronomers();
    for (int i = 0; i < astronomers.size();i++) {
        lastOne* w = new lastOne{c, astronomers[i]};
        c.addObserver(w);
        w->show();
    }
    return a.exec();
}
