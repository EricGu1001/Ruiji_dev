#include "widget_mycontent.h"
#include "ui_widget_mycontent.h"
#include "picturebox.h"
#include <QMouseEvent>
Widget_Mycontent::Widget_Mycontent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Mycontent)
{
    ui->setupUi(this);
    ui->widget_My->setStyleSheet("QWidget{background:#00FFFFFF;border-radius:15px}QWidget:hover{border:0px;background:rgb(215, 237, 255);}");
    ui->label_My->setAttribute(Qt::WA_TranslucentBackground);

    ui->myPic->setMode(PictureBox::FIXED_SIZE);
    QImage* imgMy = new QImage(":/images/file.png");
    ui->myPic->setImage(*imgMy);

}
void Widget_Mycontent::mousePressEvent(QMouseEvent *ev)
{
    mousePos = QPoint(ev->x(), ev->y());
}
void Widget_Mycontent::mouseReleaseEvent(QMouseEvent *ev)
{
    if(mousePos == QPoint(ev->x(), ev->y())){
        emit beclicked();
    }
}
Widget_Mycontent::~Widget_Mycontent()
{
    delete ui;
}
