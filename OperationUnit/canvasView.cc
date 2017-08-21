#include "CanvasView.h"
#include <QInputDialog>
#include <QGraphicsScene>
#include "item/LineA.h"
#include "item/LineI.h"
#include "item/AssemblyArea.h"
#include "item/LineE.h"
#include "item/LineI.h"
#include "item/LineO.h"
#include "item/LineX.h"
#include "item/ProcessingZone.h"
//#include "item/assemblyArea.h"
//#include "item/transportArea.h"
#include "item/StorageArea.h"
#include "item/CheckingArea.h"
//#include "item/officeArea.h"
//#include "item/stagingArea.h"
//#include "item/serviceArea.h"

#include <QDebug>


void CanvasView::init()
{
    scene_ = std::make_unique<CanvasScene>(QRectF{0, 0, 1500, 1200});
    auto ptr_scene = scene_.get();
    this->setScene(ptr_scene);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    setRenderHints (QPainter::Antialiasing);

    auto item1 = new AssemblyArea;
    item1->setPos (600, 450);

    auto item2 = new StorageArea;
    item2->setPos (400, 400);

    auto item3 = new ProcessingZone;
    item3->setPos (300, 300);

    auto item4 = new CheckingArea;
    item4->setPos (300, 700);

    scene ()->addItem (item1);
    scene ()->addItem (item2);
    scene ()->addItem (item3);
    scene ()->addItem (item4);




    auto line1 = new LineE (item1, item2);
    auto line2 = new LineA (item1, item3);
    auto line3 = new LineI (item2, item3);
    auto line4 = new LineO (item1, item4);
    auto line5 = new LineA (item2, item4);
    auto line6 = new LineX (item3, item4);


    scene ()->addItem (line1);
    scene ()->addItem (line2);
    scene ()->addItem (line3);
    scene ()->addItem (line4);
    scene ()->addItem (line5);
    scene ()->addItem (line6);

}


