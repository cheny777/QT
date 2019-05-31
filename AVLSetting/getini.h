#ifndef GETINI_H
#define GETINI_H
#include<QSettings>
#include<QString>
#include<iostream>
/*
    读写ini文件类
*/
using namespace std;
class GetIni
{
public:
    GetIni();
    //获取最初配置文件
    map<QString, QString> get_ini();
    //设置写入配置文件
    void set_ini();
    QString ConnectQStringAndNum(QString str, int i);
    //获取语言包
    QList<QString> get_pack(QString str);
    //获取当前语言
    QString get_new_lang();

};

#endif // GETINI_H
