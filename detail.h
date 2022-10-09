#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include "playertool.h"
namespace Ui {
class Detail;
}

class Detail : public QWidget
{
    Q_OBJECT

public:
    explicit Detail(QWidget *parent = nullptr);
    ~Detail();

private:
    Ui::Detail *ui;
    void* mainPtr;
};

#endif // DETAIL_H
