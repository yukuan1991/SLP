#pragma once
#include <QGraphicsObject>
#include "item/abstractItem.h"
#include <base/lang/not_null.h>


class AbstractLine : public QGraphicsObject
{
    Q_OBJECT
public:
    AbstractLine(not_null<AbstractItem *> item1, not_null<AbstractItem *> item2);
    ~AbstractLine () override;

    QPointF start () const noexcept { return start_; }
    QPointF stop () const noexcept { return stop_; }
private:
    void resetStartX () noexcept;
    void resetStopX () noexcept;
    void resetStartY () noexcept;
    void resetStopY () noexcept;
private:
    QPointF start_ = {0, 0}, stop_ = {0, 0};
};


