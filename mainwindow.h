void on_pushButton_clicked();
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <uploadmenu.h>
#include <widget_my.h>
#include <widget_bin.h>
#include <widget_mycontent.h>
#include "homepage.h"
#include "mycontent.h"
#include "recyclebin.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void beclicked();
private slots:
    void on_pushButton_clicked();
public slots:
    void mouseClicked_home();
    void mouseClicked_mycontent();
    void mouseClicked_bin();
private:
    Ui::MainWindow *ui;
    Uploadmenu * puploadmenu = nullptr;
    Widget_My * widget_my = nullptr;
    Widget_Mycontent * widget_mycontent = nullptr;
    Widget_Bin * widget_bin = nullptr;
    Homepage * homepage = nullptr;
    MyContent * mycontent = nullptr;
    RecycleBin * recyclebin = nullptr;
};
#endif // MAINWINDOW_H
