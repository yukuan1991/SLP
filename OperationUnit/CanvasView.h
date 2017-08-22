#pragma once
#include <QGraphicsView>
#include "CanvasScene.h"
#include <memory>
#include "OperationUnit/RelationSetDialog.h"
#include <QDebug>
#include <base/lang/not_null.h>

class AbstractItem;
class AbstractLine;

class CanvasView : public QGraphicsView
{
public:
    template<typename ...ARGS>
    CanvasView(ARGS && ...args) : QGraphicsView(std::forward<ARGS> (args)...) { init(); }

    ~CanvasView() override;

    void relationSetDlgExec();
private:
    void init();
    void generateChart (const QVariantMap &data);
    AbstractItem * makeItem (const QString & type);
    AbstractLine * makeLine (not_null<AbstractItem *> p1, not_null<AbstractItem*> p2, char type);
private:
    std::unique_ptr<CanvasScene> scene_;
    RelationSetDialog relationSetDlg_;
};
