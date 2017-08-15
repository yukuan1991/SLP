#include "serviceArea.h"
#include <QPainter>

serviceArea::serviceArea(QGraphicsItem *parent)
    : abstractItem (parent)
{

}

void serviceArea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(Qt::blue);

    int startAngle = 180 * 16;
    int spanAngle = -180 * 16;

    painter->drawChord(QRectF(0, 0, itemWidth, itemHeight), startAngle, spanAngle);
}
