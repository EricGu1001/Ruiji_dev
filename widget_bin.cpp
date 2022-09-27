#include "widget_bin.h"
#include "ui_widget_bin.h"
#include "picturebox.h"
#include "setfontutil.h"
#include <QMouseEvent>
Widget_Bin::Widget_Bin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Bin)
{
    ui->setupUi(this);
    ui->widget_Bin->setStyleSheet("QWidget{background:#00FFFFFF;border-radius:15px}QWidget:hover{border:0px;background:rgb(215, 237, 255);}");
    ui->label_Bin->setAttribute(Qt::WA_TranslucentBackground);
    //设置字体
    SetFontUtil::setMyFont(ui->label_Bin);
    ui->binPic->setMode(PictureBox::FIXED_SIZE);
    QImage* imgBin = new QImage(":/images/bin.png");
    ui->binPic->setImage(*imgBin);
    //图片鼠标穿透
    ui->binPic->setAttribute(Qt::WA_TransparentForMouseEvents, true);
}
void Widget_Bin::mousePressEvent(QMouseEvent *ev)
{
    mousePos = QPoint(ev->x(), ev->y());
}
void Widget_Bin::mouseReleaseEvent(QMouseEvent *ev)
{
    if(mousePos == QPoint(ev->x(), ev->y())){
        emit beclicked();
    }
}
Widget_Bin::~Widget_Bin()
{
    delete ui;
}

