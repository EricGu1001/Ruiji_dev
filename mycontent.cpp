#include "mycontent.h"
#include "ui_mycontent.h"
#include "listitem.h"
#include <QFont>
#include<QFontDatabase>
#include <QListWidgetItem>
#include <QSize>
#include <QDebug>
#include "setfontutil.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
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
            SetFontUtil::setMyFont(ui->btn_delete);
            getAll();
        for(int i=0;i<5;i++){
            QListWidgetItem* item = new QListWidgetItem(ui->contentList);
            ListItem* listItem = new ListItem();
            item->setSizeHint(QSize(listItem->width(),listItem->height()));
            item->setBackground(QColor(249,251,255,1));
            item->setFlags(item->flags()&~Qt::ItemIsSelectable);
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
            deletedialog = new DeleteDialog();
            deletedialog->setParent(this->parentWidget());
            deletedialog->setGeometry(390,251,660,381);
            deletedialog->show();
        });

    }



MyContent::~MyContent()
{
    delete ui;
}

//获取json字符串并解析
void MyContent::getAll()
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
            if(parseJsonErr.error != QJsonParseError::NoError)
            {
                qDebug() << "JSON格式错误";
                return -1;
            }
            else    // JSON格式正确
            {
                QJsonObject rootObj = jsonDoc.object();  // 转化为root对象

                 QJsonValue rootValue = rootObj.value("data");  // 获取指定key对应的value,
                 QJsonObject arrObject = rootValue.toObject(); // 再将值转换为obj:上一级key对应的值实际为数组对象

                 QJsonValue arrValue = arrObject.value("records");
                 if(arrValue.isArray()) // 判断获取的QJsonValue对象是不是数组结构
                 {
                     QJsonArray array = arrValue.toArray();
                     for(int i=0;i<array.size();i++)
                     {
                         QJsonValue recordsValue = array.at(i);
                         QJsonObject recordsObject = recordsValue.toObject();
                         QString id = recordsObject["id"].toString();
                         QString createdTime = recordsObject["createdTime"].toString();
                         qDebug() <<"id=" <<id;
                     }
                 }

            }
            reply->deleteLater();
        }
    });
    //发送异步get请求
    manager->get(QNetworkRequest(QUrl("http://localhost:8080/note/my")));
}



void MyContent::on_btn_delete_clicked()
{

}


void MyContent::on_checkBox_stateChanged(int state)
{
    qDebug()<<state;
    if(state == 0){
        //取消所有勾选

    }
    if(state == 2){
        //全选

    }

}

