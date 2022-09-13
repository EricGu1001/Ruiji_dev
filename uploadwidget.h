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

signals:
    void beclicked();
private slots:
    void on_pushButton_upload_clicked();
public slots:
    void mouseClicked();

private:
    void setupView();
    Ui::UploadWidget *ui;
};

#endif // UPLOADWIDGET_H
