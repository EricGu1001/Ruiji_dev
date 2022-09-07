#ifndef UPLOADFRAME_H
#define UPLOADFRAME_H

#include <QFrame>

namespace Ui {
class UploadFrame;
}

class UploadFrame : public QFrame
{
    Q_OBJECT

public:
    explicit UploadFrame(QWidget *parent = nullptr);
    ~UploadFrame();

private:
    Ui::UploadFrame *ui;
};

#endif // UPLOADFRAME_H
