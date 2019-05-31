#include "getini.h"
#include<QDebug>
#include<QList>
#include<QVariantMap>
#include<iostream>

using namespace std;

GetIni::GetIni()
{

}

map<QString,QString> GetIni::get_ini()
{
    //定义map
    map<QString,QString> ini;
    //打开配置文件
    QSettings *AVLSetting = new QSettings("AVLSetting.ini", QSettings::IniFormat);

    //读取语言个数
    QString language_nCount=AVLSetting->value("LANGUAGE_COUNT/language_nCount").toString();
    int n = language_nCount.toInt();

    //循环存入map容器
    for(int i = 0;i<n;i++)
    {
        QString str1 = QString("LANGUAGE_COUNT/language_%1").arg(i);
        QString str2 = QString("LANGUAGE_COUNT/language_%1_UI").arg(i);
        QString language = AVLSetting->value(str1).toString();
        QString UI = AVLSetting->value(str2).toString();
        // qDebug()<<language;
        //qDebug()<<UI;
        ini.insert(pair<QString,QString>(language,UI));
    }
    delete AVLSetting;
    //返回容器
    return ini;

   // qDebug() << n;

//    QString hour=AVLSetting->value(   "x/n"   ).toString();
//    qDebug() << hour;

}

void GetIni::set_ini()
{

}

QString GetIni::ConnectQStringAndNum(QString str, int i)
{
    QString str_i;
    str_i.sprintf("%d",i);
    return(str+str_i);
}
//获取语言包
QList<QString> GetIni::get_pack(QString str)
{
    //定义容器
    QList<QString> pack;
    QString avi = QString("%1_AVLSetting.ini").arg(str);
    //打开容器
    QSettings *AVLSetting = new QSettings(avi, QSettings::IniFormat);

    //取出数据并存入容器
    QString language = AVLSetting->value("AVLSETTING_DLG/IDC_STATIC1").toString();
    QString language1 = AVLSetting->value("AVLSETTING_DLG/IDD_AVLSETTING_DIALOG").toString();
    QString language2 = AVLSetting->value("AVLSETTING_DLG/AVLSETTING_DLG_IDOK").toString();
    QString language3 = AVLSetting->value("AVLSETTING_DLG/AVLSETTING_DLG_IDCANCEL").toString();
//    qDebug()<<language;
//    qDebug()<<language1;
//    qDebug()<<language2;
//    qDebug()<<language3;
    pack.push_back(language);
    pack.push_back(language1);
    pack.push_back(language2);
    pack.push_back(language3);

    delete AVLSetting;
    return pack;



}

//获取当前语言
QString GetIni::get_new_lang()
{
    //取出当前语言并返回
    QSettings *AVLSetting = new QSettings("AVLSetting.ini", QSettings::IniFormat);
    QString language_nCount=AVLSetting->value("LANGUAGE/Language").toString();
    delete AVLSetting;
    return language_nCount;

}
