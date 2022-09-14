#include "delete.h"
#include "ui_delete.h"
#include <QGraphicsDropShadowEffect>
Delete::Delete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
    //设置阴影
    setAttribute(Qt::WA_TranslucentBackground,true);
    ui->widget->setAttribute(Qt::WA_TranslucentBackground,true);
    QGraphicsDropShadowEffect * shadow = new QGraphicsDropShadowEffect();
    //渲染的像素点
    shadow->setBlurRadius(30);
    //渲染的颜色
    shadow->setColor(Qt::gray);
    //渲染相对于组件的偏移
    shadow->setOffset(0);
    this->setGraphicsEffect(shadow);

}

Delete::~Delete()
{
    delete ui;
}
