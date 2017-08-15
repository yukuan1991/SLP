#pragma once
#include "item/abstractItem.h"

class stagingArea : public abstractItem
{
public:
    stagingArea(QGraphicsItem *parent = nullptr);
protected:
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget) override;
};

