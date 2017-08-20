#include "checkingArea.h"
#include <QPainter>

checkingArea::checkingArea(QGraphicsItem *parent)
    : AbstractItem (parent)
{

}

void checkingArea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED (option);
    Q_UNUSED (widget);
    painter->setBrush(Qt::blue);

    painter->drawRect(QRectF(0, 0, itemWidth, itemHeight));
}
