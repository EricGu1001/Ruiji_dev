#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QGraphicsOpacityEffect>
#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QAction>
#include <QMouseEvent>
#include <setfontutil.h>
#include "ui_widget_my.h"
#include "ui_widget_bin.h"
#include "ui_widget_mycontent.h"
enum eStackedWidgetID{eForm1 = 0,eForm2,eForm3};  // 页码编号
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置字体
    SetFontUtil::setMyFont(ui->label_6);
    SetFontUtil::setMyFont(ui->searchEdit);
    SetFontUtil::setMyFont(ui->pushButton);
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
//            setModality(false);
//            puploadmenu->setEnabled(true);
            puploadmenu->show();
        }
        else {
//            setModality(true);
            puploadmenu->hide();
        }

    }
    else {
//        setModality(false);
        puploadmenu = new Uploadmenu(this);
        puploadmenu->setGeometry(1548,80,300,100);
        puploadmenu->raise();  //提示显示层数
        puploadmenu->setMouseTracking(true);
        puploadmenu->setWindowModality(Qt::ApplicationModal);
        puploadmenu->show();
    }

}

//void MainWindow::setModality(bool flag)
//{
//    QList<QWidget *> widgets = this->findChildren<QWidget *>();
//    widgets.append(ui->widget_titile->findChildren<QWidget *>());
//    for(auto widget: widgets)
//    {
//        widget->setEnabled(flag);
//    }
//    ui->centralwidget->setEnabled(true);
//    ui->widget_titile->setEnabled(true);
//    ui->pushButton->setEnabled(true);
//}
void MainWindow::mouseClicked_home(){
    ui->stackedWidget->setCurrentIndex(eForm1);
    QImage* imgHome = new QImage(":/images/my_click .png");
    QImage* imgBin = new QImage(":/images/bin.png");
    QImage* imgMy = new QImage(":/images/file.png");
    widget_my->ui->homePic->setImage(*imgHome);
    widget_my->ui->widgetmy->setStyleSheet("QWidget{background:rgb(215, 237, 255);border:0px;;border-radius:15px}");
    widget_bin->ui->widget_Bin->setStyleSheet("QWidget{background:#00FFFFFF;border-radius:15px}QWidget:hover{border:0px;background:rgb(215, 237, 255);}");
    widget_mycontent->ui->widget_My->setStyleSheet("QWidget{background:#00FFFFFF;border-radius:15px}QWidget:hover{border:0px;background:rgb(215, 237, 255);}");
    widget_bin->ui->binPic->setImage(*imgBin);
    widget_mycontent->ui->myPic->setImage(*imgMy);
}
void MainWindow::mouseClicked_mycontent(){
    ui->stackedWidget->setCurrentIndex(eForm2);
    QImage* imgHome = new QImage(":/images/my.png");
    QImage* imgBin = new QImage(":/images/bin.png");
    QImage* imgMy = new QImage(":/images/file_click.png");
    widget_my->ui->homePic->setImage(*imgHome);
    widget_my->ui->widgetmy->setStyleSheet("QWidget{background:#00FFFFFF;border-radius:15px}QWidget:hover{border:0px;background:rgb(215, 237, 255);}");
    widget_bin->ui->widget_Bin->setStyleSheet("QWidget{background:#00FFFFFF;border-radius:15px}QWidget:hover{border:0px;background:rgb(215, 237, 255);}");
    widget_mycontent->ui->widget_My->setStyleSheet("QWidget{background:rgb(215, 237, 255);border:0px;;border-radius:15px}");
    widget_bin->ui->binPic->setImage(*imgBin);
    widget_mycontent->ui->myPic->setImage(*imgMy);
}
void MainWindow::mouseClicked_bin(){
    ui->stackedWidget->setCurrentIndex(eForm3);
    QImage* imgHome = new QImage(":/images/my.png");
    QImage* imgBin = new QImage(":/images/bin_click.png");
    QImage* imgMy = new QImage(":/images/file.png");
    widget_my->ui->homePic->setImage(*imgHome);
    widget_my->ui->widgetmy->setStyleSheet("QWidget{background:#00FFFFFF;border-radius:15px}QWidget:hover{border:0px;background:rgb(215, 237, 255);}");
    widget_bin->ui->widget_Bin->setStyleSheet("QWidget{background:rgb(215, 237, 255);border:0px;;border-radius:15px}");
    widget_mycontent->ui->widget_My->setStyleSheet("QWidget{background:#00FFFFFF;border-radius:15px}QWidget:hover{border:0px;background:rgb(215, 237, 255);}");
    widget_bin->ui->binPic->setImage(*imgBin);
    widget_mycontent->ui->myPic->setImage(*imgMy);
}

