#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>
#include "examwindow.h"

QString MainWindow::name_ext = "";
QString MainWindow::stunum_ext = "";

//窗体的构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->hostName = "localhost";   // 主机名
    this->dbName = "prasysdb";   // 数据库名称
    this->userName = "root";   // 用户名
    this->password = "1024";   // 密码

    this->db = QSqlDatabase::addDatabase("QMYSQL");
    this->db.setHostName(hostName);
    this->db.setDatabaseName(dbName);
    this->db.setUserName(userName);
    this->db.setPassword(password);

    qDebug("database open status: %d\n", db.open()); //.open()连接成功返回值为1
    this->setFocusPolicy(Qt::StrongFocus);
}

//窗体的析构函数
MainWindow::~MainWindow()
{
    this->db.close();
    delete ui;
}

/**
 * 登录打开界面窗口
 */
void MainWindow::login_open_newWin()
{
//    ew = new ExamWindow(this,&this->db);//将类指针实例化
//    ew->show();
//    papwin = new PaperWindow(this,&this->db);
//    papwin->show();
    chwin = new ChDialog(this,&this->db);
    chwin->show();
    this->hide();   //登录界面隐藏
}

/**
 * 键盘事件
 */
void MainWindow::keyPressEvent(QKeyEvent *ev){

    //qDebug()<<ev->key();
    switch (ev->key()) {
    case Qt::Key_Enter-1:   //比键盘Enter值大1，我也不知道为什么
    {
        emit this->ui->loginBt->clicked(true);
        break;
    }
    default:
        break;
    }
}



/**
 * 登录按键槽函数
 */
void MainWindow::on_loginBt_clicked()
{
    QString accout = this->ui->lineEdit_account->text();
    if(accout.isEmpty())      //判断用户名
    {
        QMessageBox::information(this, "提示", "请输入用户名");
        qDebug()<<"用户名不能为空";
        return;
    }
    else {
        qDebug()<<accout;
        QSqlQuery query = QSqlQuery( this->db );
        query.prepare("select * from student where binary user_name=?");//准备sql语句
        query.bindValue(0,QVariant(accout));                            //填充sql语句
        bool success = query.exec();
        if(!success)
        {
            qDebug()<<"查询失败";return;
        }

        QSqlRecord rec = query.record();
        qDebug()<<"sudent表的字段总数:"<<rec.count();
        query.seek(-1);

        query.next();
        QString cur_password = query.value(2).toString();//数据库里面的密码
        if(cur_password.isEmpty())
        {
            QMessageBox::information(this, "提示", "此用户不存在，请重新注册");
            qDebug()<<"没有找到这个用户";
            return;
        }

        QString user_pw = this->ui->lineEdit_password->text();//输入的密码

        if(user_pw.isEmpty())
        {
            QMessageBox::information(this, "提示", "输入密码");
            qDebug()<<"请输入密码";
            return;
        }else{
            if(user_pw == cur_password)
            {
                MainWindow::name_ext = accout;      //全局用户名
                MainWindow::stunum_ext = query.value(3).toString();//全局学号

                QMessageBox::information(this, "提示", "登录成功");
                qDebug()<<"登录成功";
                login_open_newWin();
            }
            else
            {
                QMessageBox::information(this, "提示", "密码错误");
                qDebug()<<"密码错误";
            }

        }
    }

//    query.seek(-1);
//    while (query.next()) {//遍历数据表
//        qDebug()<<query.value(0)<<query.value(1)<<query.value(2);
//    }


//    QSqlQueryModel *model_name = new QSqlQueryModel;
//    model_name->setQuery(QString("select COLUMN_NAME from information_schema.COLUMNS where table_name = 'test' and table_schema = 'user_name'"));
//    QModelIndex index_name = model_name->index(2,0);    //n行1列
//    qDebug()<<model_name->data(index_name).toString();
}

/**
 * 注册按键槽函数
 */
void MainWindow::on_regBt_clicked()
{
    QSqlQuery query = QSqlQuery( this->db );
    query.prepare("insert into student (id,user_name,password) values (?,?,?)");
    if(this->ui->lineEdit_account->text().isEmpty() || this->ui->lineEdit_password->text().isEmpty())
    {
        return;
    }else {

        query.bindValue(0,NULL);       //id主键插入null，自增
        query.bindValue(1,this->ui->lineEdit_account->text());
        query.bindValue(2,this->ui->lineEdit_password->text());
        bool success = query.exec();
        if(success)
        {
            QMessageBox::information(this, "提示", "注册成功");
            qDebug()<<"注册成功";
        }
    }
}
