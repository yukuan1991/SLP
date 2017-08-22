#pragma once

#include <QDialog>
#include <memory>

namespace Ui {
class RelationSetDialog;
}

class OperationUnitDelegate;
class OperationUnitModel;
class OperationUnitNameDelegate;

class RelationSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RelationSetDialog(QWidget *parent = 0);
    ~RelationSetDialog();

    QVariant dump() const;
    void load(const QVariant& data);

private:
    void setTable(int rows, int cols);
    void initConn();
    void buttonModify();
private:
    std::unique_ptr<OperationUnitDelegate> delegate_;
    std::unique_ptr<OperationUnitModel> model_;
    std::unique_ptr<OperationUnitNameDelegate> nameDelegate_;
private:
    Ui::RelationSetDialog *ui;
};

