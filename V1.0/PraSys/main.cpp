#include "mainwindow.h"
#include "examwindow.h"
#include "paperwindow.h"

#include <QApplication>

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QSqlError>
#include <QDebug>

#include <QSqlDatabase>

#include <QMessageBox>
#include <QTextStream>
#include <stdio.h>

//bool createConnection()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("localhost");
//    db.setDatabaseName("test");
//    db.setPort(3306);
//    db.setUserName("root");
//    db.setPassword("1024");
//    bool ok = db.open();
//    if (ok)
//    {
//        qDebug() << "连接成功" ;
//        return true;
//    }
//    else
//    {
//        qDebug() << "连接失败" ;
//        return false;
//    }
//}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow login;
    login.show();

//    PaperWindow ppwin;
//    ppwin.show();

    return a.exec();
}
