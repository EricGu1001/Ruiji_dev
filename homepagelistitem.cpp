#include "homepagelistitem.h"
#include "ui_homepagelistitem.h"
#include "setfontutil.h"
#include <QMouseEvent>
#include<QFontDatabase>
#include <QDebug>
#include <QGraphicsEffect>
HomepageListItem::HomepageListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomepageListItem)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_Hover, true); //开启悬停事件
    this->installEventFilter(this); //安装事件过滤器
    setAttribute(Qt::WA_StyledBackground); //设置样式表
    //外层窗口显示为透明
    setAttribute(Qt::WA_TranslucentBackground,true);

    SetFontUtil::setMyFont(ui->lb_createTime);
    SetFontUtil::setMyFont(ui->lb_duration);
    SetFontUtil::setMyFont(ui->lb_name);
    SetFontUtil::setMyFont(ui->lb_title);
    this->setMouseTracking(true);
    connect(ui->trash_pic,SIGNAL(beclicked()),this,SLOT(mouseClicked()));

}


//设置会议标题
void HomepageListItem::setMeetingTitle(QString title){
    ui->lb_title->setText(title);
}
//设置会议时长
void HomepageListItem::setDuration(QString duration){
    ui->lb_duration->setText(duration);
}
//设置创建时间
void HomepageListItem::setCreateTime(QString createTime){
    ui->lb_createTime->setText(createTime);
}
//设置图片
void HomepageListItem::setImage(QString imgURL){
    QImage *img = new QImage(imgURL);
    ui->thumbnail->setImage(*img);
}
//设置操作图片
void HomepageListItem::setOperationImg(QString imgURL){
    QImage *img = new QImage(imgURL);
    ui->trash_pic->setImage(*img);
}


void HomepageListItem::mouseMoveEvent(QMouseEvent* e){

}
bool HomepageListItem::eventFilter(QObject * obj, QEvent * event)
    {
        if(obj == this)
        {
            if(event->type() == QEvent::HoverEnter) //当鼠标悬停在获取雷达参数按钮上
            {
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
void HomepageListItem::leaveEvent(QEvent *event)
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
HomepageListItem::~HomepageListItem()
{
    delete ui;
}
void HomepageListItem::mouseClicked(){
    pdelete = new Delete();
    pdelete->setParent(this->parentWidget()->parentWidget()->parentWidget());
    pdelete->setGeometry(390,275,661,433);
    pdelete->show();
}
