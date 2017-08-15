#include "OperationUnitRelationMain.h"
#include <QApplication>
#include <boost/filesystem.hpp>
#include <boost/range/adaptors.hpp>
#include <base/io/file/file.hpp>
#include <QTableView>
#include <QStandardItemModel>
#include <OperationUnitDelegate.h>
#include <OperationUnitModel.h>


void setStyle()
{
    using namespace boost::filesystem;

    auto rng = boost::make_iterator_range(directory_iterator("."),
                                          directory_iterator());

    std::string qss;
    for(auto & it : rng)
    {
        if(it.path().extension().string() == ".css")
        {
            auto res = file::read_all(it.path().string().data());
            if(res)
            {
                qss += res.value();
            }
        }
    }
    qApp->setStyleSheet(QString::fromStdString(qss));
    qApp->setFont(QFont("宋体", 11));
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setStyle();
    OperationUnitRelationMain w;
    w.show();

//    auto tablewidget_ = new QTableView;
//    auto model = new QStandardItemModel(10, 10);
//    auto model = new OperationUnitModel;

//    model->setItem(0, 1, new QStandardItem);
//    model->item(0, 1)->setEditable(false);
//    model->item(0, 1)->setBackground(Qt::gray);

//    tablewidget_->setModel(model);
//    auto delegate = new OperationUnitDelegate();

//    tablewidget_->setItemDelegate(delegate);

//    tablewidget_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//    tablewidget_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

//    for(int row = 0; row < 10; row++)
//    {
//        for(int col = 0; col < 10; col++)
//        {
//            QModelIndex index = model->index(row, col, QModelIndex());
//            model->setData(index, QVariant());
//        }
//    }
//    tablewidget_->show();

    return a.exec();
}
