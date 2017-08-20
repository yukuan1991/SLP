#include "AbstractLine.h"
#include <assert.h>

AbstractLine::AbstractLine(not_null<AbstractItem *> start, not_null<AbstractItem *> stop)
{
    connect (start, &QGraphicsObject::xChanged, this, &AbstractLine::resetStartX);
    connect (start, &QGraphicsObject::yChanged, this, &AbstractLine::resetStartY);
    connect (stop, &QGraphicsObject::xChanged, this, &AbstractLine::resetStopX);
    connect (stop, &QGraphicsObject::yChanged, this, &AbstractLine::resetStopY);

    connect (start, &QObject::destroyed, this, &QObject::deleteLater);
    connect (stop, &QObject::destroyed, this, &QObject::deleteLater);
}

void AbstractLine::resetStartX() noexcept
{
    const auto src = dynamic_cast<QGraphicsObject*> (sender ()); assert (src);
    start_.setX (src->pos ().x ());
    update ();
}

void AbstractLine::resetStopX() noexcept
{
    const auto src = dynamic_cast<QGraphicsObject*> (sender ()); assert (src);
    stop_.setX (src->pos ().x ());
    update ();
}

void AbstractLine::resetStartY() noexcept
{
    const auto src = dynamic_cast<QGraphicsObject*> (sender ()); assert (src);
    start_.setY (src->pos ().y ());
    update ();
}

void AbstractLine::resetStopY() noexcept
{
    const auto src = dynamic_cast<QGraphicsObject*> (sender ()); assert (src);
    stop_.setY (src->pos ().y ());
    update ();
}

AbstractLine::~AbstractLine ()
{

}
