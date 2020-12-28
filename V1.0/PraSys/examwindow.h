#ifndef EXAMWINDOW_H
#define EXAMWINDOW_H

#include <QMainWindow>

#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

namespace Ui {
class ExamWindow;
}

class ExamWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExamWindow(QWidget *parent = nullptr);
    ExamWindow(QWidget *parent = nullptr,QSqlDatabase *databass = nullptr);
    ~ExamWindow();
    bool newthop = true;
    QTimer *timer;
    int min=20;
    int sec=0;
    void mysqldbget(QSqlDatabase *databass);

    void tablefiled_get();

    void sqltableCreate();

    void lcd_getdata(QString time);

    void Delay_ms(unsigned int ms);

private slots:
    void on_filtrateBt_clicked();

    void on_analysisBt_clicked();
    void on_pgupBt_clicked();

    void on_pgdnBt_clicked();

    void handle_timeout(void);



private:
    Ui::ExamWindow *ui;
    QSqlDatabase *db;
    QSqlQuery* myquery; //用来记录查询后的题目
    qint8 index=0;
    qint8 ques_num=0;
    int id = 0;
    QString chap;
    int type = 0;
    int grade = 0;


};


#endif // EXAMWINDOW_H
