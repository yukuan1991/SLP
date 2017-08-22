#pragma once
#include <QGraphicsScene>
#include <memory>
#include <QDebug>

class CanvasScene : public QGraphicsScene
{
public:
    template<typename ... ARGS>
    CanvasScene(ARGS && ...args) : QGraphicsScene(std::forward<ARGS>(args)...)
    {
        init();
        setWorkUnitAreaLegend();
        setWorkUnitRelationshipLegend();

    }
    ~CanvasScene() { qDebug() << "~canvasScene()"; }
    QRectF effectiveRect() const { return effective_rect_; }
protected:
    void drawBackground(QPainter* painter, const QRectF &rect) override;
private:
    void init();
    qreal calculateMark();
    void setWorkUnitAreaLegend();
    void setWorkUnitRelationshipLegend();
private:
    qreal height_ = 1000;
    qreal width_ = 1000;
    QRectF effective_rect_;
};

