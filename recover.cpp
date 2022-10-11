#include "recover.h"
#include "ui_recover.h"
#include "setfontutil.h"
#include "QGraphicsEffect"
#include <QMouseEvent>
Recover::Recover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recover)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground,true);
    QGraphicsDropShadowEffect * shadow = new QGraphicsDropShadowEffect();
        //渲染的像素点
        shadow->setBlurRadius(30);
        //渲染的颜色
        shadow->setColor(Qt::gray);
        //渲染相对于组件的偏移
        shadow->setOffset(5);
       ui->widget->setGraphicsEffect(shadow);
    setWindowFlags(Qt::FramelessWindowHint);
    QImage *img = new QImage(":/images/close.png");
    ui->recover_content->setAlignment(Qt::AlignCenter);
    ui->recover_tip->setAlignment(Qt::AlignCenter);
    ui->btn_recover->setMode(PictureBox::FIXED_SIZE);
    ui->btn_recover->setImage(*img);
    SetFontUtil::setMyFont(ui->recover_confirm);
    SetFontUtil::setMyFont(ui->recover_content);
    SetFontUtil::setMyFont(ui->recover_tip);
    SetFontUtil::setMyFont(ui->recover_title);
    connect(ui->btn_recover,SIGNAL(beclicked()),this,SLOT(mouseClicked()));
}
void Recover::mouseClicked(){
    this->close();
}
Recover::~Recover()
{
    delete ui;
}
void Recover::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);

    QPoint y = event->globalPos(); // 鼠标相对于桌面左上角位置
    QPoint x = y - this->z;

    this->move(x);
}

void Recover::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

    QPoint x = this->geometry().topLeft(); // 窗口左上角相对于桌面左上角位置
    QPoint y = event->globalPos(); // 鼠标相对于桌面左上角位置
    this->z = y - x; // 这是个定值

}

void Recover::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);

    this->z = QPoint();
}
