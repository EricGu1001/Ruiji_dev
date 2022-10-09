#include "detail.h"
#include "ui_detail.h"
#include <QAction>
#include <setfontutil.h>
#include "picturebox.h"
#include <mainwindow.h>
Detail::Detail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Detail)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
    SetFontUtil::setMyFont(ui->searchEdit);
    SetFontUtil::setMyFont(ui->lb_textrecord);
    SetFontUtil::setMyFont(ui->lb_minutes);
    SetFontUtil::setMyFont(ui->label);
    SetFontUtil::setMyFont(ui->label_2);
    SetFontUtil::setMyFont(ui->label_3);
    SetFontUtil::setMyFont(ui->label_4);
    SetFontUtil::setMyFont(ui->label_5);
    QAction* pLeadingAction = new QAction(this);
    pLeadingAction->setIcon(QIcon(":/images/searchIcon.png"));
    ui->searchEdit->addAction(pLeadingAction, QLineEdit::LeadingPosition);
    ui->searchEdit->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);border-radius:15px}");
    ui->widget_2->setMode(PictureBox::FIXED_SIZE);
    QImage *img = new QImage(":/images/back.png");
    ui->widget_2->setImage(*img);
    connect(ui->widget_2,SIGNAL(beclicked()),MainWindow::mutualUi,SLOT(backClicked()));
    PlayerTool *playertool = new PlayerTool();
    ui->horizontalLayout->addWidget(playertool);
}

Detail::~Detail()
{
    delete ui;
}
