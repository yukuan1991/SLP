﻿#pragma once
#include "item/abstractItem.h"

class checkingArea : public abstractItem
{
public:
    checkingArea(QGraphicsItem *parent = nullptr);
protected:
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget) override;
};
