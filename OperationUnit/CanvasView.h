#pragma once
#include <QGraphicsView>
#include "CanvasScene.h"
#include <memory>
#include <QDebug>

class CanvasView : public QGraphicsView
{
public:
    template<typename ...ARGS>
    CanvasView(ARGS && ...args) : QGraphicsView(std::forward<ARGS> (args)...) { init(); }

    ~CanvasView() { qDebug() << "~canvasView()"; }

private:

    void init();
private:
    std::unique_ptr<CanvasScene> scene_;
};
