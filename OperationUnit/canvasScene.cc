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
    painter->setBrush(Qt::white);

    auto center_point = sceneRect().center();
    effective_rect_ = QRectF (center_point - QPointF (width_ / 2, height_ / 2), QSizeF (width_, height_));
        painter->drawRect(effective_rect_);
}

void canvasScene::init()
{
    qDebug() << "canvasScene::init()";
    setBackgroundBrush(QColor (230, 230, 230));
}
