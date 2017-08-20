#pragma once
#include "item/AbstractLine.h"

class LineI : public AbstractLine
{
public:
    LineI(AbstractItem * start, AbstractItem * stop);
    qreal width () const noexcept override;
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget = null) override;
    QRectF boundingRect () const override;
};

