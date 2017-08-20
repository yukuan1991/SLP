#pragma once
#include "item/abstractItem.h"

class stagingArea : public AbstractItem
{
public:
    stagingArea(QGraphicsItem *parent = nullptr);
protected:
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget) override;
};

