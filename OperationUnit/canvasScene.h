#pragma once
#include <QGraphicsScene>
#include <memory>
#include <QDebug>

class canvasScene : public QGraphicsScene
{
public:
    template<typename ... ARGS>
    canvasScene(ARGS && ...args) : QGraphicsScene(std::forward<ARGS>(args)...) { init(); }
    ~canvasScene() { qDebug() << "~canvasScene()"; }

//    void setTable(int row,int column);
protected:
    void drawBackground(QPainter* painter, const QRectF &rect) override;
private:
    void init();
    qreal height_ = 1000;
    qreal width_ = 1000 * 1.4142135;
    QRectF effective_rect_;
};

