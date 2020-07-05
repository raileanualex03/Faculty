#pragma once
#include <qabstractitemmodel.h>
# include "Controller.h"
class MyListTableModel :
	public QAbstractTableModel
{
private:
	// if needed
	Repository<Star>& repo;
	bool showConstellation;
	std::string constellation;
	std::string name;

public:
	friend class Controller; 
	
	MyListTableModel(Controller& controller, bool show, std::string constellation, std::string name) : repo{ controller.repositoryStars }, showConstellation{ show }, constellation{ constellation }, name{ name }{};

	MyListTableModel(Controller& controller, bool show, std::string constellation)
		: repo{ controller.repositoryStars }, showConstellation{ show }, constellation{ constellation }{name = ""; };
	int rowCount(const QModelIndex& parent) const override;
	int columnCount(const QModelIndex& parent) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

	friend class MyListViewClass;
};

