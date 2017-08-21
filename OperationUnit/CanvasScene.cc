﻿#include "CanvasScene.h"
#include <QPainter>
#include <base/lang/scope.hpp>
#include <QDebug>
#include <QTableWidget>
#include <QTableView>
#include <QStandardItemModel>
#include "OperationUnitDelegate.h"
#include <QTableWidget>
#include <QHeaderView>
#include <QLabel>
#include "item/AbstractLine.h"
#include "item/LineA.h"

void CanvasScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsScene::drawBackground(painter, rect);
    painter->setBrush(Qt::white);

    auto center_point = sceneRect().center();
    effective_rect_ = QRectF (center_point - QPointF (width_ / 2, height_ / 2), QSizeF (width_, height_));
    painter->drawRect(effective_rect_);
    auto mark = calculateMark();
    painter->drawText(effective_rect_.topRight() - QPointF(100, -15), "评估分值:");
    painter->drawText(effective_rect_.topRight() - QPointF(60, -30), QString::number(mark));
}

void CanvasScene::init()
{
    qDebug() << "canvasScene::init()";
    setBackgroundBrush(QColor (230, 230, 230));
}

qreal CanvasScene::calculateMark()
{
    QList<AbstractLine*> lines;
    const auto list = items();
    for(auto & it : list)
    {
        auto line = dynamic_cast<AbstractLine*>(it);
        if(line)
        {
            lines.append(line);
        }
    }
    auto sum = qreal {0};
    qDebug() << "lines.size:" << lines.size();
    for(auto & it : lines)
    {

        const auto start = it->start();
        const auto stop = it->stop();
        sum += it->mark() * (QLineF(start, stop).length() / 150);
    }

    qDebug() << "sum" << sum;
    return sum;
}

void CanvasScene::setWorkUnitRelationshipLegend()
{
    auto table = new QTableWidget(7, 3);
    table->move(2, 276);
    table->resize(202, 212);
    table->horizontalHeader()->hide();
    table->verticalHeader()->hide();
    table->setColumnWidth(0, 80);
    table->setColumnWidth(1, 80);
    table->setColumnWidth(2, 40);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for(int row = 0; row < 7; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            table->setItem(row, col, new QTableWidgetItem);
            table->item(row, col)->setTextAlignment(Qt::AlignCenter);
            table->setRowHeight(row, 30);
        }
    }
    table->item(0, 0)->setData(Qt::DisplayRole, "关系等级");
    table->item(0, 1)->setData(Qt::DisplayRole, "密切程度");
    table->item(0, 2)->setData(Qt::DisplayRole, "连线");
    table->item(1, 0)->setData(Qt::DisplayRole, "A");
    table->item(1, 1)->setData(Qt::DisplayRole, "绝对必要");
    table->item(2, 0)->setData(Qt::DisplayRole, "E");
    table->item(2, 1)->setData(Qt::DisplayRole, "特别重要");
    table->item(3, 0)->setData(Qt::DisplayRole, "I");
    table->item(3, 1)->setData(Qt::DisplayRole, "重要");
    table->item(4, 0)->setData(Qt::DisplayRole, "O");
    table->item(4, 1)->setData(Qt::DisplayRole, "一般");
    table->item(5, 0)->setData(Qt::DisplayRole, "U");
    table->item(5, 1)->setData(Qt::DisplayRole, "不重要");
    table->item(6, 0)->setData(Qt::DisplayRole, "X");
    table->item(6, 1)->setData(Qt::DisplayRole, "不希望");

    {
        QLabel* label = new QLabel;
        QPixmap pix("png/连线A.png");
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter);
        table->setCellWidget(1, 2, label);
    }
    {
        QLabel* label = new QLabel;
        QPixmap pix("png/连线E.png");
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter);
        table->setCellWidget(2, 2, label);
    }
    {
        QLabel* label = new QLabel;
        QPixmap pix("png/连线I.png");
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter);
        table->setCellWidget(3, 2, label);
    }
    {
        QLabel* label = new QLabel;
        QPixmap pix("png/连线O.png");
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter);
        table->setCellWidget(4, 2, label);
    }
    {
        QLabel* label = new QLabel;
        QPixmap pix("png/连线X.png");
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter);
        table->setCellWidget(6, 2, label);
    }

    addWidget(table);
}

void CanvasScene::setWorkUnitAreaLegend()
{
    auto table = new QTableWidget(9, 2);
    table->move(2, 2);
    table->resize(202, 272);
    table->horizontalHeader()->hide();
    table->verticalHeader()->hide();
    table->setColumnWidth(0, 160);
    table->setColumnWidth(1, 40);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 2; col++)
        {
            table->setItem(row, col, new QTableWidgetItem);
            table->item(row, col)->setTextAlignment(Qt::AlignCenter);
            table->setRowHeight(row, 30);
        }
    }
    table->item(0, 0)->setData(Qt::DisplayRole, "作业单位区域");
    table->item(0, 1)->setData(Qt::DisplayRole, "符号");
    table->item(1, 0)->setData(Qt::DisplayRole, "成型或处理加工区");
    table->item(2, 0)->setData(Qt::DisplayRole, "装配区");
    table->item(3, 0)->setData(Qt::DisplayRole, "与运输有关的作业区域");
    table->item(4, 0)->setData(Qt::DisplayRole, "储存作业区域");
    table->item(5, 0)->setData(Qt::DisplayRole, "停放或暂存区域");
    table->item(6, 0)->setData(Qt::DisplayRole, "检验、测试区域");
    table->item(7, 0)->setData(Qt::DisplayRole, "服务及辅助作业区域");
    table->item(8, 0)->setData(Qt::DisplayRole, "办公室或规划面积");

    {
        QLabel* label = new QLabel;
        QPixmap pix("png/加工区.png");
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter);
        table->setCellWidget(1, 1, label);
    }
    {
        QLabel* label = new QLabel;
        QPixmap pix("png/装配区.png");
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter);
        table->setCellWidget(2, 1, label);
    }
    {
        QLabel* label = new QLabel;
        QPixmap pix("png/运输.png");
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter);
        table->setCellWidget(3, 1, label);
    }
    {
        QLabel* label = new QLabel;
        QPixmap pix("png/存储区.png");
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter);
        table->setCellWidget(4, 1, label);
    }
    {
        QLabel* label = new QLabel;
        QPixmap pix("png/暂存区域.png");
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter);
        table->setCellWidget(5, 1, label);
    }
    {
        QLabel* label = new QLabel;
        QPixmap pix("png/检验区域.png");
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter);
        table->setCellWidget(6, 1, label);
    }
    {
        QLabel* label = new QLabel;
        QPixmap pix("png/服务区域.png");
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter);
        table->setCellWidget(7, 1, label);
    }
    {
        QLabel* label = new QLabel;
        QPixmap pix("png/办公室.png");
        label->setPixmap(pix);
        label->setAlignment(Qt::AlignHCenter);
        table->setCellWidget(8, 1, label);
    }

    addWidget(table);

}
