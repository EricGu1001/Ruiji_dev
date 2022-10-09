#ifndef DELETETEST_H
#define DELETETEST_H

#include <QDialog>

namespace Ui {
class DeleteTest;
}

class DeleteTest : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteTest(QWidget *parent = nullptr);
    ~DeleteTest();
public slots:
    void mouseClicked();

private:
    Ui::DeleteTest *ui;
};

#endif // DELETETEST_H
