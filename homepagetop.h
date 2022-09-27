#ifndef HOMEPAGETOP_H
#define HOMEPAGETOP_H
#include "uploadmenu.h"
#include <QWidget>

namespace Ui {
class HomepageTop;
}

class HomepageTop : public QWidget
{
    Q_OBJECT

public:
    explicit HomepageTop(QWidget *parent = nullptr);
    ~HomepageTop();
private slots:
    void on_pushButton_clicked();
private:
    Ui::HomepageTop *ui;
    Uploadmenu * puploadmenu = nullptr;
};

#endif // HOMEPAGETOP_H
