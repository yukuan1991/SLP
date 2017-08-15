#include "OperationUnitRelationMain.h"
#include "ui_operationunitrelationmain.h"
#include <QMdiSubWindow>
#include "OperationUnit/RelationSetDialog.h"

OperationUnitRelationMain::OperationUnitRelationMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OperationUnitRelationMain)
{
    ui->setupUi(this);
    initConn();
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
    setWindowState(Qt::WindowMaximized);
}

OperationUnitRelationMain::~OperationUnitRelationMain()
{
    delete ui;
}

void OperationUnitRelationMain::initConn()
{
    connect(ui->rib, &OperationUnitRibbon::fileNew, this, &OperationUnitRelationMain::newBuild);
    connect(ui->rib, &OperationUnitRibbon::relationSetClicked, this, &OperationUnitRelationMain::relationSet);
}

void OperationUnitRelationMain::newBuild()
{
    auto w = createWindow();
    w->setOperationUnitCount();
}

void OperationUnitRelationMain::relationSet()
{
    RelationSetDialog dlg;
    dlg.exec();
}

not_null<OperationUnitRelationAnalysis *> OperationUnitRelationMain::createWindow()
{
    auto analysis = std::make_unique<OperationUnitRelationAnalysis> ();
    auto ptr_analysis= analysis.get();
    analysis->setAttribute(Qt::WA_DeleteOnClose);
    auto w = ui->mdiArea->addSubWindow (analysis.release());

    w->setWindowState(Qt::WindowMaximized);
    return ptr_analysis;
}

//not_null<canvasView*> OperationUnitRelationMain::createWindow()
//{
//    auto canvas = std::make_unique<canvasView> ();
//    auto ptr_canvas = canvas.get();
//    canvas->setAttribute(Qt::WA_DeleteOnClose);
//    auto w = ui->mdiArea->addSubWindow (canvas.release());

//    w->setWindowState(Qt::WindowMaximized);
//    return ptr_canvas;
//}
