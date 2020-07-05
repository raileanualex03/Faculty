#include "MyListTableModel.h"
# include <qvariant.h>
int MyListTableModel::rowCount(const QModelIndex& parent) const
{
	return this->repo.getAll().size();
}

int MyListTableModel::columnCount(const QModelIndex& parent) const
{
	return 6;
}

QVariant MyListTableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row(); 
	std::vector<Star> elems;
	int column = index.column();
	if (showConstellation == false) {
		elems = this->repo.getAll();
	}
	else {
		for (auto elem : this->repo.getAll()) {
			if (elem.getConstellation() == constellation)
				elems.push_back(elem);
		}
	}
	if (index.row() >= elems.size())
		return QVariant{};
	Star currentStar = elems[row];
	
	if (role == Qt::DisplayRole) {
		switch (column) {
		case 0:
			return QString::fromStdString(currentStar.getName());
		case 1:
			return QString::fromStdString(currentStar.getConstellation());
		case 2:
			return QString::number(currentStar.getAscension());
		case 3:
			return QString::number(currentStar.getDeclination());
		case 4:
			return QString::number(currentStar.getDiameter());
		case 5:
			if (showConstellation == true && currentStar.getName() == name) {
				return QString::fromStdString(currentStar.getConstellation());
			}
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
				return QString("Name");
			case 1:
				return QString("Constellation");
			case 2:
				return QString("Right Ascension");
			case 3:
				return QString("Declination");
			case 4:
				return QString("Diameter");
			case 5:
				return QString("Constellation");
			default:
				break;
			}
		}
	}

	return QVariant();
}
