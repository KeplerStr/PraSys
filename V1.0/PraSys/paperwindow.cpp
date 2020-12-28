#include "paperwindow.h"
#include "ui_paperwindow.h"
#include <QButtonGroup>
#include <QDebug>
#include <string>
#include <stdlib.h>

#include "mythread2.h"

#include <ctime>
#include <QString>

#include <QApplication>
#include <QTime>

#include "mainwindow.h"

using namespace std;

PaperWindow::PaperWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PaperWindow)
{
    ui->setupUi(this);

}

void PaperWindow::sleep(unsigned int msec)
{
    QTime reachtime = QTime::currentTime().addMSecs(int(msec));
    while (QTime::currentTime()<reachtime)
        QApplication::processEvents(QEventLoop::AllEvents,100);
}

Mythread2 *th2;

/**
 * @brief PaperWindow::PaperWindow
 * @param parent
 * @param databass
 */
PaperWindow::PaperWindow(QWidget *parent,QSqlDatabase *databass,QString chapstr) :
    QMainWindow(parent),
    ui(new Ui::PaperWindow)
{
    ui->setupUi(this);

    this->db = databass;    //获取主窗口的数据库地址
    this->myquery = new QSqlQuery(*this->db);

    qDebug("database open status: %d\n", db->open());   //打印数据库连接状态

    //关闭使能选择题6-10个按钮
    this->ui->mcBt_6->setEnabled(false);
    this->ui->mcBt_7->setEnabled(false);
    this->ui->mcBt_8->setEnabled(false);
    this->ui->mcBt_9->setEnabled(false);
    this->ui->mcBt_10->setEnabled(false);

    //关闭使能判断题6-10个按钮
    this->ui->jgBt_6->setEnabled(false);
    this->ui->jgBt_7->setEnabled(false);
    this->ui->jgBt_8->setEnabled(false);
    this->ui->jgBt_9->setEnabled(false);
    this->ui->jgBt_10->setEnabled(false);

    //配置lcd参数
    this->ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    this->ui->lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
    this->ui->lcdNumber->setDigitCount(7);
    this->ui->lcdNumber_2->setDigitCount(7);

    //设置初始值
    this->ui->lcdNumber->display("1:00:00");
    this->ui->lcdNumber_2->display("1:00:00");

    this->ui->label_name->setText(MainWindow::name_ext);
    this->ui->label_stunum->setText(MainWindow::stunum_ext);

    QButtonGroup *mRadioGroup_1 = new QButtonGroup(this);   //单选按钮分组
    QButtonGroup *mRadioGroup_2 = new QButtonGroup(this);

    //按钮分组1
    mRadioGroup_1->addButton(this->ui->rBt_A);
    mRadioGroup_1->addButton(this->ui->rBt_B);
    mRadioGroup_1->addButton(this->ui->rBt_C);
    mRadioGroup_1->addButton(this->ui->rBt_D);

    //按钮分组2
    mRadioGroup_2->addButton(this->ui->rBt_right);
    mRadioGroup_2->addButton(this->ui->rBt_false);


    connect(this,SIGNAL(btck_sig(qint8)),this,SLOT(btck_slot(qint8)));
    connect(this,SIGNAL(rbtck_sig(QString)),this,SLOT(rbtck_slot(QString)));

//    this->setwin = new SetDialog(this);
//    this->setwin->show();

    this->queNumInit(this->quenum);             //初始化题目个数
    //qDebug()<<this->quenum->mcnum.grade_1;

    this->chapQueIdInit(chapstr,this->queid);    //seek得到章节题目id
    //qDebug()<<*(this->queid->mcid->queGradeid_2);

    this->paperQueIdInit(this->paperid);      //得到试卷中的题目id

    qDebug()<<*(this->paperid);

    generatePaper(this->myquery);

    this->myquery->seek(this->index);
    this->ui->tE_que->setText("单项选择题\r\n");
    this->ui->tE_que->append(QString::number(this->index+1)+"."+this->myquery->value(1).toString());

    th2 = new Mythread2(this);
    th2->start();
}

void PaperWindow::th_slot()
{
    this->newthop = false;
}

void PaperWindow::lcdGetData(QString time)
{
    this->ui->lcdNumber_2->display(time);
}

