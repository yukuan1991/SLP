#include "canvasView.h"
#include <QInputDialog>
#include <QGraphicsScene>
#include "item/LineA.h"
#include "item/assemblyArea.h"
//#include "item/processingZone.h"
//#include "item/assemblyArea.h"
//#include "item/transportArea.h"
//#include "item/storageArea.h"
//#include "item/checkingArea.h"
//#include "item/officeArea.h"
//#include "item/stagingArea.h"
//#include "item/serviceArea.h"

#include <QDebug>


void canvasView::init()
{
    qDebug() << "canvasView::init()";
    scene_ = std::make_unique<canvasScene>(QRectF{0, 0, 1500, 1200});
    auto ptr_scene = scene_.get();
    this->setScene(ptr_scene);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    setRenderHints (QPainter::Antialiasing);

    auto item1 = new assemblyArea;
    item1->setPos (100, 100);

    auto item2 = new assemblyArea;
    item1->setPos (200, 300);

    scene ()->addItem (item1);
    scene ()->addItem (item2);


    auto line = new LineA (item1, item2);
    scene ()->addItem (line);
}
