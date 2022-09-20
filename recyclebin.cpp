#include "recyclebin.h"
#include "ui_recyclebin.h"
#include "setfontutil.h"
RecycleBin::RecycleBin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecycleBin)
{
    ui->setupUi(this);
    SetFontUtil::setMyFont(ui->lb_createtime);
    SetFontUtil::setMyFont(ui->lb_file);
    SetFontUtil::setMyFont(ui->lb_no_content);
    SetFontUtil::setMyFont(ui->lb_operation);

}

RecycleBin::~RecycleBin()
{
    delete ui;
}
