#-------------------------------------------------
#
# Project created by QtCreator 2017-09-12T14:38:45
# Project Name: QZlib
# Introduction: This lib was used to zip file (get
#               .zip archive).It warpped zlib 1.2.8
#               and Minizip 1.1 and give some simple
#               functions to use when u want to zip
#               many folders to one zip with password
# Author      : MartinChan e-mail to:bycy0801@163.com
#
#-------------------------------------------------

QT       += core gui

TARGET = QZlib
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    minizip/ioapi.c \
    minizip/iowin32.c \
    minizip/mztools.c \
    minizip/unzip.c \
    minizip/zip.c \
    qzlib.cpp

DEFINES +=TEMP_DIR
DEFINES +=_CRT_SECURE_NO_WARNINGS
DEFINES +=DEBUG

win32-msvc*:QMAKE_CXXFLAGS += /wd"4819"

CONFIG (debug,debug|release) {
DESTDIR = $$PWD/debug
} else {
DESTDIR = $$PWD/release
}

TEMP_DIR =$$PWD/temp
MOC_DIR = $$TEMP_DIR
RCC_DIR = $$TEMP_DIR
UI_DIR  = $$TEMP_DIR
OBJECTS_DIR = $$TEMP_DIR/target


win32: LIBS += -L$$PWD/lib/ -lzdll

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

HEADERS += \
    include/zconf.h \
    include/zlib.h \
    minizip/crypt.h \
    minizip/ioapi.h \
    minizip/iowin32.h \
    minizip/mztools.h \
    minizip/unzip.h \
    minizip/zip.h \
    qzlib.h
