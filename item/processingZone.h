#pragma once
#include "item/abstractItem.h"


class processingZone : public AbstractItem
{
public:
    processingZone(QGraphicsItem *parent = nullptr);
protected:
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget) override;
};

