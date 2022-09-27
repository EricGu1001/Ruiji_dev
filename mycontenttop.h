#ifndef MYCONTENTTOP_H
#define MYCONTENTTOP_H

#include <QWidget>

namespace Ui {
class MyContentTop;
}

class MyContentTop : public QWidget
{
    Q_OBJECT

public:
    explicit MyContentTop(QWidget *parent = nullptr);
    ~MyContentTop();

private:
    Ui::MyContentTop *ui;
};

#endif // MYCONTENTTOP_H
