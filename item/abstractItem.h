#pragma once
#include <QGraphicsObject>


class abstractItem : public QGraphicsObject
{
    Q_OBJECT
public:
    abstractItem(QGraphicsItem *parent = nullptr);
protected:
    QRectF boundingRect () const override;
    void paint (QPainter * painter, const QStyleOptionGraphicsItem * option,
                QWidget * widget) override;
protected:
    static constexpr qreal itemWidth = 60;
    static constexpr qreal itemHeight = 60;
};

