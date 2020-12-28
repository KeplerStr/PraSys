#ifndef MYTHREAD2_H
#define MYTHREAD2_H
#include <QThread>
#include "gddialog.h"
#include "paperwindow.h"

class Mythread2 : public QThread
{
    Q_OBJECT
public:
    explicit Mythread2(PaperWindow *parent = nullptr);
    void run();

signals:
    void over();
    void lcd_sig(QString timestr);

public slots:
    void lcd_slot(QString timestr);

private:
    PaperWindow *win;
};

#endif // MYTHREAD2_H
