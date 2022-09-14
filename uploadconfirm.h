#ifndef UPLOADCONFIRM_H
#define UPLOADCONFIRM_H

#include <QWidget>

namespace Ui {
class UploadConfirm;
}

class UploadConfirm : public QWidget
{
    Q_OBJECT

public:
    explicit UploadConfirm(QWidget *parent = nullptr);
    ~UploadConfirm();

private:
    Ui::UploadConfirm *ui;
};

#endif // UPLOADCONFIRM_H
