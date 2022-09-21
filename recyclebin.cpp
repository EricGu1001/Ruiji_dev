#include "recyclebin.h"
#include "ui_recyclebin.h"
#include "setfontutil.h"
#include "picturebox.h"
RecycleBin::RecycleBin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecycleBin)
{
    ui->setupUi(this);
    SetFontUtil::setMyFont(ui->lb_createtime);
    SetFontUtil::setMyFont(ui->lb_file);
    SetFontUtil::setMyFont(ui->lb_no_content);
    SetFontUtil::setMyFont(ui->lb_operation);
    QImage *img = new QImage(":/images/no_content_in_recyclebin.png");
    ui->recyclebin_pic->setMode(PictureBox::FIXED_SIZE);
    ui->recyclebin_pic->setImage(*img);

}

RecycleBin::~RecycleBin()
{
    delete ui;
}
