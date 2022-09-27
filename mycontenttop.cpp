#include "mycontenttop.h"
#include "ui_mycontenttop.h"
#include "setfontutil.h"
#include <QAction>
MyContentTop::MyContentTop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyContentTop)
{
    ui->setupUi(this);
    //搜索框实现
    QAction* pLeadingAction = new QAction(this);
    pLeadingAction->setIcon(QIcon(":/images/searchIcon.png"));
    ui->searchEdit->addAction(pLeadingAction, QLineEdit::LeadingPosition);
    ui->searchEdit->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);border-radius:15px}");

    //上传按钮
    ui->pushButton->setStyleSheet("QPushButton{background:rgb(0,154,252);border-radius:15px;color: white;}QPushButton:pressed{}QPushButton::menu-indicator{image:none;}");

    //设置字体
    SetFontUtil::setMyFont(ui->lb_mycontent);
}

MyContentTop::~MyContentTop()
{
    delete ui;
}
