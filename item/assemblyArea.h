#pragma once
#include "item/abstractItem.h"


class assemblyArea : public AbstractItem
{
public:
    assemblyArea(QGraphicsItem *parent = nullptr);
protected:
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget) override;
};

