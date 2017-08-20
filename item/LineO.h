#pragma once
#include "item/AbstractLine.h"

class LineO : public AbstractLine
{
public:
    LineO(AbstractItem * start, AbstractItem * stop);
    qreal width () const noexcept override;
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget = null) override;
    QRectF boundingRect () const override;
};

