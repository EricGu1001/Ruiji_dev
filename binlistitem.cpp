#include "binlistitem.h"
#include "ui_binlistitem.h"
#include "setfontutil.h"
#include "picturebox.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <QFontDatabase>
#include <QGraphicsEffect>
BinListitem::BinListitem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BinListitem)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->setAttribute(Qt::WA_Hover, true); //开启悬停事件
    this->installEventFilter(this); //安装事件过滤器
    setAttribute(Qt::WA_StyledBackground); //设置样式表
    //外层窗口显示为透明
    setAttribute(Qt::WA_TranslucentBackground,true);

    SetFontUtil::setMyFont(ui->lb_createTime);
    SetFontUtil::setMyFont(ui->lb_duration);
    SetFontUtil::setMyFont(ui->lb_title);
    this->setMouseTracking(true);
    connect(ui->recover_pic,SIGNAL(beclicked()),this,SLOT(mouseClicked()));
    connect(this,SIGNAL(beclicked()),MainWindow::mutualUi,SLOT(itemClicked()));
    ui->id->setVisible(false);
}

BinListitem::~BinListitem()
{
    delete ui;
}
//设置会议标题
void BinListitem::setMeetingTitle(QString title){
    ui->lb_title->setText(title);
}
//设置会议时长
void BinListitem::setDuration(QString duration){
    ui->lb_duration->setText(duration);
}
//设置创建时间
void BinListitem::setCreateTime(QString createTime){
    ui->lb_createTime->setText(createTime);
}
//设置图片
void BinListitem::setImage(QString imgURL){
    QImage *img = new QImage(imgURL);
    ui->trash_pic->setImage(*img);
}
void BinListitem::setReImage(QString imgURL){
    QImage *img = new QImage(imgURL);
    ui->recover_pic->setImage(*img);
}
//设置操作图片
void BinListitem::setOperationImg(QString imgURL){
    QImage *img = new QImage(imgURL);
    ui->trash_pic->setImage(*img);
}
void BinListitem::mousePressEvent(QMouseEvent *ev)
{
    mousePos = QPoint(ev->x(), ev->y());
}
void BinListitem::mouseReleaseEvent(QMouseEvent *ev)
{
    if(mousePos == QPoint(ev->x(), ev->y())){
        emit beclicked();
    }
}

void BinListitem::mouseMoveEvent(QMouseEvent* e){

}
bool BinListitem::eventFilter(QObject * obj, QEvent * event)
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
void BinListitem::leaveEvent(QEvent *event)
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
void BinListitem::mouseClicked(){
    recover = new Recover();
    recover->setModal(Qt::ApplicationModal);
//    recover->setParent(this->parentWidget()->parentWidget()->parentWidget());
//    recover->setGeometry(390,275,670,440);
    recover->show();
}
