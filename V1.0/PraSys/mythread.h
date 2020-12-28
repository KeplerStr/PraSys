#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include "examwindow.h"

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(ExamWindow *parent = nullptr);

    void run();

signals:
    void over();
    void lcd_sig(QString timestr);

public slots:
    void lcd_slot(QString timestr);

private:
    ExamWindow *win;
};

#endif // MYTHREAD_H
