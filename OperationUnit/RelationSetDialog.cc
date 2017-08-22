#include "RelationSetDialog.h"
#include "ui_relationsetdialog.h"
#include "OperationUnitDelegate.h"
#include <memory>
#include <assert.h>
#include "OperationUnitModel.h"
#include <QMessageBox>
#include "OperationUnit/OperationUnitNameDelegate.h"
#include <base/lang/not_null.h>

using std::make_unique;

RelationSetDialog::RelationSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RelationSetDialog)
{
    ui->setupUi(this);

    ui->lineEdit->setValidator(new QIntValidator(1, 999, this));
    initConn();
}

RelationSetDialog::~RelationSetDialog()
{
    delete ui;
}

QVariant RelationSetDialog::dump() const
{
    if (model_ == null)
    {
        return {};
    }
    QVariantList relation;

    for (int col = 0; col < model_->columnCount (); col ++)
    {
        for (int row = col + 1; row < model_->columnCount (); row ++)
        {
            const auto cellData = model_->index (row, col).data (Qt::DisplayRole).toString ();
            if (cellData.isEmpty ())
            {
                return {};
            }

            relation.push_back (QString::number (row) + " " + QString::number (col) + " " + cellData);
        }
    }

    const auto model = ui->operationUnitForm->model (); assert (model);

    QVariantList operationList;
    for (auto row = 0; row < model->rowCount (); row ++)
    {
        QVariantMap map;
        map ["name"] = model->data (model->index (row, 0), Qt::DisplayRole).toString ();
        map ["type"] = model->data (model->index (row, 1), Qt::DisplayRole).toString ();

        operationList.append (map);
    }

    QVariantMap totalMap;
    totalMap ["relation"] = relation;
    totalMap ["operations"] = operationList;

    return totalMap;
}

void RelationSetDialog::setTable(int rows, int cols)
{
    model_ = make_unique<OperationUnitModel> (rows, cols, this);
    delegate_ = make_unique<OperationUnitDelegate> (this);

    ui->tableView->setModel(model_.get ());
    ui->tableView->setItemDelegate(delegate_.get ());
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            auto item = std::make_unique<QStandardItem> ();
            if (i >= rows - 2)
            {
                item->setBackground (QColor (230, 230, 230));
            }
            model_->setItem(i, j, item.release ());
            model_->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    for(int row = 0; row < cols; row++)
    {
        int col = row;
        model_->item(row, col)->setEditable(false);
        model_->item(row, col)->setBackground(Qt::gray);
    }

    model_->setHeaderData(rows - 2, Qt::Vertical, "综合接近程度");
    model_->setHeaderData(rows - 1, Qt::Vertical, "排序");
    ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);


    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(6);
    QStringList horizontalHeader;
    horizontalHeader << "密切程度" << "分值";
    ui->tableWidget->setHorizontalHeaderLabels(horizontalHeader);
    QStringList verticalHeader;
    verticalHeader << "A" << "E" << "I" << "O" << "U" << "X";
    ui->tableWidget->setVerticalHeaderLabels(verticalHeader);
    for(int row = 0; row < 6; row++)
    {
        for(int col = 0; col < 2; col++)
        {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem);
        }
    }
    ui->tableWidget->item(0, 0)->setData(Qt::DisplayRole, "绝对必要");
    ui->tableWidget->item(1, 0)->setData(Qt::DisplayRole, "特别重要");
    ui->tableWidget->item(2, 0)->setData(Qt::DisplayRole, "重要");
    ui->tableWidget->item(3, 0)->setData(Qt::DisplayRole, "一般");
    ui->tableWidget->item(4, 0)->setData(Qt::DisplayRole, "不重要");
    ui->tableWidget->item(5, 0)->setData(Qt::DisplayRole, "不希望");
    ui->tableWidget->item(0, 1)->setData(Qt::DisplayRole, 4);
    ui->tableWidget->item(1, 1)->setData(Qt::DisplayRole, 3);
    ui->tableWidget->item(2, 1)->setData(Qt::DisplayRole, 2);
    ui->tableWidget->item(3, 1)->setData(Qt::DisplayRole, 1);
    ui->tableWidget->item(4, 1)->setData(Qt::DisplayRole, 0);
    ui->tableWidget->item(5, 1)->setData(Qt::DisplayRole, -1);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    auto nameModel = std::make_unique<QStandardItemModel> (cols, 2, this);
    nameModel->setHeaderData(0, Qt::Horizontal, "作业单位名称");
    nameModel->setHeaderData(1, Qt::Horizontal, "作业单位工作性质");
    for(int i = 0; i < cols; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            auto item = std::make_unique<QStandardItem> ();
            nameModel->setItem(i, j, item.release ());
            nameModel->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
    }

    nameDelegate_ = std::make_unique<OperationUnitNameDelegate> ();

    ui->operationUnitForm->setModel(nameModel.release());
    ui->operationUnitForm->setItemDelegate(nameDelegate_.get());
    ui->operationUnitForm->setColumnWidth(1, 150);
}

void RelationSetDialog::initConn()
{
    connect(ui->buttonModify, &QPushButton::clicked, this, &RelationSetDialog::buttonModify);

    connect(ui->buttonConfirm, &QPushButton::clicked, this, &RelationSetDialog::accept);
    connect(ui->buttonCancel, &QPushButton::clicked, this, &RelationSetDialog::reject);

}

void RelationSetDialog::buttonModify()
{
    /// 很不优雅 QMessageBox::question
    if (model_ != null)
    {
        auto ret = QMessageBox::question(this, "设置", "是否修改当前作业单位数？", "是", "否");
        constexpr auto yes = 0;
        if(ret != yes)
        {
            return;
        }
    }

    const auto text = ui->lineEdit->text();
    bool isOk = false;
    const auto num = text.toInt(&isOk);

    if(isOk)
    {
        this->setTable(num + 2, num);
    }
}

