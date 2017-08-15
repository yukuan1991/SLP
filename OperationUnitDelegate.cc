#include "OperationUnitDelegate.h"
#include <QComboBox>
#include <assert.h>

#include <QDebug>

OperationUnitDelegate::OperationUnitDelegate(QObject *parent)
    : QStyledItemDelegate (parent)
{

}

QWidget *OperationUnitDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    auto model = index.model();
    const auto header = model->headerData(index.row(), Qt::Vertical, Qt::DisplayRole).toString();
    if((header == "综合接近程度") or (header == "排序"))
    {
        return nullptr;
    }
    else
    {
        return new QComboBox(parent);
    }
}

void OperationUnitDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    auto model = index.model();
    const auto header = model->headerData(index.row(), Qt::Vertical, Qt::DisplayRole).toString();
    if((header != "综合接近程度") or (header != "排序"))
    {
        QStringList list;
        list << "" << "A" << "E" << "I" << "O" << "U" << "X";
        auto combo = dynamic_cast<QComboBox*>(editor);
        combo->addItems(list);
        if(combo)
        {
            qDebug() << "setCurrentText";
            combo->setCurrentText(index.data().toString());
        }
    }
}

void OperationUnitDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    const auto header = model->headerData(index.row(), Qt::Vertical, Qt::DisplayRole).toString();

    if((header != "综合接近程度") or (header != "排序"))
    {
        auto combo = dynamic_cast<QComboBox*>(editor);
        if(combo)
        {
            model->setData(index, combo->currentText());
            auto relativeIndex = model->index(index.column(), index.row());
            model->setData(relativeIndex, combo->currentText());
        }
    }
}


