#pragma once
#include "abstractItem.h"

class storageArea : public abstractItem
{
public:
    storageArea(QGraphicsItem *parent = nullptr);
protected:
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget) override;
};

