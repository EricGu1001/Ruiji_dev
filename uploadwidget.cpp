#include "uploadwidget.h"
#include "ui_uploadwidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <uploadwidget.h>

UploadWidget::UploadWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UploadWidget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);
     //外层窗口显示为透明
    setAttribute(Qt::WA_TranslucentBackground,true);
    ui->frame->setStyleSheet("QFrame{border-radius:20px;background:rgb(255, 255, 255);}");
//    ui->widget_pic->setStyleSheet("QWidget{background-image: url(:/images/file_uploadbig.png);}");
    ui->widget_frame->setStyleSheet("QWidget{border:2px dotted #242424;}");


}

void UploadWidget::mousePressEvent(QMouseEvent *ev){
    if(ev->button() == Qt::LeftButton){
        qDebug() << "123";
    }
}

UploadWidget::~UploadWidget()
{
    delete ui;
}
