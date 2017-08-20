﻿#pragma once
#include <QGraphicsScene>
#include <memory>
#include <QDebug>

class canvasScene : public QGraphicsScene
{
public:
    template<typename ... ARGS>
    canvasScene(ARGS && ...args) : QGraphicsScene(std::forward<ARGS>(args)...)
    {
        init();
        setWorkUnitAreaLegend();
        setWorkUnitRelationshipLegend();

    }
    ~canvasScene() { qDebug() << "~canvasScene()"; }

protected:
    void drawBackground(QPainter* painter, const QRectF &rect) override;
private:
    void init();
    void setWorkUnitAreaLegend();
    void setWorkUnitRelationshipLegend();
private:
    qreal height_ = 1000;
    qreal width_ = 1000;
    QRectF effective_rect_;
};

