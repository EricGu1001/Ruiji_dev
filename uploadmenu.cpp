#include "uploadmenu.h"
#include "ui_uploadmenu.h"

Uploadmenu::Uploadmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Uploadmenu)
{
    setAttribute(Qt::WA_StyledBackground); //设置样式表
    ui->setupUi(this);
    //在任务栏上不显示图标
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint);

     //外层窗口显示为透明
    setAttribute(Qt::WA_TranslucentBackground,true);
    ui->frame->setStyleSheet("QFrame{border-radius:15px;}");


}

Uploadmenu::~Uploadmenu()
{
    delete ui;
}
