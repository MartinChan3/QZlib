win32: LIBS += -L$$PWD/lib/ -lzdll

INCLUDEPATH += $$PWD        \
               $$PWD/include

HEADERS     += $$PWD/qzlib.h\
    $$PWD\include/zconf.h \
    $$PWD\include/zlib.h \
    $$PWD\minizip/crypt.h \
    $$PWD\minizip/ioapi.h \
    $$PWD\minizip/iowin32.h \
    $$PWD\minizip/mztools.h \
    $$PWD\minizip/unzip.h \
    $$PWD\minizip/zip.h

SOURCES     += $$PWD/qzlib.cpp \
    $$PWD\minizip/ioapi.c \
    $$PWD\minizip/iowin32.c \
    $$PWD\minizip/mztools.c \
    $$PWD\minizip/unzip.c \
    $$PWD\minizip/zip.c \

