#ifndef HOMEPAGE_H
#define HOMEPAGE_H
#include "uploadmenu.h"
#include <QWidget>

namespace Ui {
class Homepage;
}

class Homepage : public QWidget
{
    Q_OBJECT

public:
    explicit Homepage(QWidget *parent = nullptr);
    ~Homepage();
private slots:
    void on_pushButton_clicked();
    void on_searchEdit_textChanged(const QString &arg1);

private:
    Ui::Homepage *ui;
    Uploadmenu * puploadmenu = nullptr;
};

#endif // HOMEPAGE_H
