#include "deletetest.h"
#include "ui_deletetest.h"
#include "picturebox.h"
#include <QGraphicsDropShadowEffect>
DeleteTest::DeleteTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteTest)
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground,true);
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
        ui->widget->setGraphicsEffect(shadow);
}
void DeleteTest::mouseClicked(){
    this->close();
}
DeleteTest::~DeleteTest()
{
    delete ui;
}
