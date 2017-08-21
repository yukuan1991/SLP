#include "OperationUnitRelationMain.h"
#include "ui_operationunitrelationmain.h"
#include <QMdiSubWindow>

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
    connect(ui->rib, &OperationUnitRibbon::relationSetClicked,
            this, &OperationUnitRelationMain::relationSet);
}

void OperationUnitRelationMain::newBuild()
{
    auto w = createWindow();
}

void OperationUnitRelationMain::relationSet()
{
    relationSetDlg_.exec();
}

not_null<CanvasView*> OperationUnitRelationMain::createWindow()
{
    auto canvas = std::make_unique<CanvasView> ();
    auto ptr_canvas = canvas.get();
    canvas->setAttribute(Qt::WA_DeleteOnClose);
    auto w = ui->mdiArea->addSubWindow (canvas.release());

    w->setWindowState(Qt::WindowMaximized);
    return ptr_canvas;
}
