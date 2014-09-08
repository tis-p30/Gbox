#-------------------------------------------------
#
# Project created by QtCreator 2014-09-02T21:30:13
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gbox
TEMPLATE = app


SOURCES += main.cpp \
    scene/render/render.cpp \
    scene/scene.cpp \
    math/mth.cpp

HEADERS  += \
    scene/render/render.h \
    scene/scene.h \
    math/mth.h \
    def.h
 LIBS += -lGLU
