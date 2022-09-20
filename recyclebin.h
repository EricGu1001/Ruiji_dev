#ifndef RECYCLEBIN_H
#define RECYCLEBIN_H

#include <QWidget>

namespace Ui {
class RecycleBin;
}

class RecycleBin : public QWidget
{
    Q_OBJECT

public:
    explicit RecycleBin(QWidget *parent = nullptr);
    ~RecycleBin();

private:
    Ui::RecycleBin *ui;
};

#endif // RECYCLEBIN_H
