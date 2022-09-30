#ifndef LISTITEM_H
#define LISTITEM_H

#include <QWidget>

namespace Ui {
class ListItem;
}

class ListItem : public QWidget
{
    Q_OBJECT

public:
    explicit ListItem(QWidget *parent = nullptr);
    ~ListItem();

    //设置会议标题
    void setMeetingTitle(QString title);
    //设置会议时长
    void setDuration(QString duration);
    //设置创建时间
    void setCreateTime(QString createTime);

    //设置图片
    void setImage(QString imgURL);

    void mouseMoveEvent(QMouseEvent* e);
    Ui::ListItem *ui;
private:

protected:

    bool eventFilter(QObject * obj, QEvent * event);
    void leaveEvent(QEvent *event);
};

#endif // LISTITEM_H