void PaperWindow::generatePaper(QSqlQuery *query)
{
    //QSqlQuery *query = new QSqlQuery(*this->db);

    bool success = query->exec("truncate table paper");
    if(success)
    {
        qDebug()<<"数据表已经删除";

        QString querystr = "select * from qsbank where binary id=?";

        QSqlQuery *query2 = new QSqlQuery(*this->db);
        for (qint8 i=0;i<this->paperid->length();i++) {
            querystr = "select * from qsbank where binary id=?";
            query->prepare(querystr);
            query->bindValue(0,(*this->paperid)[i]);
            query->exec();
            query->seek(0);

            querystr = "insert into paper (id,qus,ans,myans,isright) values (?,?,?,?,?)";
            query2->prepare(querystr);
            query2->bindValue(0,query->value(0)); //写入id
            query2->bindValue(1,query->value(4)); //写入问题
            query2->bindValue(2,query->value(5)); //写入答案
            query2->bindValue(3,NULL);            //我的答案
            query2->bindValue(4,NULL);            //是否正确
            query2->exec();                       //执行
        }

//        QString querystr = "select * from qsbank where binary ";
//        for (qint8 i = 0;i<this->paperid->length();i++) {
//            querystr += "id="+QString::number((*this->paperid)[i])+" or ";
//        }
//        querystr.chop(4);
//        qDebug()<<querystr;
//        query->exec(querystr);

//        QSqlQuery *query2 = new QSqlQuery(*this->db);
//        querystr = "insert into paper (id,qus,ans,myans,isright) values (?,?,?,?,?)";
//        query2->prepare(querystr);

//        query->seek(-1);
//        while (query->next()) {
//            query2->bindValue(0,query->value(0)); //写入id
//            query2->bindValue(1,query->value(4)); //写入问题
//            query2->bindValue(2,query->value(5)); //写入答案
//            query2->bindValue(3,NULL);            //我的答案
//            query2->bindValue(4,NULL);            //是否正确
//            query2->exec();                       //执行
//        }

        query->exec("select * from paper");
    }
}


bool PaperWindow::queNumInit(QueNumDef *que_num)
{
    que_num->mcnum.grade_1 = 2;
    que_num->mcnum.grade_2 = 2;
    que_num->mcnum.grade_3 = 1;
    que_num->mcnum.all_grade = 5;

    que_num->jbnum.grade_1 = 2;
    que_num->jbnum.grade_2 = 2;
    que_num->jbnum.grade_3 = 1;
    que_num->jbnum.all_grade = 5;

    que_num->sbnum.grade_1 = 0;
    que_num->sbnum.grade_2 = 1;
    que_num->sbnum.grade_3 = 0;
    que_num->sbnum.all_grade = 1;
    return true;
}

bool PaperWindow::seekId(QList<int> *list,int num,QList<int> *list2)
{
    int temp = 0;
    for (int i = 0;i<num;i++) {
        temp = this->rangenum_get(list2->length()-1);

        qDebug()<<temp;

        this->sleep(1000);

        if(list->indexOf((*list2)[temp]) == (-1))
        {
            qDebug()<<"插入";
            list->append((*list2)[temp]);
        }else {
            qDebug()<<"未插入";
            i--;
        }

    }
    return true;
}

bool PaperWindow::paperQueIdInit(QList<int> *paper_id)
{
    this->seekId(paper_id,this->quenum->mcnum.grade_1,this->queid->mcid->queGradeid_1);
    this->seekId(paper_id,this->quenum->mcnum.grade_2,this->queid->mcid->queGradeid_2);
    this->seekId(paper_id,this->quenum->mcnum.grade_3,this->queid->mcid->queGradeid_3);

    this->seekId(paper_id,this->quenum->jbnum.grade_1,this->queid->jbid->queGradeid_1);
    this->seekId(paper_id,this->quenum->jbnum.grade_2,this->queid->jbid->queGradeid_2);
    this->seekId(paper_id,this->quenum->jbnum.grade_3,this->queid->jbid->queGradeid_3);

    this->seekId(paper_id,this->quenum->sbnum.grade_1,this->queid->sbid->queGradeid_1);
    this->seekId(paper_id,this->quenum->sbnum.grade_2,this->queid->sbid->queGradeid_2);
    this->seekId(paper_id,this->quenum->sbnum.grade_3,this->queid->sbid->queGradeid_3);

    //qSort(paper_id->begin(),paper_id->end());//排序

    return true;
}

/**
 * @brief PaperWindow::chaplist_get
 * @param chap
 * @return
 */
bool PaperWindow::chaplist_get(QString chap)
{
    if(chap.toStdString().find(',') != string::npos)
    {
        chaplist = chap.split(",");
    }
    else if(chap.toStdString().find('-') != string::npos){
        chaplist = chap.split("-");
        for (int i = chaplist[0].toInt();i<chaplist[1].toInt()-1;++i) {
            chaplist.append(QString::number(i+1));
        }
    }else if(chap.isEmpty()){
        return false;
    }else {
        chaplist.append(chap);
    }
    return true;
}


