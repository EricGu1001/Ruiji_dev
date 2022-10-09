#ifndef MYCONTENT_H
#define MYCONTENT_H

#include <QWidget>
#include <deletedialog.h>
#include <uploadmenu.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MyContent; }
QT_END_NAMESPACE

class MyContent : public QWidget
{
    Q_OBJECT

public:
    MyContent(QWidget *parent = nullptr);

    ~MyContent();

private slots:
    void on_btn_delete_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_searchEdit_2_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::MyContent *ui;
    DeleteDialog * deletedialog = nullptr;
    Uploadmenu * puploadmenu = nullptr;
    void getAll();
    void searchListWidgetItem(QString str);
};
#endif // MYCONTENT_H
