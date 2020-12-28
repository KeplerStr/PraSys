#include "mythread2.h"
#include <QDebug>

Mythread2::Mythread2(PaperWindow *parent) : QThread(parent)
{
    this->win = parent; //获取答题窗口地址
    connect(this,SIGNAL(lcd_sig(QString)),this,SLOT(lcd_slot(QString)));  //连接信号
}

void Mythread2::lcd_slot(QString timestr)
{
    this->win->lcdGetData(timestr);
}

void Mythread2::run()
{
  qDebug()<<"线程执行";
  QString time = "1:00:00";
  emit lcd_sig(time);
  qint8 min,sec;
  while (time != "0:00:00") {
      for( min =59;min>=0 ;min--){
          for(sec=59;sec>=0;sec--){

            time[0] = 0+48;
            time[2] = min/10%10+48;
            time[3] = min%10+48;

            time[5] = sec/10%10+48;
            time[6] = sec%10+48;
            sleep(1);
            emit lcd_sig(time);
            if(this->win->newthop != true)
            {
                return;
            }
          }
      }
  }
  emit over();
}
