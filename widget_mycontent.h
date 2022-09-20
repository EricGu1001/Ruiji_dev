#ifndef WIDGET_MYCONTENT_H
#define WIDGET_MYCONTENT_H

#include <QWidget>

namespace Ui {
class Widget_Mycontent;
}

class Widget_Mycontent : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Mycontent(QWidget *parent = nullptr);
    ~Widget_Mycontent();
signals:
    void beclicked();
private:
    Ui::Widget_Mycontent *ui;
    QPoint mousePos;
protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // WIDGET_MYCONTENT_H
