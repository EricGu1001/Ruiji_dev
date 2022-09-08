#include "uploadmenu.h"
#include "ui_uploadmenu.h"
#include <QMouseEvent>
#include <QDebug>
#include <QDesktopWidget>
#include "mainwindow.h"
#include "picturebox.h"

Uploadmenu::Uploadmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Uploadmenu)
{
    setAttribute(Qt::WA_StyledBackground); //设置样式表

    ui->setupUi(this);
    //在任务栏上不显示图标
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);
     //外层窗口显示为透明
    setAttribute(Qt::WA_TranslucentBackground,true);
    ui->widget->setMode(PictureBox::FIXED_SIZE);
    QImage *img = new QImage(":/images/file_upload.png");
    ui->widget->setImage(*img);
   ui->frame->setStyleSheet("QFrame{border-radius:15px;}QFrame:hover{border:0px;background:rgb(215, 237, 255);}");

    ui->label->setAttribute(Qt::WA_TranslucentBackground);

}






void Uploadmenu::mousePressEvent(QMouseEvent *ev){
    if(ev->button() == Qt::LeftButton){
        UploadWidget* puploadwidget = new UploadWidget(this);
        puploadwidget->setMouseTracking(true);
 //     puploadwidget->setGeometry(1548,112,300,100); //这里要调整好
        puploadwidget->raise();  //提示显示层数
        puploadwidget->show();
        this->close();
    }
}


Uploadmenu::~Uploadmenu()
{
    delete ui;
}


