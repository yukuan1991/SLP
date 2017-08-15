#include "abstractItem.h"
#include <QPainter>

abstractItem::abstractItem(QGraphicsItem *parent)
    : QGraphicsObject (parent)
{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

QRectF abstractItem::boundingRect() const
{
    return QRectF{0, 0, itemWidth, itemHeight};
}

void abstractItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    painter->setPen(Qt::black);
}
