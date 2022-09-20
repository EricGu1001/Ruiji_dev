#include "homepagelistitem.h"
#include "ui_homepagelistitem.h"
#include "setfontutil.h"
HomepageListItem::HomepageListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomepageListItem)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    SetFontUtil::setMyFont(ui->lb_createTime);
    SetFontUtil::setMyFont(ui->lb_duration);
    SetFontUtil::setMyFont(ui->lb_name);
    SetFontUtil::setMyFont(ui->lb_title);

}

HomepageListItem::~HomepageListItem()
{
    delete ui;
}
