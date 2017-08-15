#pragma once
#include "item/abstractItem.h"


class processingZone : public abstractItem
{
public:
    processingZone(QGraphicsItem *parent = nullptr);
protected:
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget) override;
};

