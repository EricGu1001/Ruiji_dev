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
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

signals:
    void beclicked();
private slots:
    void on_pushButton_upload_clicked();
public slots:
    void mouseClicked();

private:
    void setupView();
    QPoint z;
    Ui::UploadWidget *ui;
};

#endif // UPLOADWIDGET_H
