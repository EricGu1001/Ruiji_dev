#ifndef QCLICKWIDGET_H
#define QCLICKWIDGET_H

#include <QWidget>

class QClickWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QClickWidget(QWidget *parent = nullptr);

signals:
    void beclicked();
};

#endif // QCLICKWIDGET_H
