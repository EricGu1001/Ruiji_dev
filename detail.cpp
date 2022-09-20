#include "detail.h"
#include "ui_detail.h"
#include <QAction>
Detail::Detail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Detail)
{
    ui->setupUi(this);
    QAction* pLeadingAction = new QAction(this);
    pLeadingAction->setIcon(QIcon(":/images/searchIcon.png"));
    ui->searchEdit->addAction(pLeadingAction, QLineEdit::LeadingPosition);
    ui->searchEdit->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);border-radius:15px}");

}

void Detail::PushWidget(QWidget *widget){
    ui->horizontalLayout->addWidget(widget);
}
Detail::~Detail()
{
    delete ui;
}