//根据不同章节 得到不同难度题目的id
bool PaperWindow::chapQueIdInit(QString chapstr,QueidGradedef *que_id)
{
    QSqlQuery *query = new QSqlQuery(*this->db);
    if(this->chaplist_get(chapstr))
    {
        //处理sql语句
        QString str_query = "select * from qsbank where binary type=? and grade=? and (";
        for (int i=0;i<this->chaplist.length();++i) {
            str_query = str_query + "chap=" + this->chaplist[i]+" or ";
        }
        str_query.chop(4);  //删除后面四个字符
        str_query += ")";

        //获取题目id
        for (int i=1;i<4;i++) {
            for (int j=0;j<3;j++) {
                query->prepare(str_query);
                query->bindValue(0,j);      //题目 0单选 1判断 2大题
                query->bindValue(1,i);      //难度一
                query->exec();              //执行sql语句
                query->seek(-1);

                while (query->next()) {
                    switch (i) {
                    case 1:
                    {
                        if(j==0)
                        {
                            que_id->mcid->queGradeid_1->append(query->value(0).toInt());
                        }else if(j==1){
                            que_id->jbid->queGradeid_1->append(query->value(0).toInt());
                        }else if(j==2){
                            que_id->sbid->queGradeid_1->append(query->value(0).toInt());
                        }
                        break;
                    }
                    case 2:
                    {
                        if(j==0)
                        {
                            que_id->mcid->queGradeid_2->append(query->value(0).toInt());
                        }else if(j==1){
                            que_id->jbid->queGradeid_2->append(query->value(0).toInt());
                        }else if(j==2){
                            que_id->sbid->queGradeid_2->append(query->value(0).toInt());
                        }
                        break;
                    }
                    case 3:
                    {
                        if(j==0)
                        {
                            que_id->mcid->queGradeid_3->append(query->value(0).toInt());
                        }else if(j==1){
                            que_id->jbid->queGradeid_3->append(query->value(0).toInt());
                        }else if(j==2){
                            que_id->sbid->queGradeid_3->append(query->value(0).toInt());
                        }
                        break;
                    }

                    }
                }

            }
        }
    }else {
        return false;
    }
    return true;
}

/**
 * @brief PaperWindow::rangenum_get
 * @param que_num
 * @return
 */
int PaperWindow::rangenum_get(int que_num)
{

    srand((unsigned int)time(nullptr));
    int temp = rand()%(que_num-0+1)+0;
    return temp;
   //return (rand() % ((que_num-1)-0+0))+ 0;
}

/**
 * @brief PaperWindow::~PaperWindow
 */
PaperWindow::~PaperWindow()
{
    delete ui;
}

/**
 * 按键处理槽函数
 */
void PaperWindow::btck_slot(qint8 state)
{
    if(this->index<5)
        this->ui->tE_que->setText("单项选择题\r\n");
    else if(this->index<10){
        this->ui->tE_que->setText("判断题\r\n");
    }else {
        this->ui->tE_que->setText("程序分析题\r\n");
    }
    this->myquery->seek(this->index);
    this->ui->tE_que->append(QString::number(this->index+1)+"."+this->myquery->value(1).toString());


    if(this->index<11)
    {
        qint8 ansisRight = 0;
        QSqlQuery *query = new QSqlQuery(*this->db);
        QString sqlstr = "select * from paper where binary id=?";
        query->prepare(sqlstr);
        query->bindValue(0,(*this->paperid)[this->index+state]);
        query->exec();

        query->seek(0);
        if(query->value(2) == this->myans)
        {
            ansisRight = 1;
            this->ansck[this->index+state] = ansisRight;
        }
        sqlstr = "update paper set myans=?,isright=? where id=?";
        query->prepare(sqlstr);
        query->bindValue(0,this->myans);
        this->anslist[this->index+state] = this->myans; //将答案写入数组
        query->bindValue(1,ansisRight);

        query->bindValue(2,(*this->paperid)[this->index+state]);
        query->exec();
    }
}

/**
 * 选择题10个按钮槽函数
 */
void PaperWindow::on_mcBt_1_clicked()
{
    this->index = 0;
    emit this->btck_sig(0);
}

void PaperWindow::on_mcBt_2_clicked()
{
    this->index = 1;
    emit this->btck_sig(0);
}

void PaperWindow::on_mcBt_3_clicked()
{
    this->index = 2;
    emit this->btck_sig(0);
}

void PaperWindow::on_mcBt_4_clicked()
{
    this->index = 3;
    emit this->btck_sig(0);
}



void PaperWindow::on_mcBt_5_clicked()
{
    this->index = 4;
    emit this->btck_sig(0);
}

void PaperWindow::on_mcBt_6_clicked()
{

}

