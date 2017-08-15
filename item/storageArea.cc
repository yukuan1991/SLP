#include "storageArea.h"
#include <QPainter>

storageArea::storageArea(QGraphicsItem *parent)
    : abstractItem (parent)
{

}

void storageArea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(QColor(255, 128, 0));
    static const QPointF points[3] = {
        QPointF(0, 0),
        QPointF(itemWidth, 0),
        QPointF(itemWidth / 2, itemHeight)
    };

    painter->drawPolygon(points, 3);
}
