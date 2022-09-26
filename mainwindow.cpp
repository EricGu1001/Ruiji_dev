#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QGraphicsOpacityEffect>
#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QAction>
#include <QMouseEvent>

enum eStackedWidgetID{eForm1 = 0,eForm2,eForm3};  // 页码编号
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置左边建筑背景图片
    ui->leftWidget->setStyleSheet("QWidget{background-image: url(:/images/background_left.png)}");
    ui->widget_2->setStyleSheet("QWidget{background-image: url(:/images/background_right .png);}");

    //设置背景颜色
    ui->widget_back->setStyleSheet("QWidget{background:rgb(237, 245, 255)}");
    ui->widget_titile->setStyleSheet("QWidget{background:rgb(237, 242, 250)}");


    //搜索框实现
    QAction* pLeadingAction = new QAction(this);
    pLeadingAction->setIcon(QIcon(":/images/searchIcon.png"));
    ui->searchEdit->addAction(pLeadingAction, QLineEdit::LeadingPosition);
    ui->searchEdit->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);border-radius:15px}");

    //上传按钮
    ui->pushButton->setStyleSheet("QPushButton{background:rgb(0,154,252);border-radius:15px;color: white;}QPushButton:pressed{}QPushButton::menu-indicator{image:none;}");


    widget_my = new Widget_My(this);
    widget_my->setGeometry(134,112,332,64);

    widget_mycontent = new Widget_Mycontent(this);
    widget_mycontent->setGeometry(134,192,332,64);

    widget_bin = new Widget_Bin(this);
    widget_bin->setGeometry(134,272,332,64);

    //页面切换
    homepage = new Homepage(this);
    mycontent = new MyContent(this);
    recyclebin = new RecycleBin(this);

    ui->stackedWidget->insertWidget(eForm1,homepage);
    ui->stackedWidget->insertWidget(eForm2,mycontent);
    ui->stackedWidget->insertWidget(eForm3,recyclebin);

    ui->stackedWidget->setCurrentIndex(eForm1);
    connect(widget_my,SIGNAL(beclicked()),this,SLOT(mouseClicked_home()));
    connect(widget_mycontent,SIGNAL(beclicked()),this,SLOT(mouseClicked_mycontent()));
    connect(widget_bin,SIGNAL(beclicked()),this,SLOT(mouseClicked_bin()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(puploadmenu)
    {
        if(puploadmenu->isHidden())
        {
            puploadmenu->show();
        }
        else {
            puploadmenu->hide();
        }

    }
    else {
        puploadmenu = new Uploadmenu(this);
        puploadmenu->setGeometry(1548,80,300,100);
        puploadmenu->raise();  //提示显示层数
        puploadmenu->setMouseTracking(true);
        puploadmenu->setWindowModality(Qt::ApplicationModal);
        puploadmenu->show();
    }

}
void MainWindow::mouseClicked_home(){
    ui->stackedWidget->setCurrentIndex(eForm1);
}
void MainWindow::mouseClicked_mycontent(){
    ui->stackedWidget->setCurrentIndex(eForm2);
}
void MainWindow::mouseClicked_bin(){
    ui->stackedWidget->setCurrentIndex(eForm3);
}

