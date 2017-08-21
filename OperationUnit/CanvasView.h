﻿#pragma once
#include <QGraphicsView>
#include "CanvasScene.h"
#include <memory>
#include "OperationUnit/RelationSetDialog.h"
#include <QDebug>

class CanvasView : public QGraphicsView
{
public:
    template<typename ...ARGS>
    CanvasView(ARGS && ...args) : QGraphicsView(std::forward<ARGS> (args)...) { init(); }

    ~CanvasView() { qDebug() << "~canvasView()"; }

    void relationSetDlgExec() { relationSetDlg_.exec(); }
private:
    void init();
private:
    std::unique_ptr<CanvasScene> scene_;
    RelationSetDialog relationSetDlg_;
};
