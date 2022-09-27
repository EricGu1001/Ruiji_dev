#ifndef WIDGET_MY_H
#define WIDGET_MY_H

#include <QWidget>

namespace Ui {
class Widget_My;
}

class Widget_My : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_My(QWidget *parent = nullptr);
    ~Widget_My();
     Ui::Widget_My *ui;
signals:
    void beclicked();
private:

    QPoint mousePos;
protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // WIDGET_MY_H
