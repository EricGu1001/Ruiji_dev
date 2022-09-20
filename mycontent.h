#ifndef MYCONTENT_H
#define MYCONTENT_H

#include <QWidget>

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

private:
    Ui::MyContent *ui;
};
#endif // MYCONTENT_H
