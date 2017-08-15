#pragma once
#include "abstractItem.h"


class serviceArea : public abstractItem
{
public:
    serviceArea(QGraphicsItem *parent = nullptr);
protected:
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget) override;
};

