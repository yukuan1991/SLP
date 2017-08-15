#include "canvasView.h"
#include <QInputDialog>

#include <QDebug>

void canvasView::setOperationUnitCount()
{
    QInputDialog dlg;
    dlg.setWindowTitle("设置作业单位数");
    dlg.setLabelText("请输入作业单位数:");
    dlg.setOkButtonText("确定");
    dlg.setCancelButtonText("取消");
    dlg.setInputMode(QInputDialog::IntInput);
    dlg.setIntRange(1, 999);

    if(dlg.exec() == QDialog::Accepted)
    {
        auto num = dlg.intValue();
//        scene_->setTable(num, num);
    }

}

void canvasView::init()
{
    qDebug() << "canvasView::init()";
    scene_ = std::make_unique<canvasScene>(QRectF{0, 0, 1500, 1200});
//    this->setScene(scene_.get());
    auto ptr_scene = scene_.get();
    this->setScene(ptr_scene);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    setRenderHints (QPainter::SmoothPixmapTransform);

}
