#ifndef UPLOADWIDGET_H
#define UPLOADWIDGET_H

#include <QWidget>

namespace Ui {
class UploadWidget;
}

class UploadWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UploadWidget(QWidget *parent = nullptr);
    ~UploadWidget();

    //鼠标按下
    virtual void mousePressEvent(QMouseEvent *ev);

private:
    Ui::UploadWidget *ui;
};

#endif // UPLOADWIDGET_H
