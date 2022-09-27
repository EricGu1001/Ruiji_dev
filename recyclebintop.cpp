#include "recyclebintop.h"
#include "ui_recyclebintop.h"
#include "setfontutil.h"
#include <QAction>
RecyclebinTop::RecyclebinTop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecyclebinTop)
{
    ui->setupUi(this);
    //搜索框实现
    QAction* pLeadingAction = new QAction(this);
    pLeadingAction->setIcon(QIcon(":/images/searchIcon.png"));
    ui->searchEdit->addAction(pLeadingAction, QLineEdit::LeadingPosition);
    ui->searchEdit->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);border-radius:15px}");
    SetFontUtil::setMyFont(ui->lb_recyclebin);
}

RecyclebinTop::~RecyclebinTop()
{
    delete ui;
}
