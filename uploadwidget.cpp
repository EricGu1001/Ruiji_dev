#include "uploadwidget.h"
#include "ui_uploadwidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <uploadwidget.h>
#include <QFileDialog>
#include <QMimeData>
#include "picturebox.h"

UploadWidget::UploadWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UploadWidget)
{
    ui->setupUi(this);
   setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint|Qt::Tool|Qt::WindowStaysOnTopHint|Qt::Dialog);
     //外层窗口显示为透明
    setAttribute(Qt::WA_TranslucentBackground,true);
    ui->frame->setStyleSheet("QFrame{border-radius:20px;background:rgb(255, 255, 255);}");
    ui->widget_frame->setStyleSheet("QWidget{border:2px dotted #242424;}");
    //关闭按钮
    ui->widget->setMode(PictureBox::FIXED_SIZE);
    QImage *img = new QImage(":/images/close.png");
    ui->widget->setImage(*img);

    connect(ui->widget,SIGNAL(beclicked()),this,SLOT(mouseClicked()));

}

UploadWidget::~UploadWidget()
{
    delete ui;
}
void UploadWidget::mouseClicked(){
    this->close();
}

//文件上传对话框
void UploadWidget::on_pushButton_upload_clicked()
{
    QStringList filename = QFileDialog::getOpenFileNames(this,"选择视频上传","","files(*.mp4);;");
    qDebug() << filename;
}

void UploadWidget::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();

    //可以指定过滤类型，一般用于自定义类型
//    if (event->mimeData()->hasFormat("text/uri-list")){
//        event->acceptProposedAction();
//    }
}

void UploadWidget::dropEvent(QDropEvent *event)
{
    //QList<QUrl> urls = event->mimeData()->urls();                  // 结果   多个文件
    //QString url = event->mimeData()->urls().first().toString();    // 结果   "file:///C:/User/test/Desktop/a.png"
    //QString url = event->mimeData()->urls().at(0).toLocalFile();   // 结果   "C:/User/test/Desktop/a.png"
    QString url = event->mimeData()->urls().first().toLocalFile();   // 结果   "C:/User/test/Desktop/a.png"
    if (url.isEmpty()){
        return;
    }
    //
    //具体将拿到的数据进行处理
//    QImage img;
//    img.load(url);
//    ui->labelImg->setPixmap(QPixmap::fromImage(img));
}

void UploadWidget::setupView()
{
    ui->widget_frame->setAcceptDrops(true);    //可以指定控件
}
//关闭上传对话框



