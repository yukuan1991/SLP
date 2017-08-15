#include "canvasView.h"
#include <QInputDialog>
#include "item/processingZone.h"
#include "item/assemblyArea.h"
#include "item/transportArea.h"

#include <QDebug>


void canvasView::init()
{
    qDebug() << "canvasView::init()";
    scene_ = std::make_unique<canvasScene>(QRectF{0, 0, 1500, 1200});
//    this->setScene(scene_.get());
    auto ptr_scene = scene_.get();
    this->setScene(ptr_scene);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    setRenderHints (QPainter::SmoothPixmapTransform);


    auto process = new processingZone;
    scene_->addItem(process);
    auto assembly = new assemblyArea;
    scene_->addItem(assembly);
    auto transport = new transportArea;
    scene_->addItem(transport);

}
