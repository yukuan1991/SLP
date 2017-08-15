#include "processingZone.h"
#include "QPainter"

processingZone::processingZone(QGraphicsItem *parent)
    : abstractItem (parent)
{

}

void processingZone::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    abstractItem::paint(painter, option, widget);

    painter->setBrush(Qt::green);
    const QRectF rect(0, 0, itemWidth, itemHeight);
    painter->drawEllipse(rect);

    update();
}
