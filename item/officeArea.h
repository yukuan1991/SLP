#pragma once
#include "abstractItem.h"

class officeArea : public abstractItem
{
public:
    officeArea(QGraphicsItem *parent = nullptr);
protected:
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget) override;
};

