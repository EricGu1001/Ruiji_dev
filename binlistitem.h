#ifndef BINLISTITEM_H
#define BINLISTITEM_H

#include <QWidget>
#include "recover.h"
namespace Ui {
class BinListitem;
}

class BinListitem : public QWidget
{
    Q_OBJECT

public:
    explicit BinListitem(QWidget *parent = nullptr);
    ~BinListitem();
    //设置会议标题
    void setMeetingTitle(QString title);
    //设置会议时长
    void setDuration(QString duration);
    //设置创建时间
    void setCreateTime(QString createTime);

    //设置图片
    void setImage(QString imgURL);
    void setReImage(QString imgURL);
    //设置操作图片
    void setOperationImg(QString imgURL);

    void mouseMoveEvent(QMouseEvent* e);
signals:
    void beclicked();
public slots:
    void mouseClicked();
private:
    Ui::BinListitem *ui;
    QPoint mousePos;
    Recover * recover = nullptr;
protected:
    bool eventFilter(QObject * obj, QEvent * event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // BINLISTITEM_H
