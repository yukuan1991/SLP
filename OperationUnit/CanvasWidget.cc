#include "CanvasWidget.h"
#include "ui_canvaswidget.h"

CanvasWidget::CanvasWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CanvasWidget)
{
    ui->setupUi(this);
}

CanvasWidget::~CanvasWidget()
{
    delete ui;
}
