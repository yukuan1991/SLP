﻿#pragma once
#include "item/abstractItem.h"


class assemblyArea : public abstractItem
{
public:
    assemblyArea(QGraphicsItem *parent = nullptr);
protected:
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget) override;
};
