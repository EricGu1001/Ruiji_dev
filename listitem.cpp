#include "listitem.h"
#include "ui_listitem.h"
#include "setfontutil.h"
#include <QImage>
#include <QDebug>
#include <QMouseEvent>
#include<QFontDatabase>
#include <QGraphicsEffect>
#include <QMouseEvent>
#include <mainwindow.h>
ListItem::ListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListItem)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_Hover, true); //开启悬停事件
    this->installEventFilter(this); //安装事件过滤器
    setAttribute(Qt::WA_StyledBackground); //设置样式表
    //外层窗口显示为透明
    setAttribute(Qt::WA_TranslucentBackground,true);
    SetFontUtil::setMyFont(ui->lb_title);
    SetFontUtil::setMyFont(ui->lb_duration);
    SetFontUtil::setMyFont(ui->lb_operation);
    SetFontUtil::setMyFont(ui->create_time);
    ui->create_time->setAlignment(Qt::AlignCenter);
    this->setMouseTracking(true);
    connect(this,SIGNAL(beclicked()),MainWindow::mutualUi,SLOT(itemClicked()));
    ui->id->setVisible(false);
}

//设置会议标题
void ListItem::setMeetingTitle(QString title){
    ui->lb_title->setText(title);
}
//设置会议时长
void ListItem::setDuration(QString duration){
    ui->lb_duration->setText(duration);
}
//设置创建时间
void ListItem::setCreateTime(QString createTime){
    ui->create_time->setText(createTime);
}
//设置图片
void ListItem::setImage(QString imgURL){
    QImage *img = new QImage(imgURL);
    ui->thumbnail->setImage(*img);
}
void ListItem::mouseMoveEvent(QMouseEvent* e){

}
void ListItem::mousePressEvent(QMouseEvent *ev)
{
    mousePos = QPoint(ev->x(), ev->y());
}
void ListItem::mouseReleaseEvent(QMouseEvent *ev)
{
    if(mousePos == QPoint(ev->x(), ev->y())){
        emit beclicked();
        qDebug() << "123";
    }
}
bool ListItem::eventFilter(QObject * obj, QEvent * event)
    {
        if(obj == this)
        {
            if(event->type() == QEvent::HoverEnter) //当鼠标悬停在获取雷达参数按钮上
            {
                QGraphicsDropShadowEffect * shadow = new QGraphicsDropShadowEffect();
                    //渲染的像素点
                    shadow->setBlurRadius(45);
                    //渲染的颜色
                    shadow->setColor(Qt::gray);
                    //渲染相对于组件的偏移
                    shadow->setOffset(0);
                   this->setGraphicsEffect(shadow);
                return true;
            }
        }
        return QWidget::eventFilter(obj, event);
    }
void ListItem::leaveEvent(QEvent *event)
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
ListItem::~ListItem()
{
    delete ui;
}
