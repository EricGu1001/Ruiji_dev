#ifndef RECOVER_H
#define RECOVER_H

#include <QDialog>

namespace Ui {
class Recover;
}

class Recover : public QDialog
{
    Q_OBJECT

public:
    explicit Recover(QWidget *parent = nullptr);
    ~Recover();
public slots:
    void mouseClicked();
protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
private:
    Ui::Recover *ui;
    QPoint z;
};

#endif // RECOVER_H
