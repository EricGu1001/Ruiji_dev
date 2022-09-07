#ifndef UPLOADMENU_H
#define UPLOADMENU_H

#include <QWidget>

namespace Ui {
class Uploadmenu;
}

class Uploadmenu : public QWidget
{
    Q_OBJECT

public:
    explicit Uploadmenu(QWidget *parent = nullptr);
    ~Uploadmenu();

private:
    Ui::Uploadmenu *ui;
};

#endif // UPLOADMENU_H
