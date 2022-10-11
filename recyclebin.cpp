#include "recyclebin.h"
#include "ui_recyclebin.h"
#include "setfontutil.h"
#include "picturebox.h"
#include <QAction>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <binlistitem.h>
RecycleBin::RecycleBin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecycleBin)
{
    ui->setupUi(this);
    //搜索框实现
    getAll();
    QAction* pLeadingAction = new QAction(this);
    ui->recyclebin_pic->setVisible(false);
    pLeadingAction->setIcon(QIcon(":/images/searchIcon.png"));
    ui->searchEdit->addAction(pLeadingAction, QLineEdit::LeadingPosition);
    ui->searchEdit->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);border-radius:15px}");
    SetFontUtil::setMyFont(ui->searchEdit);
    SetFontUtil::setMyFont(ui->lb_createtime);
    SetFontUtil::setMyFont(ui->lb_file);
    SetFontUtil::setMyFont(ui->lb_no_content);
    SetFontUtil::setMyFont(ui->lb_operation);
    ui->lb_no_content->setVisible(false);
    ui->widget_titile->setStyleSheet("QWidget{background:rgb(237, 242, 250)}");
}

RecycleBin::~RecycleBin()
{
    delete ui;
}
void RecycleBin::noContent(){
    if(ui->contentList->count()==0){
        ui->recyclebin_pic->setVisible(true);
        QImage *img = new QImage(":/images/no_content_in_recyclebin.png");
        ui->recyclebin_pic->setMode(PictureBox::FIXED_SIZE);
        ui->recyclebin_pic->setImage(*img);
        ui->lb_no_content->setVisible(true);
    }
}
void RecycleBin::on_searchEdit_textChanged(const QString &arg1)
{
    if(arg1!=""){
    qDebug() << arg1;
    qDebug() << ui->contentList->count();
    //搜索框实现
    QString searchTarget = ui->searchEdit->text();
    for (int i = 0; i < ui->contentList->count(); ++i) {
       QString content;
       QListWidgetItem* pItem  = ui->contentList->item(i);
       QWidget * qitem = ui->contentList->itemWidget(pItem);
       if(qitem != NULL){
           QList<QLabel*> labelList = qitem->findChildren<QLabel*>(); //获取所有的Qlabel
           foreach(QLabel *label, labelList)
           {
               if(label->objectName() == "lb_title")
               {
                  content = label->text();
                  if(content.contains(searchTarget,Qt::CaseInsensitive)){
                      qDebug() << "111";
                      qitem->show();
                  }else{
                      qitem->hide();
                  }
               }
//
           }
       }
    }
}else{
        for (int i = 0; i < ui->contentList->count(); ++i) {
            QListWidgetItem* pItem  = ui->contentList->item(i);
            QWidget * qitem = ui->contentList->itemWidget(pItem);
            qitem->show();
        }
    }
}
//获取json字符串并解析
void RecycleBin::getAll()
{
    qDebug()<<"QSslSocket="<<QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "OpenSSL支持情况:" << QSslSocket::supportsSsl();
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    //manager具有异步API，当http请求完成后，会通过finished信号进行通知
    connect(manager,&QNetworkAccessManager::finished,this,
            [=](QNetworkReply *reply)
    {
        if(reply->error()!=QNetworkReply::NoError)
        {
            //处理中的错误信息
            qDebug()<<"reply error:"<<reply->errorString();
        }
        else
        {
            //请求方式
            qDebug()<<"operation:"<<reply->operation();
            //状态码
            qDebug()<<"status code:"<<reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            qDebug()<<"url:"<<reply->url();
            //qDebug()<<"raw header:"<<reply->rawHeaderList();

            //获取响应信息
            const QByteArray replyData=reply->readAll();
            qDebug()<<"read all:"<<QString(replyData).toUtf8();

            QJsonParseError parseJsonErr;

            QJsonDocument jsonDoc = QJsonDocument::fromJson(QString(replyData).toUtf8(), &parseJsonErr);
            qDebug()<<jsonDoc;
            if(parseJsonErr.error != QJsonParseError::NoError)
            {
                qDebug() << "JSON格式错误";
                return -1;
            }
            else    // JSON格式正确
            {
                QJsonArray array =jsonDoc.array();
                qDebug()<<array.count();
                for (int i = 0; i < array.count(); ++i) {
                   QJsonValue resArray = array.at(i);
                   QJsonObject res = resArray.toObject();
                   qDebug()<<res["id"].toInt();
                   QListWidgetItem* item = new QListWidgetItem(ui->contentList);
                   BinListitem* listItem = new BinListitem();
                   //        QListWidgetItem* item = new QListWidgetItem;
                   //        ListItem* listItem = new ListItem(this);

                   //qDebug()<<listItem->width()<<listItem->height();
                   item->setSizeHint(QSize(listItem->width(),listItem->height()));
                   item->setBackground(QColor(249,251,255,1));
                   item->setFlags(item->flags()&~Qt::ItemIsSelectable);
                   listItem->setMeetingTitle(res["title"].toString());
                   listItem->setDuration("2分16秒");
                   listItem->setCreateTime(res["deleteTime"].toString());
                   listItem->setImage(":/images/123.jpg");
                   listItem->setOperationImg(":/images/bin.png");
                   listItem->setReImage(":/images/recover.png");

                   //listItem->setAttribute(Qt::WA_TransparentForMouseEvents);

                   //        ui->contentList->addItem(item);
                   ui->contentList->setItemWidget(item,listItem);
                   //ui->contentList->setStyleSheet("QListWidget::item{margin-top:20px;}");
                   ui->contentList->setSpacing(20);
                }
//                QJsonObject rootObj = jsonDoc.object();
                // 转化为root对象

//                 QJsonValue rootValue = rootObj.value("data");  // 获取指定key对应的value,
//                 qDebug() << rootValue;
//                 QJsonObject arrObject = rootValue.toObject(); // 再将值转换为obj:上一级key对应的值实际为数组对象


//                 if(arrValue.isArray()) // 判断获取的QJsonValue对象是不是数组结构
//                 {
//                     QJsonArray array = arrValue.toArray();
//                     for(int i=0;i<array.size();i++)
//                     {
//                         QJsonValue recordsValue = array.at(i);
//                         QJsonObject recordsObject = recordsValue.toObject();
//                         QString id = recordsObject["id"].toString();
//                         QString createdTime = recordsObject["createdTime"].toString();
//                         qDebug() <<"id=" <<id;
//                     }
//                 }

            }
            reply->deleteLater();
        }
    });
    //发送异步get请求
    manager->get(QNetworkRequest(QUrl("http://121.41.94.69:8080/litters/1")));
}

