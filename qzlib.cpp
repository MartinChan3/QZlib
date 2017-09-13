#include "qzlib.h"
#include "QDir"
#include "QDebug"

QZlib::QZlib():crc(0),zf(Q_NULLPTR)
{
    if ( !dirs.empty() )
    {
        dirs.clear();
    }
}

QZlib::~QZlib()
{

}

bool QZlib::AddDir(QString dir)
{
    QDir tmp_dir;
    tmp_dir.setPath(dir);

    if ( !tmp_dir.exists() )
    {
        return false;
    }

    dirs.append(dir);
    return true;
}

bool QZlib::GenerateZip(const char* zip_name,const char *password)
{
    if (dirs.size()<1)
    {
        return false;
    }

    zf = zipOpen(zip_name,APPEND_STATUS_CREATE);

    QDir tmp_dir;
    QStringList filter;
    filter<<"*.png"<<"*.PNG"<<"*.jpg"<<"*.JPG";//设定过滤类型

    //遍历各个文件夹
    for (int i = 0; i < dirs.size() ; i++ )
    {
        tmp_dir.setPath(dirs.at(i));
        tmp_dir.setNameFilters(filter);

        QStringList png_names;
        png_names = tmp_dir.entryList();

        for (int j = 0; j < png_names.size() ; j++ )
        {
            QString tmp_str = dirs.at(i) + "/" + png_names.at(j);

            ZipSinglePNG(tmp_str,password);
        }

    }

    zipClose(zf,"Union Tech utk file");

    return true;
}

bool QZlib::ZipSinglePNG(QString file_str, const char * password)
{
    QFile tmp_png_file(file_str);

    QString tmp_str = file_str;
    int last_but_one_back_slash_pos = tmp_str.lastIndexOf('/');
    int second_from_end_back_slash_pos = tmp_str.lastIndexOf('/',last_but_one_back_slash_pos);
    file_str = tmp_str.right(tmp_str.size() - second_from_end_back_slash_pos + 1);

    QByteArray tmp_byte_arr = file_str.toLatin1();
    const char *zip_file_path = tmp_byte_arr;

    if (!tmp_png_file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    zip_fileinfo tmp_file_info = GenerateZipInfo(GenerateZipTimeInfo());

    arr = tmp_png_file.readAll();
    int flag_open_new_flag= zipOpenNewFileInZip3(zf,
                                                 zip_file_path,
                                                 &tmp_file_info,
                                                 NULL,
                                                 0,
                                              NULL,
                                              0,
                                              "UnionTech utk",
                                              Z_DEFLATED,
                                              Z_DEFAULT_COMPRESSION,
                                              0,
                                              15,
                                              8,
                                              Z_DEFAULT_STRATEGY,
                                              password,
                                              crc32(crc,(uchar*)(arr.data()),arr.size()));
    if (flag_open_new_flag != ZIP_OK)
    {
        tmp_png_file.close();
        return false;
    }

    zipWriteInFileInZip(zf,arr.data(),arr.size());
    zipCloseFileInZip(zf);
    tmp_png_file.close();
    return true;
}

tm_zip_s QZlib::GenerateZipTimeInfo(uint year, uint mon, uint day, uint hour, uint min, uint sec)
{
    tm_zip_s tmp_zip_time_info;
    tmp_zip_time_info.tm_year = year;
    tmp_zip_time_info.tm_mon  = mon;
    tmp_zip_time_info.tm_hour = hour;
    tmp_zip_time_info.tm_mday = day;
    tmp_zip_time_info.tm_min  = min;
    tmp_zip_time_info.tm_sec  = sec;

    return tmp_zip_time_info;
}

zip_fileinfo QZlib::GenerateZipInfo(tm_zip_s tmp_data)
{
    zip_fileinfo tmp_fileinfo;
    tmp_fileinfo.tmz_date = tmp_data;
    tmp_fileinfo.dosDate  = 0;
    tmp_fileinfo.internal_fa = 0;
    tmp_fileinfo.external_fa = 0;

    return tmp_fileinfo;
}
