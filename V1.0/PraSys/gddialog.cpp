#include "gddialog.h"
#include "ui_gddialog.h"
#include <QString>
#include <QDebug>

GdDialog::GdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GdDialog)
{
    ui->setupUi(this);
}

GdDialog::GdDialog(QWidget *parent,QSqlQuery *query,qint8 res) :
    QDialog(parent),
    ui(new Ui::GdDialog)
{
    ui->setupUi(this);
    this->myquery = query;
    this->gdres = res;
    this->ui->label_gd->setText(QString::number(this->gdres)+"分");
    myquery->exec("select * from paper");
    for (qint8 i = 0;i<11;i++) {
        myquery->seek(i);
        QString str = "";
        qDebug()<<myquery->value(2)<<myquery->value(3)<<myquery->value(4);
        if(myquery->value(4).toInt() == 1)
            str = QString::number(i+1)+"."+myquery->value(2).toString()+"\t"+myquery->value(3).toString()+"\t"+"正确";
        else
            str = QString::number(i+1)+"."+myquery->value(2).toString()+"\t"+myquery->value(3).toString()+"\t"+"错误";
        this->ui->tE_ans->append(str);
    }
}

GdDialog::~GdDialog()
{
    delete ui;
}
