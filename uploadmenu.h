#ifndef UPLOADMENU_H
#define UPLOADMENU_H

#include <QWidget>
#include "uploadwidget.h"
namespace Ui {
class Uploadmenu;
}

class Uploadmenu : public QWidget
{
    Q_OBJECT

public:
    explicit Uploadmenu(QWidget *parent = nullptr);
    ~Uploadmenu();

    //鼠标按下
    virtual void mousePressEvent(QMouseEvent *ev);

protected:

    bool eventFilter(QObject * obj, QEvent * event);
    void leaveEvent(QEvent *event);

private:
    Ui::Uploadmenu *ui;
    UploadWidget * puploadwidget = nullptr;
};

#endif // UPLOADMENU_H
