#ifndef CHDIALOG_H
#define CHDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include "examwindow.h"
#include "paperwindow.h"

namespace Ui {
class ChDialog;
}

class ChDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChDialog(QWidget *parent = nullptr);
    ChDialog(QWidget *parent = nullptr,QSqlDatabase *databass = nullptr);
    ~ChDialog();
    QSqlDatabase *db;

private slots:
    void on_exBt_clicked();

    void on_papBt_clicked();

private:
    Ui::ChDialog *ui;
    ExamWindow *exwin;
    PaperWindow *papwin;

};

#endif // CHDIALOG_H
