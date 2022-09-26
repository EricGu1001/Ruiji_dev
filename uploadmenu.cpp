#include "uploadmenu.h"
#include "ui_uploadmenu.h"
#include <QMouseEvent>
#include <QDebug>
#include <QDesktopWidget>
#include "mainwindow.h"
#include "picturebox.h"
#include <QGraphicsDropShadowEffect>

void Uploadmenu::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
     QGraphicsDropShadowEffect * no_shadow_effect = new QGraphicsDropShadowEffect();
     no_shadow_effect->setOffset(0, 0);
         //阴影颜色
//         no_shadow_effect->setColor(QColor(255,255,255, 127));
         //阴影半径
         no_shadow_effect->setBlurRadius(0);
         this->setGraphicsEffect(no_shadow_effect);
}
Uploadmenu::Uploadmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Uploadmenu)
{
    setAttribute(Qt::WA_StyledBackground); //设置样式表
    ui->setupUi(this);
//    setWindowFlags(Qt::Tool |Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint|Qt::Dialog);
//    setWindowModality(Qt::ApplicationModal);

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

void Uploadmenu::mousePressEvent(QMouseEvent *ev){
    if(ev->button() == Qt::LeftButton){
        puploadwidget = new UploadWidget();
        puploadwidget->setParent(this->parentWidget());
        puploadwidget->setWindowModality(Qt::ApplicationModal);
        puploadwidget->setMouseTracking(true);
        puploadwidget->setGeometry(515,255,890,570); //这里要调整好
        puploadwidget->raise();  //提示显示层数
        puploadwidget->show();
        this->close();
    }
}
bool Uploadmenu::eventFilter(QObject * obj, QEvent * event)
    {
        if(obj == this)
        {
            if(event->type() == QEvent::HoverEnter) //当鼠标悬停在获取雷达参数按钮上
            {
                qDebug() << ("123");
                QGraphicsDropShadowEffect * shadow = new QGraphicsDropShadowEffect();
                    //渲染的像素点
                    shadow->setBlurRadius(30);
                    //渲染的颜色
                    shadow->setColor(Qt::gray);
                    //渲染相对于组件的偏移
                    shadow->setOffset(5);
                    this->setGraphicsEffect(shadow);
                return true;
            }
        }
        return QWidget::eventFilter(obj, event);
    }

Uploadmenu::~Uploadmenu()
{
    delete ui;
}


