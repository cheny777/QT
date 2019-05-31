#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<map>

using namespace std;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    //void keyPressEvent(QKeyEvent *);
private:
    Ui::Dialog *ui;
    //存储行号
    int num;
    //初始化函数
    void init();
    //存取配置文件内容
    map<QString,QString> ini_str;

    //flag
    int p;
    //存取最后的语言
    QString last_str;

private slots:
    //获取行号槽函数
    void ListNum(int row);
    //处理语言选择事件槽
    void readini();



};

#endif // DIALOG_H
