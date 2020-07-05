#include "MyListTableModel.h"

int MyListTableModel::rowCount(const QModelIndex& parent) const
{
	return this->repo.getIdeas().size();
}

int MyListTableModel::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant MyListTableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();
	std::vector<Idea> elems = this->repo.getIdeas();
	Idea currentIdea = this->repo.getIdeas()[row];

	if (role == Qt::DisplayRole) {
		switch (column) {
		case 0:
			return QString::fromStdString(currentIdea.getDescription());
		case 1:
			return QString::fromStdString(currentIdea.getStatus());
		case 2:
			return QString::fromStdString(currentIdea.getNameOfCreator());
		case 3:
			return QString::number(currentIdea.getAct());
	
		default:
			break;
		}
	}


	return QVariant();
}

QVariant MyListTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole) {
		if (orientation == Qt::Horizontal) {
			switch (section) {
			case 0:
				return QString("Description");
			case 1:
				return QString("Status");
			case 2:
				return QString("Creator");
			case 3:
				return QString("Act");
			default:
				break;
			}
		}
	}

	return QVariant();
}
