#include "uploadframe.h"
#include "ui_uploadframe.h"

UploadFrame::UploadFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::UploadFrame)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

UploadFrame::~UploadFrame()
{
    delete ui;
}
