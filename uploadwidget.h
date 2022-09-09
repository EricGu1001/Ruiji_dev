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

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private slots:
    void on_pushButton_upload_clicked();

private:
    void setupView();
    Ui::UploadWidget *ui;
};

#endif // UPLOADWIDGET_H
