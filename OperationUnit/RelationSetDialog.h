#pragma once

#include <QDialog>

namespace Ui {
class RelationSetDialog;
}

class OperationUnitDelegate;
class OperationUnitModel;

class RelationSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RelationSetDialog(QWidget *parent = 0);
    ~RelationSetDialog();

private:
    void setTable(int rows, int cols);
    void initConn();
    void buttonConfirm();
    void buttonCancel();
private:
    OperationUnitDelegate* delegate;
    OperationUnitModel* model;
private:
    Ui::RelationSetDialog *ui;
};

