#include "dialog.h"
#include "ui_dialog.h"
#include<QListWidget>
#include<QListWidgetItem>
#include<QDebug>
#include"getini.h"
#include<iostream>
#include<map>
using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    num = 0;

    //初始化
   init();

    p=0;

    //取消关闭
    connect(ui->remove,SIGNAL(clicked(bool)),this,SLOT(close()));
    //链接确定设置槽
    connect(ui->sure,SIGNAL(clicked(bool)),this,SLOT(readini()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init()
{

    //ini文件打开类
    GetIni getini;
    //获取AVLSetting信息
    ini_str = getini.get_ini();
    //获取当前信息
    QString new_str = getini.get_new_lang();
    //迭代器取出元素
    map<QString, QString>::iterator iter;
    int i = 0;
    //显示到语言选择框中
    for(iter = ini_str.begin(); iter != ini_str.end(); iter++)
    {
    i++;
    //qDebug()<<iter->first;
    //qDebug()<<iter->second;
    //
    QListWidgetItem *item = new QListWidgetItem;
    item->setText(iter->second);
    item->setToolTip(iter->second);
    ui->listWidget->insertItem(i,item);
    }
    //链接获取行号槽
    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),this,SLOT(ListNum(int)));

    //设置两个选择框
   // ui->listWidget->addItem(tr("选择简体中文"));
//    QListWidgetItem *item1 = new QListWidgetItem;
//    item1->setText(tr("Select English"));
//    item1->setToolTip(tr("Select English"));
//    ui->listWidget->insertItem(2,item1);
    //设置到当前语言
    QList<QString> a;
    //qDebug()<<iter->first;
    //读取当前语言文件
    a =  getini.get_pack(new_str);
    //存取当前语言
    last_str = new_str;

    //设置当前语言
    this->setWindowTitle(a[0]);
    ui->label->setText(a[1]);
   // qDebug()<<a[1];
    ui->sure->setText(a[2]);
    ui->remove->setText(a[3]);

}
//语言选择槽函数
void Dialog::ListNum(int row)
{
    //qDebug()<<row;
    num = row;
    //qDebug()<<num;
    if(p>0)
    {
        //迭代器取出元素
        map<QString, QString>::iterator iter;
        int i=0;
        for(iter = ini_str.begin(); iter != ini_str.end(); iter++)
        {
            //判断当前点击的行数
            if(num == i++)
            {
                //取出语言并设置到当前
                GetIni getini;
                QList<QString> a;
                //qDebug()<<iter->first;
                a =  getini.get_pack(iter->first);
                last_str =iter->first;
               //a.size()
    //            for(int i = 0;i<a.size();i++)
    //            {
    //                qDebug()<<a[i];
    //            }
                this->setWindowTitle(a[0]);
                ui->label->setText(a[1]);
                ui->sure->setText(a[2]);
                ui->remove->setText(a[3]);
                //this->setWindowTitle();

                //a.clear();
                //return;
            }
        }
    }
    p++;
}

void Dialog::readini()
{

    //map<QString,QString>::iterator iter;

//    for(iter = ini_str.begin();iter!=ini_str.end();iter++)
//    {
//        qDebug()<<iter
//    }
   // qDebug()<<ini_str.size();
    //最后点击确定，写入文件
    QSettings *set_last = new QSettings("AVLSetting.ini", QSettings::IniFormat);
    set_last->setValue("LANGUAGE/Language",last_str);
    delete set_last;
    close();
}











