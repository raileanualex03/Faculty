#include "MyListTableModel.h"

int MyListTableModel::rowCount(const QModelIndex& parent) const
{
	return this->repo.getElements().size();
}

int MyListTableModel::columnCount(const QModelIndex& parent) const
{
	return 6;
}

QVariant MyListTableModel::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();
	std::vector<Bot> elems = this->repo.getElements();
	Bot currentBot = this->repo.getElements()[row];

	if (role == Qt::DisplayRole) {
		switch (column) {
		case 0:
			return QString::fromStdString(currentBot.getID());
		case 1:
			return QString::fromStdString(currentBot.getSize());
		case 2:
			return QString::fromStdString(currentBot.getRadioactivityLevel());
		case 3:
			return QString::number(currentBot.getQuantityOfMicrofragments());
		case 4:
			return QString::fromStdString(currentBot.getDigitizedScan());
		case 5:
			return QString::fromStdString(currentBot.getID());
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
				return QString("ID");
			case 1:
				return QString("Size");
			case 2:
				return QString("RadioactivityLevel");
			case 3:
				return QString("QuantityOfMicrofragments");
			case 4:
				return QString("DigitizedScan");
			case 5:
				return QString("Photo");
			default:
				break;
			}
		}
	}

	return QVariant();
}
