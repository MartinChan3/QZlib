#ifndef QZLIB_H
#define QZLIB_H

#include <QStringList>
#include "minizip/zip.h"

///////////////////////////////////////////////////////////////////////////////
// Copyright    :
// Name         :qzlib.h
// Introduction :Wrap zip function
//
// Author       :MartinChan
// Version      :1.0
// Date         :2017-09-13
// Explanation  :
///////////////////////////////////////////////////////////////////////////////
class QZlib
{
public:
    QZlib();
    ~QZlib();

    /*The AddDir and GenerateZip is the base functions you could use*/
    bool AddDir(QString);                                 //Add directory
    bool GenerateZip(const char*,const char* = Q_NULLPTR);//Generate Zip file
private:
    zipFile zf;
    QStringList dirs;                                     //Store the diretories
    QByteArray arr;                                       //As temp array for store file
    uLong crc;                                            //Store crc file

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
