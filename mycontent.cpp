#include "mycontent.h"
#include "ui_mycontent.h"
#include "listitem.h"
#include "deletedialog.h"
#include <QFont>
#include<QFontDatabase>
#include <QListWidgetItem>
#include <QSize>
#include <QDebug>
#include "setfontutil.h"
MyContent::MyContent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyContent)
{
    ui->setupUi(this);


            //fontThis.setPointSize(9);
            //QFont* font = new QFont(":/font/SourceHanSansSC-Medium.ttf");
            //QFont font (strList.at(0));
            SetFontUtil::setMyFont(ui->lb_createTime);
            SetFontUtil::setMyFont(ui->lb_file);
            SetFontUtil::setMyFont(ui->lb_operation);

            DeleteDialog *deleteDialog = new DeleteDialog;

        for(int i=0;i<5;i++){
            QListWidgetItem* item = new QListWidgetItem(ui->contentList);
            ListItem* listItem = new ListItem();
            //        QListWidgetItem* item = new QListWidgetItem;
            //        ListItem* listItem = new ListItem(this);

            //qDebug()<<listItem->width()<<listItem->height();
            item->setSizeHint(QSize(listItem->width(),listItem->height()));
            item->setBackground(QColor(249,251,255,1));
            listItem->setMeetingTitle("两分钟上手会议瑞记");
            listItem->setDuration("2分16秒");
            listItem->setCreateTime("2022年9月5日 下午7：05");
            listItem->setImage(":/img/123.jpg");
            //listItem->setAttribute(Qt::WA_TransparentForMouseEvents);

            //        ui->contentList->addItem(item);
            ui->contentList->setItemWidget(item,listItem);
            //ui->contentList->setStyleSheet("QListWidget::item{margin-top:20px;}");
            ui->contentList->setSpacing(20);

        }
        connect(ui->btn_delete,&QPushButton::clicked,[=](){
            qDebug()<<"123";
            deleteDialog->show();
        });

    }



MyContent::~MyContent()
{
    delete ui;
}




void MyContent::on_btn_delete_clicked()
{

}

