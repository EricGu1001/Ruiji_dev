#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "picturebox.h"
#include "uploadmenu.h"
#include <QImage>
#include <QGraphicsOpacityEffect>
#include <QWidget>
#include <QFile>
#include <QAction>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    setAttribute(Qt::WA_StyledBackground); //设置样式表

    //为button设置样式
    ui->widget_My->setStyleSheet("QWidget{background:#00FFFFFF;border-radius:15px}QWidget:hover{border:0px;background:rgb(215, 237, 255);}");
    ui->widget_Home->setStyleSheet("QWidget{background:#00FFFFFF;border-radius:15px}QWidget:hover{border:0px;background:rgb(215, 237, 255);}");
    ui->widget_Bin->setStyleSheet("QWidget{background:#00FFFFFF;border-radius:15px}QWidget:hover{border:0px;background:rgb(215, 237, 255);}");
    ui->label_My->setStyleSheet("Qlabel:hover{border:0px;background:rgb(215, 237, 255);}");
    ui->label_Home->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_My->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_Bin->setAttribute(Qt::WA_TranslucentBackground);
    //设置左边建筑背景图片
    ui->leftWidget->setStyleSheet("QWidget{background-image: url(:/images/background_left.png)}");
    ui->widget_2->setStyleSheet("QWidget{background-image: url(:/images/background_right .png);}");

    //设置背景颜色
    ui->widget_back->setStyleSheet("QWidget{background:rgb(237, 245, 255)}");
    ui->widget_titile->setStyleSheet("QWidget{background:rgb(237, 242, 250)}");
    ui->widget_tableTitle->setStyleSheet("QWidget{background:rgb(249, 251, 255)}");
    ui->widget_table->setStyleSheet("QWidget{background:rgb(249, 251, 255)}");

    //设置标签图片
    ui->homePic->setMode(PictureBox::FIXED_SIZE);
    ui->myPic->setMode(PictureBox::FIXED_SIZE);
    ui->binPic->setMode(PictureBox::FIXED_SIZE);

    QImage* imgHome = new QImage(":/images/my.png");
    QImage* imgMy = new QImage(":/images/file.png");
    QImage* imgBin = new QImage(":/images/bin.png");

    ui->homePic->setImage(*imgHome);
    ui->myPic->setImage(*imgMy);
    ui->binPic->setImage(*imgBin);

    //搜索框实现
    QAction* pLeadingAction = new QAction(this);
    pLeadingAction->setIcon(QIcon(":/images/searchIcon.png"));
    ui->searchEdit->addAction(pLeadingAction, QLineEdit::LeadingPosition);
    ui->searchEdit->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);border-radius:15px}");

    //上传按钮
    ui->pushButton->setStyleSheet("QPushButton{background:rgb(0,154,252);border-radius:15px;color: white;}QPushButton:pressed{}QPushButton::menu-indicator{image:none;}");
//    connect(ui->pushButton,&QPushButton::clicked,[=](){
//        Uploadmenu *uploadmenu = new Uploadmenu;
//        uploadmenu->show();


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
        puploadmenu->setMouseTracking(true);
        puploadmenu->setGeometry(1548,112,300,100); //这里要调整好
        puploadmenu->raise();  //提示显示层数
        puploadmenu->show();
    }

}

