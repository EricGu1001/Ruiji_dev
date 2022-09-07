#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile res_file("C:\\Users\\msi-user\\Desktop\\Project_1\\ruiji\\Style.qss");
    if(res_file.open(QIODevice::ReadOnly)){
        a.setStyleSheet(res_file.readAll());
    }
    res_file.close();

    MainWindow w;
    w.show();
    return a.exec();
}
