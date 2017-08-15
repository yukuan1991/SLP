#include "officeArea.h"
#include <QPainter>

officeArea::officeArea(QGraphicsItem *parent)
    : abstractItem (parent)
{

}

void officeArea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(Qt::gray);

    static const QPointF points[7] = {
        QPointF(0, itemHeight / 3),
        QPointF(itemWidth / 2, 0),
        QPointF(itemWidth, itemHeight / 3),
        QPointF(itemWidth * 2 / 3, itemHeight / 3),
        QPointF(itemWidth * 2 / 3, itemHeight),
        QPointF(itemWidth / 3, itemHeight),
        QPointF(itemWidth / 3, itemHeight / 3)
    };

    painter->drawPolygon(points, 7);
}
