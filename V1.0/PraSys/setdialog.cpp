#include "setdialog.h"
#include "ui_setdialog.h"

SetDialog::SetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetDialog)
{
    ui->setupUi(this);


}

SetDialog::~SetDialog()
{
    delete ui;
}

void SetDialog::on_pushButton_clicked()
{
    if(this->ui->lineEdit->text().isEmpty())
        return;
    else
    {
        this->chapstr = this->ui->lineEdit->text();
    }
    emit th_sign();

}
