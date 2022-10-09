#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QWidget>

namespace Ui {
class DeleteDialog;
}

class DeleteDialog : public QWidget
{
    Q_OBJECT

public:
    int delCnt;
    QVector<int> ids;
    explicit DeleteDialog(QWidget *parent = nullptr);
    ~DeleteDialog();
public slots:
    void contentChange(int count);
private:
    Ui::DeleteDialog *ui;
public slots:
    void mouseClicked();
private slots:
    void on_delete_confirm_clicked();
};

#endif // DELETEDIALOG_H
