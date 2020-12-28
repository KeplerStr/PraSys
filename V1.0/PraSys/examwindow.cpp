#include "examwindow.h"
#include "ui_examwindow.h"
#include <QDebug>
#include <string>
#include <list>
#include <stdlib.h>

#include <QTime>
#include <QTimer>
#include <QDateTime>
#include <QProcess>

#include "mythread.h"    //线程类

using namespace std;

ExamWindow::ExamWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExamWindow)
{
    ui->setupUi(this);

    qDebug("database open status: %d\n", db->open());
}


MyThread *th;   //定义全局线程

/**
 * 重载构造函数
 */
ExamWindow::ExamWindow(QWidget *parent,QSqlDatabase *databass):
    QMainWindow(parent),
    ui(new Ui::ExamWindow)
{
    ui->setupUi(this);
    this->mysqldbget(databass);
    qDebug("database open status: %d\n", db->open());

    this->ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    this->ui->lcdNumber->setDigitCount(5);

    th = new MyThread(this);
//    th->start();

//    ui->lcdNumber->display(QDateTime::currentDateTime().toString("20:00"));
//    timer = new QTimer(this);
//    connect(timer,&QTimer::timeout,this,&ExamWindow::handle_timeout);
    //timer->start(1000);
}




void ExamWindow::lcd_getdata(QString time)
{
    this->ui->lcdNumber->display(time);

//    QString LogInfo;
//    LogInfo.sprintf("%p", QThread::currentThread());
//    qDebug() << "主窗口 " <<"threadID : "<<LogInfo;
}


void ExamWindow::handle_timeout()
{
    for( min =19;min>=0 ;min--){
        for(sec=59;sec>=0;sec--){
            ui->lcdNumber->display(QDateTime::currentDateTime().toString(QString::number(min)+":"+QString::number(sec)));
            Delay_ms(1000);
        }
    }
    timer->stop();
}


void ExamWindow::Delay_ms(unsigned int ms)
{
    QTime _Timer = QTime::currentTime().addMSecs(int(ms));
    while(QTime::currentTime() < _Timer){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
//    if(this->type != 2)
//    {
//        timer->stop();
//    }
}

/**
 * 读取筛选信息
 */
void ExamWindow::tablefiled_get()
{
    this->chap = this->ui->chapter_lineEdit->text();    //读取章节
    this->type = this->ui->qscBox->currentIndex();      //读取题型
    this->grade = this->ui->hardcBox->currentIndex();   //读取难度
    if(this->grade == 0)    //随机难度
    {
        this->grade = (rand() % (3-1+1))+ 1;//产生随机数1-3之间
    }

    if(this->type==2)
    {
        this->newthop = true;
        th->start();
    }else {
        this->newthop = false;
    }
}

/**
 * 查询后创建题目数据表
 */
void ExamWindow::sqltableCreate()
{
    QSqlQuery *query = new QSqlQuery(*this->db);
    bool success = query->exec("truncate table resbank");
    if(success)
    {
        qDebug()<<"数据表已经删除";
    }

    this->tablefiled_get();     //获取筛选属性

    QStringList chap_List;      //建立列表

    //处理String，拼接成list
    if(this->chap.toStdString().find(',') != string::npos)
    {
        chap_List = this->chap.split(",");
    }
    else if(this->chap.toStdString().find('-') != string::npos){
        chap_List = this->chap.split("-");
        for (int i = chap_List[0].toInt();i<chap_List[1].toInt()-1;++i) {
            chap_List.append(QString::number(i+1));
        }
    }else if(this->chap.isEmpty()){
        return;
    }else {
        chap_List.append(this->chap);
    }

    qDebug()<<chap_List;


    QString str_query = "select * from qsbank where binary type=? and grade=? and (";
    for (int i=0;i<chap_List.length();++i) {
        str_query = str_query + "chap=" + chap_List[i]+" or ";
    }
    str_query.chop(4);  //删除后面四个字符
    str_query += ")";

    query->prepare(str_query);
    query->bindValue(0,this->type);        //填充筛选字段的值
    query->bindValue(1,this->grade);
    query->exec();                         //执行sql语句

    qDebug()<<str_query;

    query->seek(-1);

    str_query = "insert into resbank (id,chap,type,grade,qes,ans) values (?,?,?,?,?,?)";

    QSqlQuery *query2 = new QSqlQuery(*this->db);
    this->ques_num = 0;     //计算题目数量
    while (query->next()) { //遍历数据表
        this->ques_num++;
        query2->prepare(str_query);
        query2->bindValue(0,query->value(0));
        query2->bindValue(1,query->value(1));
        query2->bindValue(2,query->value(2));
        query2->bindValue(3,query->value(3));
        query2->bindValue(4,query->value(4));
        query2->bindValue(5,query->value(5));
        if(query2->exec()!=true)
        {
            qDebug()<<"插入失败";
        }else {
            qDebug()<<"插入成功";
        }
//        qDebug()<<query->value(0).toInt()<<query->value(1)<<query->value(2)<<query->value(3)<<query->value(4)<<query->value(5);
    }
    qDebug()<<"题目数量:"<<ques_num;
    //用作返回指针
    delete query2;
    delete query;
}

/**
 * 获取登录窗口的数据库
 */
void ExamWindow::mysqldbget(QSqlDatabase *databass)
{
    this->db = databass;
}


/**
 * 析构函数
 */
ExamWindow::~ExamWindow()
{
    delete ui;
}

/**
 * 筛选槽函数
 */
void ExamWindow::on_filtrateBt_clicked()
{
//    this->tablefiled_get();
//    qDebug()<<this->chap<<this->type<<this->grade;
    this->sqltableCreate();

    this->myquery = new QSqlQuery(*this->db);
    this->myquery->exec("select * from resbank");


    myquery->seek(0);

    this->ui->textBrowser_que->setText(myquery->value(0).toString()+"."+myquery->value(4).toString());
    this->index=0;
//    while (myquery->next())
//        qDebug()<<myquery->value(0).toInt()<<myquery->value(1)<<myquery->value(2)<<myquery->value(3)<<myquery->value(4)<<myquery->value(5);

}


/**
 * 解析按钮槽函数
 */
void ExamWindow::on_analysisBt_clicked()
{
    this->ui->textBrowser_ans->setText(myquery->value(5).toString());
}


/**
 * @brief ExamWindow::on_pgupBt_clicked
 */
void ExamWindow::on_pgupBt_clicked()
{
    this->newthop = false;
    th->wait();             //等待子进程结束,进程间同步

    if(index==0)
    {
        return;
    }else {
        index--;
    }
    this->myquery->seek(this->index);
    this->ui->textBrowser_que->setText(myquery->value(0).toString()+"."+myquery->value(4).toString());

    if(this->type == 2)
    {
        this->newthop = true;
        th->start();
    }
}

/**
 * @brief ExamWindow::on_pgdnBt_clicked
 */
void ExamWindow::on_pgdnBt_clicked()
{
    this->newthop = false;
    th->wait();     //等待子线程结束
    if(index==ques_num-1)
    {
        return;
    }
    else {
        index++;
    }
    this->myquery->seek(index);
    this->ui->textBrowser_que->setText(myquery->value(0).toString()+"."+myquery->value(4).toString());

    if(this->type == 2)
    {
        this->newthop = true;
        th->start();
    }
}
