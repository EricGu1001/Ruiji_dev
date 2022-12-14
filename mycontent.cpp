#include "mycontent.h"
#include "ui_mycontent.h"
#include "listitem.h"
#include <QFont>
#include <QFontDatabase>
#include <QListWidgetItem>
#include <QSize>
#include <QDebug>
#include "setfontutil.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QAction>

MyContent::MyContent(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyContent)
{
    ui->setupUi(this);

    SetFontUtil::setMyFont(ui->searchEdit_2);
    SetFontUtil::setMyFont(ui->pushButton_2);
    //搜索框实现
    QAction* pLeadingAction = new QAction(this);
    pLeadingAction->setIcon(QIcon(":/images/searchIcon.png"));
    ui->searchEdit_2->addAction(pLeadingAction, QLineEdit::LeadingPosition);
    ui->searchEdit_2->setStyleSheet("QLineEdit { background: rgb(255, 255, 255);border-radius:15px}");
    ui->widget_titile->setStyleSheet("QWidget{background:rgb(237, 242, 250)}");
    //上传按钮
    ui->pushButton_2->setStyleSheet("QPushButton{background:rgb(0,154,252);border-radius:15px;color: white;}QPushButton:pressed{}QPushButton::menu-indicator{image:none;}");

            //fontThis.setPointSize(9);
            //QFont* font = new QFont(":/font/SourceHanSansSC-Medium.ttf");
            //QFont font (strList.at(0));
            SetFontUtil::setMyFont(ui->lb_createTime);
            SetFontUtil::setMyFont(ui->lb_file);
            SetFontUtil::setMyFont(ui->lb_operation);
            SetFontUtil::setMyFont(ui->btn_delete);
            getAll();
        for(int i=0;i<5;i++){
            QListWidgetItem* item = new QListWidgetItem(ui->mycontentList);
            ListItem* listItem = new ListItem();
            item->setSizeHint(QSize(listItem->width(),listItem->height()));
            item->setBackground(QColor(249,251,255,1));
            item->setFlags(item->flags()&~Qt::ItemIsSelectable);
            listItem->setMeetingTitle("两分钟上手会议瑞记");
            listItem->setDuration("2分16秒");
            listItem->setCreateTime("2022年9月5日 下午7：05");
            listItem->setImage(":/img/123.jpg");
            listItem->setOperationImg(":/images/bin.png");
            //listItem->setAttribute(Qt::WA_TransparentForMouseEvents);

            //        ui->contentList->addItem(item);
            ui->mycontentList->setItemWidget(item,listItem);
            //ui->contentList->setStyleSheet("QListWidget::item{margin-top:20px;}");
            ui->mycontentList->setSpacing(20);
        }
//        connect(ui->btn_delete,&QPushButton::clicked,[=](){
//            deletedialog = new DeleteDialog();
//            deletedialog->setParent(this->parentWidget());
//            deletedialog->setGeometry(390,251,660,381);
//            deletedialog->show();
//        });
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
                }
                QJsonObject rootObj = jsonDoc.object();
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
    manager->get(QNetworkRequest(QUrl("http://121.41.94.69:8080/litters")));
}



void MyContent::on_btn_delete_clicked()
{
    int count = 0;
    int itemId;
    deletedialog = new DeleteDialog();
    for (int i = 0; i < ui->mycontentList->count(); ++i) {
       QString content;
       QListWidgetItem* pItem  = ui->mycontentList->item(i);
       QWidget * qitem = ui->mycontentList->itemWidget(pItem);
       QList<QLabel*> hiddenId =qitem->findChildren<QLabel*>();
       foreach(QLabel *idlabel, hiddenId){
           if(idlabel->objectName() == "id"){
               itemId = idlabel->text().toInt();
           }
       }
       QList<QCheckBox*> state =qitem->findChildren<QCheckBox*>();
       foreach(QCheckBox *checkbox, state){
           if(checkbox->isChecked()){
               //被选中
               count++;
               deletedialog->ids.append(itemId);
           }
       }
    }
    if(count != 0){
        deletedialog->contentChange(count);
        deletedialog->setParent(this->parentWidget());
        deletedialog->setGeometry(390,251,660,381);
        deletedialog->show();
    }
}
void MyContent::on_checkBox_stateChanged(int state)
{
    qDebug()<<state;
    QList<QCheckBox *> listCheck = this->findChildren<QCheckBox *>();
    qDebug()<< listCheck.size();
    if(state == 0){
        //取消所有勾选
        foreach (QCheckBox *pCheck, listCheck)
        {
            if(pCheck != ui->checkBox)
            {
                if(pCheck->isChecked()){
                    pCheck->setCheckState(Qt::Unchecked);
                }
            }
        }
    }
    if(state == 2){
        //全选
        foreach (QCheckBox *pCheck, listCheck)
        {
            if(pCheck != ui->checkBox)
            {
                if(!pCheck->isChecked()){
                    pCheck->setCheckState(Qt::Checked);
                }
            }
        }

    }

}


void MyContent::on_searchEdit_2_textChanged(const QString &arg1)
{
    if(arg1!=""){
    qDebug() << arg1;
    qDebug() << ui->mycontentList->count();
    //搜索框实现
    QString searchTarget = ui->searchEdit_2->text();
    for (int i = 0; i < ui->mycontentList->count(); ++i) {
       QString content;
       QListWidgetItem* pItem  = ui->mycontentList->item(i);
       QWidget * qitem = ui->mycontentList->itemWidget(pItem);
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
        for (int i = 0; i < ui->mycontentList->count(); ++i) {
            QListWidgetItem* pItem  = ui->mycontentList->item(i);
            QWidget * qitem = ui->mycontentList->itemWidget(pItem);
            qitem->show();
        }
    }
}



void MyContent::on_pushButton_2_clicked()
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
        puploadmenu->setGeometry(1428,85,300,100);
        puploadmenu->raise();  //提示显示层数
        puploadmenu->setMouseTracking(true);
        puploadmenu->setWindowModality(Qt::ApplicationModal);
        puploadmenu->show();
    }
}

