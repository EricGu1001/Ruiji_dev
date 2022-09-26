#include "uploadfileutil.h"
#include <QString>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFileDialog>
#include <QFileInfo>
#include <QHttpPart>
#include <QFile>
#include <QEventLoop>
#include <QDebug>
UploadFileUtil::UploadFileUtil()
{

}
int UploadFileUtil::UploadFile(QString filePath){
    QFileInfo info(filePath);

    QString fileName=info.fileName();

    //设置multiPart
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QHttpPart filePart;
    QString header=QString("form-data; name=\"file\";filename=\"%1\"").arg(fileName);
    //filePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/png"));
    filePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(header));
    QFile *file = new QFile(filePath);
    file->open(QIODevice::ReadOnly);
    filePart.setBodyDevice(file);
    file->setParent(multiPart);
    // we cannot delete the file now, so delete it with the multiPart
    multiPart->append(filePart);

    QNetworkRequest request;

    //***这里需要修改为自定义URL***
    request.setUrl(QUrl("YOUR URL"));

    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkReply *reply = manager->post(request, multiPart);
    multiPart->setParent(reply);
    QEventLoop loop;
    QAbstractSocket::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    QByteArray bytes=reply->readAll();
    //qDebug()<<bytes;
    if(bytes.length()==0){
        qDebug()<<reply->error();
        return -1;
    }else return 0;

}
