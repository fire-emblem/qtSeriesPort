#-------------------------------------------------
#
# Project created by QtCreator 2016-11-13T17:17:45
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport



TARGET = qtSeriesPort
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    qabout.cpp \
    mtdlg.cpp \
    qcustomplot.cpp \
    wzsd.cpp \
    spcomm.cpp

HEADERS  += mainwindow.h \
    qabout.h \
    mtdlg.h \
    qcustomplot.h \
    wzsd.h \
    thread.h \
    spcomm.h

FORMS    += mainwindow.ui \
    qabout.ui \
    mtdlg.ui \
    wzsd.ui

RESOURCES += \
    icon.qrc

RC_ICONS += image\19.ICO
