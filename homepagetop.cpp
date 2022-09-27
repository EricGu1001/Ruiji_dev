#include "homepagetop.h"
#include "ui_homepagetop.h"
#include "setfontutil.h"

#include<QAction>
HomepageTop::HomepageTop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomepageTop)
{
    ui->setupUi(this);
    //搜索框实现
    QAction* pLeadingAction = new QAction(this);
    pLeadingAction->setIcon(QIcon(":/images/searchIcon.png"));
    ui->searchEdit->addAction(pLeadingAction, QLineEdit::LeadingPosition);
    ui->searchEdit->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);border-radius:15px}");

    //上传按钮
    ui->pushButton->setStyleSheet("QPushButton{background:rgb(0,154,252);border-radius:15px;color: white;}QPushButton:pressed{}QPushButton::menu-indicator{image:none;}");

    SetFontUtil::setMyFont(ui->lb_homepage);
}


void HomepageTop::on_pushButton_clicked()
{
    if(puploadmenu)
    {
        if(puploadmenu->isHidden())
        {
            puploadmenu->show();
        }
        else {
            puploadmenu->hide();
        }

    }
    else {
        puploadmenu = new Uploadmenu(this);
        puploadmenu->setGeometry(1548,80,300,100);
        puploadmenu->raise();  //提示显示层数
        puploadmenu->setMouseTracking(true);
        puploadmenu->show();
    }

}
HomepageTop::~HomepageTop()
{
    delete ui;
}
