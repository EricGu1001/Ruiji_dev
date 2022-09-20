#include "homepage.h"
#include "ui_homepage.h"
#include "setfontutil.h"
Homepage::Homepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Homepage)
{
    ui->setupUi(this);
    SetFontUtil::setMyFont(ui->lb_file);
    SetFontUtil::setMyFont(ui->lb_belonging);
    SetFontUtil::setMyFont(ui->lb_operation);
    SetFontUtil::setMyFont(ui->lb_time);

}

Homepage::~Homepage()
{
    delete ui;
}
