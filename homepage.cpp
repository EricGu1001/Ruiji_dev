#include "homepage.h"
#include "ui_homepage.h"
#include "setfontutil.h"
#include "homepagelistitem.h"
#include "QAction"
#include "QDebug"
Homepage::Homepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Homepage)
{
    ui->setupUi(this);
    SetFontUtil::setMyFont(ui->searchEdit);
    SetFontUtil::setMyFont(ui->pushButton);
    SetFontUtil::setMyFont(ui->lb_file);
    SetFontUtil::setMyFont(ui->lb_belonging);
    SetFontUtil::setMyFont(ui->lb_operation);
    SetFontUtil::setMyFont(ui->lb_time);
    ui->widget_titile->setStyleSheet("QWidget{background:rgb(237, 242, 250)}");


    //搜索框实现
    QAction* pLeadingAction = new QAction(this);
    pLeadingAction->setIcon(QIcon(":/images/searchIcon.png"));
    ui->searchEdit->addAction(pLeadingAction, QLineEdit::LeadingPosition);
    ui->searchEdit->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);border-radius:15px}");

    //上传按钮
    ui->pushButton->setStyleSheet("QPushButton{background:rgb(0,154,252);border-radius:15px;color: white;}QPushButton:pressed{}QPushButton::menu-indicator{image:none;}");
    for(int i=0;i<5;i++){
        QListWidgetItem* item = new QListWidgetItem(ui->contentList);
        HomepageListItem* listItem = new HomepageListItem();
        //        QListWidgetItem* item = new QListWidgetItem;
        //        ListItem* listItem = new ListItem(this);

        //qDebug()<<listItem->width()<<listItem->height();
        item->setSizeHint(QSize(listItem->width(),listItem->height()));
        item->setBackground(QColor(249,251,255,1));
        item->setFlags(item->flags()&~Qt::ItemIsSelectable);
        listItem->setMeetingTitle("两分钟上手会议瑞记");
        listItem->setDuration("2分16秒");
        listItem->setCreateTime("2022年9月5日 下午7：05");
        listItem->setImage(":/images/123.jpg");
        listItem->setOperationImg(":/images/bin.png");
        //listItem->setAttribute(Qt::WA_TransparentForMouseEvents);

        //        ui->contentList->addItem(item);
        ui->contentList->setItemWidget(item,listItem);
        //ui->contentList->setStyleSheet("QListWidget::item{margin-top:20px;}");
        ui->contentList->setSpacing(20);
    }
}

void Homepage::on_pushButton_clicked()
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
        puploadmenu = new Uploadmenu(this->parentWidget()->parentWidget());
        puploadmenu->setGeometry(1548,85,300,100);
        puploadmenu->raise();  //提示显示层数
        puploadmenu->setMouseTracking(true);
        puploadmenu->setWindowModality(Qt::ApplicationModal);
        puploadmenu->show();
    }

}
Homepage::~Homepage()
{
    delete ui;
}

void Homepage::on_searchEdit_textChanged(const QString &arg1)
{
    qDebug() << ui->contentList->count();
}

