#include "canvasScene.h"
#include <QPainter>
#include <base/lang/scope.hpp>
#include <QDebug>
#include <QTableWidget>
#include <QTableView>
#include <QStandardItemModel>
#include "OperationUnitDelegate.h"

void canvasScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsScene::drawBackground(painter, rect);
//    painter->setBrush(Qt::white);

//    auto center_point = sceneRect().center();
//    effective_rect_ = QRectF (center_point - QPointF (width_ / 2, height_ / 2), QSizeF (width_, height_));
    //    painter->drawRect(effective_rect_);
}

//void canvasScene::setTable(int row, int column)
//{
//    auto tablewidget_ = new QTableView;
//    auto model = new QStandardItemModel(row, column, this);
//    tablewidget_->setModel(model);
//    tablewidget_->setItemDelegate(new OperationUnitDelegate(this));
//    tablewidget_->setEditTriggers (QAbstractItemView::DoubleClicked);

////    auto tablewidget_ = new QTableWidget(row, column);

////    tablewidget_->resize(400, 400);

//    tablewidget_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//    tablewidget_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

//    addWidget(tablewidget_);
////    for (int i = 0; i < row; i ++)
////    {
////        for(int j = 0; j < column; j++)
////        {
//////            tablewidget_->setItemDelegate(i, j, new OperationUnitDelegate);
//////            tablewidget_->item(i, j)->setTextAlignment(Qt::AlignCenter);
////        }
////    }
//}


void canvasScene::init()
{
    qDebug() << "canvasScene::init()";
    setBackgroundBrush(QColor (230, 230, 230));
}
