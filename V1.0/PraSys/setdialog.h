#ifndef SETDIALOG_H
#define SETDIALOG_H

#include <QDialog>

namespace Ui {
class SetDialog;
}

class SetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetDialog(QWidget *parent = nullptr);
    ~SetDialog();
    QString chapstr;

signals:
    void th_sign();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SetDialog *ui;
};

#endif // SETDIALOG_H
