#include "homepage.h"
#include "ui_homepage.h"
#include "setfontutil.h"
#include "homepagelistitem.h"
Homepage::Homepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Homepage)
{
    ui->setupUi(this);
    SetFontUtil::setMyFont(ui->lb_file);
    SetFontUtil::setMyFont(ui->lb_belonging);
    SetFontUtil::setMyFont(ui->lb_operation);
    SetFontUtil::setMyFont(ui->lb_time);

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
        //listItem->setAttribute(Qt::WA_TransparentForMouseEvents);

        //        ui->contentList->addItem(item);
        ui->contentList->setItemWidget(item,listItem);
        //ui->contentList->setStyleSheet("QListWidget::item{margin-top:20px;}");
        ui->contentList->setSpacing(20);

    }
}

Homepage::~Homepage()
{
    delete ui;
}
