#ifndef HOMEPAGELISTITEM_H
#define HOMEPAGELISTITEM_H

#include <QWidget>

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

protected:
    bool eventFilter(QObject * obj, QEvent * event);
    void leaveEvent(QEvent *event);
};

#endif // HOMEPAGELISTITEM_H
