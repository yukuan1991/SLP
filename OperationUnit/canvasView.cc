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
#include <QJsonDocument>

#include <QDebug>
#include <boost/range/adaptor/indexed.hpp>

using namespace boost::adaptors;


CanvasView::~CanvasView()
{

}

void CanvasView::relationSetDlgExec()
{
    if (QDialog::Accepted != relationSetDlg_.exec ())
    {
	return;
    }

    const auto data = relationSetDlg_.dump ();

    generateChart (data.toMap ());
}

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

void CanvasView::generateChart(const QVariantMap & data)
{
    scene ()->clear ();
    const auto list = data ["operations"].toList ();
    const auto lines = data ["relation"].toList ();

    std::map<int, AbstractItem*> items;
    for (auto item : list | indexed ())
    {
	items [item.index ()] = makeItem (item.value ().toMap () ["type"].toString ());
    }

    for (auto & it : lines)
    {
	const auto stringlist = it.toString ().split (" ");
	assert (stringlist.size () == 3);
	makeLine (items[stringlist.at (0).toInt ()], items[stringlist.at (1).toInt ()], stringlist.at (2).toStdString ().at (0));
    }

}

AbstractItem *CanvasView::makeItem(const QString &type)
{
    AbstractItem * item = null;
    if (type == "成型或处理加工区")
    {
	item = new AssemblyArea;
    }
    else if (type == "装配区")
    {
	item = new AssemblyArea;
    }
    else if (type == "与运输有关的作业区域")
    {
	item = new AssemblyArea;
    }
    else if (type == "储存作业区域")
    {
	item = new AssemblyArea;
    }
    else if (type == "停放或暂存区域")
    {
	item = new AssemblyArea;
    }
    else if (type == "检验、测试区域")
    {
	item = new AssemblyArea;
    }
    else if ("服务及辅助作业区域" == type)
    {
	item = new AssemblyArea;
    }
    else if ("办公室规划面积" == type)
    {
	item = new AssemblyArea;
    }
    else
    {
	assert (false);
    }
    scene ()->addItem (item);

    return item;
}

AbstractLine *CanvasView::makeLine(not_null<AbstractItem *> p1, not_null<AbstractItem *> p2, char type)
{
    AbstractLine * line = null;

    if (type == 'A')
    {
	line = new LineA (p1, p2);
    }
    else if (type == 'E')
    {
	line = new LineE (p1, p2);
    }
    else if (type == 'I')
    {
	line = new LineI (p1, p2);
    }
    else if (type == 'O')
    {
	line = new LineO (p1, p2);
    }
    else if (type == 'X')
    {
	line = new LineX (p1, p2);
    }

    if (line != null)
    {
	scene ()->addItem (line);
    }

    return line;
}
