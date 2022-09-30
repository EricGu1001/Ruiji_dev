#include "recyclebin.h"
#include "ui_recyclebin.h"
#include "setfontutil.h"
#include "picturebox.h"
#include <QAction>
RecycleBin::RecycleBin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecycleBin)
{
    ui->setupUi(this);
    //搜索框实现

    QAction* pLeadingAction = new QAction(this);
    pLeadingAction->setIcon(QIcon(":/images/searchIcon.png"));
    ui->searchEdit->addAction(pLeadingAction, QLineEdit::LeadingPosition);
    ui->searchEdit->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);border-radius:15px}");
    SetFontUtil::setMyFont(ui->searchEdit);
    SetFontUtil::setMyFont(ui->lb_createtime);
    SetFontUtil::setMyFont(ui->lb_file);
    SetFontUtil::setMyFont(ui->lb_no_content);
    SetFontUtil::setMyFont(ui->lb_operation);
    QImage *img = new QImage(":/images/no_content_in_recyclebin.png");
    ui->recyclebin_pic->setMode(PictureBox::FIXED_SIZE);
    ui->recyclebin_pic->setImage(*img);
    ui->widget_titile->setStyleSheet("QWidget{background:rgb(237, 242, 250)}");
}

RecycleBin::~RecycleBin()
{
    delete ui;
}
