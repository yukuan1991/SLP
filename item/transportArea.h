#pragma once
#include "item/abstractItem.h"

class transportArea : public abstractItem
{
public:
    transportArea(QGraphicsItem* parent = nullptr);
protected:
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget) override;
};

