#ifndef QZLIB_H
#define QZLIB_H

#include <QStringList>
#include "minizip/zip.h"


class QZlib
{
public:
    QZlib();
    ~QZlib();

    bool AddDir(QString);
    bool GenerateZip(const char*,const char* = Q_NULLPTR);
private:
    zipFile zf;
    QStringList dirs;
    QByteArray arr;
    uLong crc;

    bool ZipSinglePNG(QString,const char*);
    tm_zip_s GenerateZipTimeInfo(uint year = 1991,
                                 uint mon  = 10,
                                 uint day  = 1,
                                 uint hour = 16,
                                 uint min  = 0,
                                 uint sec  = 0);
    zip_fileinfo GenerateZipInfo(tm_zip_s);
};

#endif // QZLIB_H
