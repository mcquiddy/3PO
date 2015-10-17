#-------------------------------------------------
#
# Project created by QtCreator 2015-10-11T13:45:07
#
#-------------------------------------------------
QT += core gui\
 multimedia \
 serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = POOL
TEMPLATE = app


SOURCES +=Poolmain.cpp\
    Poolgame.cpp \
    bolablanca.cpp \
    bolanegra.cpp \
    bolatiro.cpp \
    core.cpp \
    connectgui.cpp \
    bola.cpp \
    logicbolablanca.cpp \
    logicbolanegra.cpp \
    logicbolatiro.cpp \
    palo.cpp

HEADERS  += \
    Poolgame.h \
    Poolconstants.h \
    bolablanca.h \
    bolanegra.h \
    bolatiro.h \
    linked_list.h \
    Node.h \
    core.h \
    connectgui.h \
    bola.h \
    logicbolablanca.h \
    logicbolanegra.h \
    logicbolatiro.h \
    palo.h

FORMS    +=



OTHER_FILES +=

RESOURCES += \
    rec.qrc
