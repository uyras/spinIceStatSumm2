#-------------------------------------------------
#
# Project created by QtCreator 2015-02-11T16:08:03
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = spinIceStatSumm2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

LIBS += -L$$PWD/../partsEngine/ -lPartsEngine
INCLUDEPATH += $$PWD/../partsEngine
DEPENDPATH += $$PWD/../partsEngine
PRE_TARGETDEPS += $$PWD/../partsEngine/libPartsEngine.a

DISTFILES += \
    README.md \
    magnetisation.nb \
    kappa.nb \
    data/statsumm_12_2200.dat \
    res/magnetisation_12_2200.png
