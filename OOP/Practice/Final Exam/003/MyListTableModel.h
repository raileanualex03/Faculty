#pragma once
#include <qabstractitemmodel.h>
#include "Controller.h"


class MyListTableModel :
	public QAbstractTableModel
{
private:
	Controller& repo;

public:
	MyListTableModel(Controller* repository) : repo{ *repository } {}
	int rowCount(const QModelIndex& parent) const override;
	int columnCount(const QModelIndex& parent) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;

	
	friend class MyListViewClass;
};
