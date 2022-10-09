#include "delete.h"
#include "ui_delete.h"
#include <QGraphicsDropShadowEffect>
#include "picturebox.h"
#include "setfontutil.h"
Delete::Delete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Delete)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground,true);
    ui->setupUi(this);
    SetFontUtil::setMyFont(ui->label);
    SetFontUtil::setMyFont(ui->label_2);
    SetFontUtil::setMyFont(ui->label_3);
    SetFontUtil::setMyFont(ui->label_4);
    SetFontUtil::setMyFont(ui->pushButton_confirm);
    ui->widget_2->setMode(PictureBox::FIXED_SIZE);
    QImage *img = new QImage(":/images/close.png");
    ui->widget_2->setImage(*img);
    connect(ui->widget_2,SIGNAL(beclicked()),this,SLOT(mouseClicked()));
    QGraphicsDropShadowEffect * shadow = new QGraphicsDropShadowEffect();
        //渲染的像素点
        shadow->setBlurRadius(30);
        //渲染的颜色
        shadow->setColor(Qt::gray);
        //渲染相对于组件的偏移
        shadow->setOffset(5);
        this->setGraphicsEffect(shadow);

}
void Delete::mouseClicked(){
    this->close();
}
Delete::~Delete()
{
    delete ui;
}

void Delete::on_pushButton_confirm_clicked()
{

}

