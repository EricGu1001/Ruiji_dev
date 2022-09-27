#ifndef WIDGET_BIN_H
#define WIDGET_BIN_H

#include <QWidget>

namespace Ui {
class Widget_Bin;
}

class Widget_Bin : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Bin(QWidget *parent = nullptr);
    ~Widget_Bin();
    Ui::Widget_Bin *ui;
signals:
    void beclicked();
private:

    QPoint mousePos;
protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // WIDGET_BIN_H
