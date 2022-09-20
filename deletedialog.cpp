#include "deletedialog.h"
#include "ui_deletedialog.h"
#include "setfontutil.h"
#include <QImage>
#include "picturebox.h"
#include<QFontDatabase>
DeleteDialog::DeleteDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->delete_content->setAlignment(Qt::AlignCenter);
    ui->delete_tip->setAlignment(Qt::AlignCenter);
    ui->delete_title->setAlignment(Qt::AlignCenter);

    ui->line->setStyleSheet("QFrame{background-color:rgb(206, 220, 245)}");

    this->setStyleSheet("QWidget{background-color:rgb(255, 255, 255)}");
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

DeleteDialog::~DeleteDialog()
{
    delete ui;
}
