#ifndef GDDIALOG_H
#define GDDIALOG_H

#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class GdDialog;
}

class GdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GdDialog(QWidget *parent = nullptr);
    GdDialog(QWidget *parent = nullptr,QSqlQuery *query = nullptr,qint8 res=0);//重载获取数据库地址
    ~GdDialog();

private:
    Ui::GdDialog *ui;
    QSqlQuery *myquery;
    qint8 gdres;

};

#endif // GDDIALOG_H
