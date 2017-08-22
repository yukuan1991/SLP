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
#include "item/AssemblyArea.h"
#include "item/TransportArea.h"
#include "item/StorageArea.h"
#include "item/CheckingArea.h"
#include "item/OfficeArea.h"
#include "item/StagingArea.h"
#include "item/ServiceArea.h"
#include <QJsonDocument>

#include <QDebug>
#include <boost/range/adaptor/indexed.hpp>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/adaptor/transformed.hpp>

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

	auto op = scene_->items ()
	        | transformed ([] (auto && c) { return dynamic_cast<AbstractItem *>(c); })
	        | filtered ([] (auto && c) { return c != null; });
	auto pos = scene_->effectiveRect().center();
	const auto offset = QPointF(60, 60);
	auto i = 0;
	for(auto && it : op)
	{
		it->setPos(pos + (offset) * i);
		i++;
	}
}

AbstractItem *CanvasView::makeItem(const QString &type)
{
    AbstractItem * item = null;
    if (type == "成型或处理加工区")
    {
	item = new ProcessingZone;
    }
    else if (type == "装配区")
    {
	item = new AssemblyArea;
    }
    else if (type == "与运输有关的作业区域")
    {
	item = new TransportArea;
    }
    else if (type == "储存作业区域")
    {
	item = new StorageArea;
    }
    else if (type == "停放或暂存区域")
    {
	item = new StagingArea;
    }
    else if (type == "检验、测试区域")
    {
	item = new CheckingArea;
    }
    else if ("服务及辅助作业区域" == type)
    {
	item = new ServiceArea;
    }
    else if ("办公室规划面积" == type)
    {
	item = new OfficeArea;
    }
	else
	{
		assert (false);
	}
	connect(item, &AbstractItem::xChanged, this, &CanvasView::itemPositionChanged);
	connect(item, &AbstractItem::xChanged, [] { qDebug() << "xChanged"; });
	connect(item, &AbstractItem::yChanged, this, &CanvasView::itemPositionChanged);

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
