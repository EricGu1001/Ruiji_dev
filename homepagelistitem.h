#ifndef HOMEPAGELISTITEM_H
#define HOMEPAGELISTITEM_H

#include <QWidget>
#include "delete.h"
#include "deletetest.h"
namespace Ui {
class HomepageListItem;
}

class HomepageListItem : public QWidget
{
    Q_OBJECT

public:
    explicit HomepageListItem(QWidget *parent = nullptr);
    ~HomepageListItem();


    //设置会议标题
    void setMeetingTitle(QString title);
    //设置会议时长
    void setDuration(QString duration);
    //设置创建时间
    void setCreateTime(QString createTime);

    //设置图片
    void setImage(QString imgURL);
    //设置操作图片
    void setOperationImg(QString imgURL);

    void mouseMoveEvent(QMouseEvent* e);

private:
    Ui::HomepageListItem *ui;
    Delete * pdelete = nullptr;
    DeleteTest * deletetest = nullptr;
    QPoint mousePos;
signals:
    void beclicked();
public slots:
    void mouseClicked();
protected:
    bool eventFilter(QObject * obj, QEvent * event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // HOMEPAGELISTITEM_H
