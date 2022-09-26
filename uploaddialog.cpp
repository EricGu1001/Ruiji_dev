#include "uploaddialog.h"
#include "ui_uploaddialog.h"
#include "picturebox.h"
UploadDialog::UploadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UploadDialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground); //设置样式表
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    ui->setupUi(this);


    this->setAttribute(Qt::WA_Hover, true); //开启悬停事件
    this->installEventFilter(this); //安装事件过滤器
    //外层窗口显示为透明
    setAttribute(Qt::WA_TranslucentBackground,true);
    ui->widget_2->setAttribute(Qt::WA_TranslucentBackground,true);
    ui->widget->setMode(PictureBox::FIXED_SIZE);
    QImage *img = new QImage(":/images/file_upload.png");
    ui->widget->setImage(*img);
    //样式
   ui->frame->setStyleSheet("QFrame{border-radius:15px;}");
   ui->label->setAttribute(Qt::WA_TranslucentBackground);
}

UploadDialog::~UploadDialog()
{
    delete ui;
}
