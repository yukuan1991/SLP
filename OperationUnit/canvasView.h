#pragma once
#include <QGraphicsView>
#include "canvasScene.h"
#include <memory>
#include <QDebug>

class canvasView : public QGraphicsView
{
public:
    template<typename ...ARGS>
    canvasView(ARGS && ...args) : QGraphicsView(std::forward<ARGS> (args)...) { init(); }

    ~canvasView() { qDebug() << "~canvasView()"; }
public:
    void setOperationUnitCount();
private:

    void init();
private:
    std::unique_ptr<canvasScene> scene_;
};
