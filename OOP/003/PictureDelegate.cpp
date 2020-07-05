#include "PictureDelegate.h"
#include <QPixmap>
#include <QPainter>
#include "domain.h"
#include <QtWidgets\qmessagebox.h>

PictureDelegate::PictureDelegate(QWidget* parent) : QStyledItemDelegate{ parent }
{
}

void PictureDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	QString organism = index.model()->data(index, Qt::DisplayRole).toString();
	
	// show a picture only in the fifth column; the other columns remain unchanged
	if (index.column() != 5)
	{
		QStyledItemDelegate::paint(painter, option, index);
		return;
	}

	if (organism.contains("Bumblebee"))
	{
		QPixmap pixMap("Bumblebee.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (organism.contains("OptimusPrime"))
	{
		QPixmap pixMap("OptimusPrime.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (organism.contains("Jetfire"))
	{
		QPixmap pixMap("Jetfire.jfif");
		painter->drawPixmap(option.rect, pixMap);
	}
	else if (organism.contains("SoundWave"))
	{
		QPixmap pixMap("SoundWave.jpg");
		painter->drawPixmap(option.rect, pixMap);
	}

	else if (organism.contains("Megatron"))
	{
		QPixmap pixMap("Megatron.jfif");
		painter->drawPixmap(option.rect, pixMap);
	}
	else {
		QPixmap pixMap("21047");
		painter->drawPixmap(option.rect, pixMap);
	}
}

QSize PictureDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	// show a picture only in the second column; the other columns remain unchanged
	if (index.column() == 5)
	{
		return QSize(32, 100);
	}

	return QStyledItemDelegate::sizeHint(option, index);
}
