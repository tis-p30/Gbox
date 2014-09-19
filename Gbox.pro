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
    scene/render/prim.cpp \
    scene/units/base/triangle.cpp \
    scene/units/base/sphere.cpp \
    scene/input/input.cpp \
    scene/render/camera.cpp \
    scene/units/control/sccontrol.cpp \
    math/vec.cpp \
    math/matr.cpp \
    math/numint.cpp \
    math/mthqstr.cpp \
    math/mth.cpp

HEADERS  += \
    scene/render/render.h \
    scene/scene.h \
    math/mth.h \
    def.h \
    scene/render/prim.h \
    scene/units/units.h \
    scene/units/base/triangle.h \
    scene/units/base/sphere.h \
    scene/input/input.h \
    scene/render/camera.h \
    scene/units/control/sccontrol.h \
    math/numint.h \
    math/mthdef.h \
    math/matr.h \
    math/vec.h \
    math/mthqstr.h
 LIBS += -lGLU

QMAKE_CXXFLAGS += -Wno-unused-parameter
