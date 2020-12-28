#include "chdialog.h"
#include "ui_chdialog.h"
#include "QMessageBox"

ChDialog::ChDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChDialog)
{
    ui->setupUi(this);
}

ChDialog::ChDialog(QWidget *parent,QSqlDatabase *databass) :
    QDialog(parent),
    ui(new Ui::ChDialog)
{
    ui->setupUi(this);
    this->db = databass;
    qDebug("database open status: %d\n", this->db->open());
}

ChDialog::~ChDialog()
{
    delete ui;
}


void ChDialog::on_exBt_clicked()
{
    this->exwin = new ExamWindow(this,this->db);
    this->exwin->show();
    this->hide();
}

void ChDialog::on_papBt_clicked()
{
    QString str = this->ui->lineEdit->text();
    if(str.isEmpty())
    {
        QMessageBox::information(this, "提示", "请填入章节");
        return;
    }
    else {
        this->papwin = new PaperWindow(this,this->db,str);
        this->papwin->show();
        this->hide();
    }
}
