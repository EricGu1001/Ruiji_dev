#include "uploadwidget.h"
#include "ui_uploadwidget.h"
UploadWidget::UploadWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UploadWidget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);
     //外层窗口显示为透明
    setAttribute(Qt::WA_TranslucentBackground,true);
    ui->frame->setStyleSheet("QFrame{border-radius:20px;background}");
    ui->widget_pic->setStyleSheet("QWidget{background-image: url(:/images/file_uploadbig.png);background:rgb(255, 255, 255);}");

}

UploadWidget::~UploadWidget()
{
    delete ui;
}