void PaperWindow::on_mcBt_7_clicked()
{

}

void PaperWindow::on_mcBt_8_clicked()
{

}

void PaperWindow::on_mcBt_9_clicked()
{

}

void PaperWindow::on_mcBt_10_clicked()
{

}
/**********************************************/

/**
 * 判断题10个按钮槽函数
 */
void PaperWindow::on_jgBt_1_clicked()
{
    this->index = 5;
    emit this->btck_sig(0);
}

void PaperWindow::on_jgBt_2_clicked()
{
    this->index = 6;
    emit this->btck_sig(0);
}

void PaperWindow::on_jgBt_3_clicked()
{
    this->index = 7;
    emit this->btck_sig(0);
}

void PaperWindow::on_jgBt_4_clicked()
{
    this->index = 8;
    emit this->btck_sig(0);
}

void PaperWindow::on_jgBt_5_clicked()
{
    this->index = 9;
    emit this->btck_sig(0);
}

void PaperWindow::on_jgBt_6_clicked()
{

}

void PaperWindow::on_jgBt_7_clicked()
{

}

void PaperWindow::on_jgBt_8_clicked()
{

}

void PaperWindow::on_jgBt_9_clicked()
{

}

void PaperWindow::on_jgBt_10_clicked()
{

}

/***********************************************/
/**
 * 主观题槽函数
 */
void PaperWindow::on_sbBt_1_clicked()
{
    this->index = 10;
    this->myans = this->ui->tE_ans->toPlainText();
    emit this->btck_sig(0);
}

/***********************************************/



/**
 * @brief PaperWindow::on_pdBt_clicked
 */
void PaperWindow::on_pdBt_clicked()
{
    if(this->index==this->paperid->length()-1)
    {
        return;
    }
    else {
        this->index++;
    }
    emit this->btck_sig(-1);

//    if(this->index<5)
//        this->ui->tBrowser_que->setText("单项选择题\r\n");
//    else if(this->index<11){
//        this->ui->tBrowser_que->setText("判断题\r\n");
//    }else {
//        this->ui->tBrowser_que->setText("程序分析题\r\n");
//    }
//    this->myquery->seek(this->index);
//    this->ui->tBrowser_que->append(QString::number(this->index+1)+"."+this->myquery->value(1).toString());
}

/**
 * @brief PaperWindow::on_puBt_clicked
 */
void PaperWindow::on_puBt_clicked()
{
    if(this->index==0)
    {
        return;
    }else {
        this->index--;
    }
    emit this->btck_sig(1);

//    this->myquery->seek(this->index);
//    if(this->index<5)
//        this->ui->tBrowser_que->setText("单项选择题\r\n");
//    else if(this->index<11){
//        this->ui->tBrowser_que->setText("判断题\r\n");
//    }else {
//        this->ui->tBrowser_que->setText("程序分析题\r\n");
//    }
//    this->ui->tBrowser_que->append(QString::number(this->index+1)+"."+this->myquery->value(1).toString());
}

/**
 * rbt处理槽函数
 */
void PaperWindow::rbtck_slot(QString ans)
{
    this->myans = ans;
}

void PaperWindow::on_rBt_A_clicked()
{
    this->ui->tE_hint->setText("A");
    emit rbtck_sig("A");
}

void PaperWindow::on_rBt_B_clicked()
{
    this->ui->tE_hint->setText("B");
    emit rbtck_sig("B");
}

void PaperWindow::on_rBt_C_clicked()
{
    this->ui->tE_hint->setText("C");
    emit rbtck_sig("C");
}

void PaperWindow::on_rBt_D_clicked()
{
    this->ui->tE_hint->setText("D");
    emit rbtck_sig("D");
}

void PaperWindow::on_rBt_right_clicked()
{
    this->ui->tE_hint->setText("对");
    emit rbtck_sig("对");
}

void PaperWindow::on_rBt_false_clicked()
{
    this->ui->tE_hint->setText("错");
    emit rbtck_sig("错");
}

/**
 * 提交试卷，获取得分以及解析 考虑用数组存储答案情况
 */
void PaperWindow::on_coBt_clicked()
{
//    qint8 ansisright[20] = {1};

    if(this->index==10)
        this->myans = this->ui->tE_ans->toPlainText();
    emit this->btck_sig(0);

    for (qint8 i =0; i<11;i++) {
        this->gdres += this->ansck[i]*10;
    }
    this->newthop = false;
    th2->wait();

    this->gdwin = new GdDialog(this,this->myquery,this->gdres);
    this->gdwin->show();
}

/**
 * 退出
 */
void PaperWindow::on_doBt_clicked()
{
    this->newthop = false;
    th2->wait();
    this->close();
}
