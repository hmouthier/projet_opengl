#-------------------------------------------------
#
# Project created by QtCreator 2014-10-08T11:07:06
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT += opengl


LIBS += -lglut
LIBS += -lGL -lGLU -lglut
INCLUDEPATH += -L /usr/lib/


INCLUDEPATH += -L/usr/lib/
INCLUDEPATH += /usr/local/include/opencv2
LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann



TARGET = bientotFini
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    camera.cpp \
    bati.cpp \
    initgl.cpp \
    traitementimage.cpp \
    afficheortho.cpp \
    vegetation.cpp \
    classification.cpp


HEADERS += \
    camera.h \
    bati.h \
    initgl.h \
    traitementimage.h \
    afficheortho.h \
    vegetation.h \
    classification.h

FORMS +=
