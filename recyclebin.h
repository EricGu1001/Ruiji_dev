#ifndef RECYCLEBIN_H
#define RECYCLEBIN_H

#include <QWidget>

namespace Ui {
class RecycleBin;
}

class RecycleBin : public QWidget
{
    Q_OBJECT

public:
    explicit RecycleBin(QWidget *parent = nullptr);
    ~RecycleBin();

private slots:
    void on_searchEdit_textChanged(const QString &arg1);

private:
    Ui::RecycleBin *ui;
    void getAll();
    void noContent();
};

#endif // RECYCLEBIN_H
