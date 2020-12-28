#include "mythread.h"
#include <QDebug>


MyThread::MyThread(ExamWindow *parent) : QThread(parent)
{
    this->win = parent; //获取答题窗口地址
    connect(this,SIGNAL(lcd_sig(QString)),this,SLOT(lcd_slot(QString)));  //连接信号
}

void MyThread::lcd_slot(QString timestr)
{
    this->win->lcd_getdata(timestr);
//    QString LogInfo;
//    LogInfo.sprintf("%p",QThread::currentThread());
//    qDebug() << "槽函数 " <<"threadID : "<<LogInfo;
}

void MyThread::run()
{
  qDebug()<<"线程执行";
  QString time = "20:00";
  emit lcd_sig(time);
  qint8 min,sec;
  while (time != "00:00") {
      for( min =19;min>=0 ;min--){
          for(sec=59;sec>=0;sec--){
            time[0] = min/10%10+48;
            time[1] = min%10+48;
            time[3] = sec/10%10+48;
            time[4] = sec%10+48;
            sleep(1);
//            qDebug()<<time;
            emit lcd_sig(time);

            if(this->win->newthop != true)
            {
                return;
//                break;
            }
          }
      }
  }
//  QString LogInfo;
//  LogInfo.sprintf("%p", QThread::currentThread());
//  qDebug() << "run() " <<"threadID : "<<LogInfo;
  //线程操作
  emit over();
}
