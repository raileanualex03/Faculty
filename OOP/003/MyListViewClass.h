
# include "Observer.h"
# include <qwidget.h>
#include "MyListTableModel.h"

# include "ui_MyListViewClass.h"

class MyListViewClass: public QWidget, public Observer
{
private:
	MyListTableModel* model;
public:
	Ui::MyListViewClass ui;
	MyListViewClass(MyListTableModel* model, QWidget* parent = Q_NULLPTR);

	void update() override;

	~MyListViewClass();
};                                                                                                                                                                                                                                                                                                                                                                            