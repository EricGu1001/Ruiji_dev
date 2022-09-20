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

private:
    Ui::HomepageListItem *ui;
};

#endif // HOMEPAGELISTITEM_H
