#ifndef PLAYERTOOL_H
#define PLAYERTOOL_H

#include <QWidget>

namespace Ui {
class PlayerTool;
}

class PlayerTool : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerTool(QWidget *parent = nullptr);
    ~PlayerTool();

private:
    Ui::PlayerTool *ui;
};

#endif // PLAYERTOOL_H
