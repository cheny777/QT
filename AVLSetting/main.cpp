#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    //w.setWindowTitle(QObject::tr("选择语言"));
    w.show();

    return a.exec();
}
