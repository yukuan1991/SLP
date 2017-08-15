#include "checkingArea.h"
#include <QPainter>

checkingArea::checkingArea(QGraphicsItem *parent)
    : abstractItem (parent)
{

}

void checkingArea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);

    painter->drawRect(QRectF(0, 0, itemWidth, itemHeight));
}
