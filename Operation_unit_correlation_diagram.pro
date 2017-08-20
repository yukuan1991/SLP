#-------------------------------------------------
#
# Project created by QtCreator 2017-08-10T13:49:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG -= c++11
QMAKE_CXXFLAGS += -std=c++1z

TARGET = Operation_unit_correlation_diagram
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cc\
        OperationUnitRelationMain.cc \
    OperationUnit/Ribbon.cc \
    OperationUnit/canvasView.cc \
    OperationUnit/canvasScene.cc \
    OperationUnitDelegate.cc \
    OperationUnitModel.cc \
    OperationUnit/OperationUnitRelationAnalysis.cc \
    OperationUnit/OperationUnitRibbon.cc \
    OperationUnit/RelationSetDialog.cc \
    item/abstractItem.cc \
    item/processingZone.cc \
    item/assemblyArea.cc \
    item/transportArea.cc \
    item/storageArea.cc \
    item/checkingArea.cc \
    item/officeArea.cc \
    item/stagingArea.cc \
    item/serviceArea.cc \
    item/AbstractLine.cc

HEADERS  += OperationUnitRelationMain.h \
    OperationUnit/Ribbon.h \
    OperationUnit/canvasView.h \
    OperationUnit/canvasScene.h \
    OperationUnitDelegate.h \
    OperationUnitModel.h \
    OperationUnit/OperationUnitRelationAnalysis.h \
    OperationUnit/OperationUnitRibbon.h \
    OperationUnit/RelationSetDialog.h \
    item/abstractItem.h \
    item/processingZone.h \
    item/assemblyArea.h \
    item/transportArea.h \
    item/storageArea.h \
    item/checkingArea.h \
    item/officeArea.h \
    item/stagingArea.h \
    item/serviceArea.h \
    item/AbstractLine.h

FORMS    += operationunitrelationmain.ui \
    OperationUnit/form.ui \
    OperationUnit/operationunitrelationanalysis.ui \
    OperationUnit/relationsetdialog.ui

LIBS += -lboost_filesystem
LIBS += -lboost_system

DISTFILES +=
