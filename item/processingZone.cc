#include "processingZone.h"
#include "QPainter"

processingZone::processingZone(QGraphicsItem *parent)
    : AbstractItem (parent)
{

}

void processingZone::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    AbstractItem::paint(painter, option, widget);

    painter->setBrush(Qt::green);
    const QRectF rect(0, 0, itemWidth, itemHeight);
    painter->drawEllipse(rect);

}
