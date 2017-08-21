#pragma once
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

    ~CanvasView() override;

    void relationSetDlgExec();
private:
    void init();
private:
    std::unique_ptr<CanvasScene> scene_;
    RelationSetDialog relationSetDlg_;
};
