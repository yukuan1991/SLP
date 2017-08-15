#include "transportArea.h"
#include <QPainter>

transportArea::transportArea(QGraphicsItem *parent)
    : abstractItem (parent)
{

}

void transportArea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor(255, 128, 0));

    static const QPointF points[7] = {
        QPointF(0, itemHeight / 3),
        QPointF(itemWidth / 2, itemHeight / 3),
        QPointF(itemWidth / 2, 0),
        QPointF(itemWidth, itemHeight / 2),
        QPointF(itemWidth / 2, itemHeight),
        QPointF(itemWidth /2, itemHeight * 2 / 3),
        QPointF(0, itemHeight * 2 / 3)
    };

    painter->drawPolygon(points, 7);

}
