#ifndef PAPERWINDOW_H
#define PAPERWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QList>
#include <QSqlQuery>
#include "gddialog.h"
#include "setdialog.h"


namespace Ui {
class PaperWindow;
}

//根据难度将三个等级题目的id分开
typedef struct
{
    QList<int> *queGradeid_1 = new QList<int>();
    QList<int> *queGradeid_2 = new QList<int>();
    QList<int> *queGradeid_3 = new QList<int>();
}IdGradedef;      //选择题三种难度题目数据结构

typedef struct
{
    IdGradedef *mcid = new IdGradedef();  //单选id
    IdGradedef *jbid = new IdGradedef();  //判断id
    IdGradedef *sbid = new IdGradedef();  //大题id
}QueidGradedef;       //三种题型数据结构

typedef struct{
    int grade_1;
    int grade_2;
    int grade_3;
    int all_grade;
}NumGradeDef;

typedef struct
{
    NumGradeDef mcnum;
    NumGradeDef jbnum;
    NumGradeDef sbnum;
}QueNumDef;         //需要的题目道数

class PaperWindow : public QMainWindow
{
    Q_OBJECT
public:
    PaperWindow(QWidget *parent = nullptr);
    PaperWindow(QWidget *parent = nullptr,QSqlDatabase *databass = nullptr,QString chapstr = "");//重载获取数据库地址

    ~PaperWindow();
    QSqlQuery *myquery;
    qint8 ansck[11] = {0};
    qint8 gdres = 0;
    bool newthop = true;        //线程标志

    QStringList chaplist;  //章节列表数据结构
    QList<int> *paperid = new QList<int>();

    QueNumDef *quenum = new QueNumDef();

    bool queNumInit(QueNumDef *que_num);                        //通过章节进行筛选，获取到三个不同难度的id
    bool chapQueIdInit(QString chapstr,QueidGradedef *que_id);  //筛选题目进入题库
    bool paperQueIdInit(QList<int> *paper_id);                  //根据每种题的个数 得到试卷
    bool seekId(QList<int> *list,int num,QList<int> *list2);    //拷贝题库题目id列表到试卷题库题目id列表
    void generatePaper(QSqlQuery *query);    //根据id生成数据库

    void lcdGetData(QString time);

signals:
    void btck_sig(qint8 state);
    void rbtck_sig(QString ans);


private slots:
    void th_slot(); //线程信号

    void btck_slot(qint8 state);
    void rbtck_slot(QString ans);

    void on_mcBt_1_clicked();

    void on_mcBt_4_clicked();

    void on_mcBt_2_clicked();

    void on_mcBt_3_clicked();

    void on_mcBt_5_clicked();

    void on_mcBt_6_clicked();

    void on_mcBt_7_clicked();

    void on_mcBt_8_clicked();

    void on_mcBt_9_clicked();

    void on_mcBt_10_clicked();

    void on_jgBt_1_clicked();

    void on_jgBt_2_clicked();

    void on_jgBt_3_clicked();

    void on_jgBt_4_clicked();

    void on_jgBt_5_clicked();

    void on_jgBt_6_clicked();

    void on_jgBt_7_clicked();

    void on_jgBt_8_clicked();

    void on_jgBt_9_clicked();

    void on_jgBt_10_clicked();

    void on_sbBt_1_clicked();

    void on_coBt_clicked();

    void on_pdBt_clicked();

    void on_puBt_clicked();

    void on_rBt_A_clicked();

    void on_rBt_B_clicked();

    void on_rBt_C_clicked();

    void on_rBt_D_clicked();

    void on_rBt_right_clicked();

    void on_rBt_false_clicked();

    void on_doBt_clicked();

private:
    Ui::PaperWindow *ui;
    QSqlDatabase *db;

    QueidGradedef *queid = new QueidGradedef();   //题目id数据结构


    GdDialog *gdwin;
    SetDialog *setwin;

    QString myans;
    qint8 index=0;                                //题目标记

    QString anslist[11]={""};


    //根据章节字符串 获取章节列表
    bool chaplist_get(QString chap);
    int rangenum_get(int que_num);                  //把题目的道数送入随机函数进行随机，返回一个数，对应列表id
    void sleep(unsigned int msec);
};

#endif // PAPERWINDOW_H
