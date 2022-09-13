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
//    virtual void mousePressEvent(QMouseEvent *ev);

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
//    void mouseReleaseEvent(QMouseEvent *ev);
//    bool eventFilter(QObject * obj, QEvent *ev);
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
