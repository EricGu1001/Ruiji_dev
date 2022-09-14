#include "uploadconfirm.h"
#include "ui_uploadconfirm.h"

UploadConfirm::UploadConfirm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UploadConfirm)
{
    ui->setupUi(this);
}

UploadConfirm::~UploadConfirm()
{
    delete ui;
}
