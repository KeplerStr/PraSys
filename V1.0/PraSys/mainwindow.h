#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/*******************************************
 *user_include
 **************/
#include "chdialog.h"
#include "examwindow.h"
#include "paperwindow.h"

#include <QKeyEvent>
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
/******************************************/



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static QString name_ext;
    static QString stunum_ext;

    QString hostName;
    QString dbName;
    QString userName;
    QString password;
    QSqlDatabase db;

    void login_open_newWin();

private slots:
    void on_loginBt_clicked();
    void on_regBt_clicked();

private:
    Ui::MainWindow *ui;
    ExamWindow *ew;

    PaperWindow *papwin;

    ChDialog *chwin;
    void keyPressEvent(QKeyEvent *ev);  //键盘事件
//    void keyPressEvent(QKeyEvent *ev);
};

#endif // MAINWINDOW_H
