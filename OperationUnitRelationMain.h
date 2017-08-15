#ifndef OPERATIONUNITRELATIONMAIN_H
#define OPERATIONUNITRELATIONMAIN_H

#include <QWidget>
#include <base/lang/not_null.h>
#include "OperationUnit/canvasView.h"
#include "OperationUnit/OperationUnitRelationAnalysis.h"

namespace Ui {
class OperationUnitRelationMain;
}

class OperationUnitRelationMain : public QWidget
{
    Q_OBJECT

public:
    explicit OperationUnitRelationMain(QWidget *parent = 0);
    ~OperationUnitRelationMain();

private:
    void initConn();
private:
    void newBuild();
    void relationSet();
    not_null<canvasView*> createWindow();
private:
    Ui::OperationUnitRelationMain *ui;
};

#endif // OPERATIONUNITRELATIONMAIN_H
