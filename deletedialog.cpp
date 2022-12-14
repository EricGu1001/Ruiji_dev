#include "deletedialog.h"
#include "ui_deletedialog.h"
#include "setfontutil.h"
#include <QImage>
#include "picturebox.h"
#include <QFontDatabase>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QMouseEvent>

DeleteDialog::DeleteDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->delete_content->setAlignment(Qt::AlignCenter);
    ui->delete_tip->setAlignment(Qt::AlignCenter);
    ui->delete_title->setAlignment(Qt::AlignCenter);
    QGraphicsDropShadowEffect * shadow = new QGraphicsDropShadowEffect();
        //渲染的像素点
        shadow->setBlurRadius(30);
        //渲染的颜色
        shadow->setColor(Qt::gray);
        //渲染相对于组件的偏移
        shadow->setOffset(5);
        this->setGraphicsEffect(shadow);
        connect(ui->btn_delete,SIGNAL(beclicked()),this,SLOT(mouseClicked()));
    ui->line->setStyleSheet("QFrame{background-color:rgb(206, 220, 245)}");
    ui->delete_title->setAlignment(Qt::AlignCenter);

    QImage *img = new QImage(":/images/close.png");
    ui->delete_content->setAlignment(Qt::AlignCenter);
    ui->delete_tip->setAlignment(Qt::AlignCenter);
    ui->btn_delete->setMode(PictureBox::FIXED_SIZE);
    ui->btn_delete->setImage(*img);
    SetFontUtil::setMyFont(ui->delete_confirm);
    SetFontUtil::setMyFont(ui->delete_content);
    SetFontUtil::setMyFont(ui->delete_tip);
    SetFontUtil::setMyFont(ui->delete_title);
}
void DeleteDialog::mouseClicked(){
    this->close();
}
void DeleteDialog::contentChange(int count){
    delCnt = count;
    QString str = QString::number(count);
    ui->delete_content->setText("删除"+str+"项内容");
}
DeleteDialog::~DeleteDialog()
{
    delete ui;
}

void DeleteDialog::on_delete_confirm_clicked()
{

}

