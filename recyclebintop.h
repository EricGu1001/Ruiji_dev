#ifndef RECYCLEBINTOP_H
#define RECYCLEBINTOP_H

#include <QWidget>

namespace Ui {
class RecyclebinTop;
}

class RecyclebinTop : public QWidget
{
    Q_OBJECT

public:
    explicit RecyclebinTop(QWidget *parent = nullptr);
    ~RecyclebinTop();

private:
    Ui::RecyclebinTop *ui;
};

#endif // RECYCLEBINTOP_H
