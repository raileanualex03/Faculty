#pragma once
#include <qabstractitemmodel.h>
# include "genericRepository.h"
#include "controller.h"
class MyListTableModel :
	public QAbstractTableModel
{
private:
	Repository& repo;

public:
	MyListTableModel(Controller& controller) :repo{ *controller.repositoryAssistant} {}
	MyListTableModel(Repository* repository) : repo{ *repository } {}
	int rowCount(const QModelIndex& parent) const override;
	int columnCount(const QModelIndex& parent ) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;

	friend class MyListViewClass;	
};

