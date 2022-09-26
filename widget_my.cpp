#include "widget_my.h"
#include "ui_widget_my.h"
#include "picturebox.h"
#include "setfontutil.h"
#include <QMouseEvent>
Widget_My::Widget_My(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_My)
{
    ui->setupUi(this);
    //为button设置样式
    ui->widgetmy->setStyleSheet("QWidget{background:#00FFFFFF;border-radius:15px}QWidget:hover{border:0px;background:rgb(215, 237, 255);}");
    ui->label_Home->setAttribute(Qt::WA_TranslucentBackground);
    ui->homePic->setMode(PictureBox::FIXED_SIZE);
    //设置字体
    SetFontUtil::setMyFont(ui->label_Home);

    QImage* imgHome = new QImage(":/images/my.png");

    ui->homePic->setImage(*imgHome);

}
void Widget_My::mousePressEvent(QMouseEvent *ev)
{
    mousePos = QPoint(ev->x(), ev->y());
}
void Widget_My::mouseReleaseEvent(QMouseEvent *ev)
{
    if(mousePos == QPoint(ev->x(), ev->y())){
        emit beclicked();
    }
}
Widget_My::~Widget_My()
{
    delete ui;
}
