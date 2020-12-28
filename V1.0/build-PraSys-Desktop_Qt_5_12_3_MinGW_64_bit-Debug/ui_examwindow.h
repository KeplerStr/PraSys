/********************************************************************************
** Form generated from reading UI file 'examwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMWINDOW_H
#define UI_EXAMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QTextBrowser *textBrowser_que;
    QSpacerItem *horizontalSpacer;
    QLabel *label_7;
    QTextBrowser *textBrowser_solve;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pgupBt;
    QPushButton *pgdnBt;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_8;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QComboBox *hardcBox;
    QComboBox *qscBox;
    QLineEdit *chapter_lineEdit;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *filtrateBt;
    QPushButton *analysisBt;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_9;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QLabel *label_6;
    QTextBrowser *textBrowser_ans;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ExamWindow)
    {
        if (ExamWindow->objectName().isEmpty())
            ExamWindow->setObjectName(QString::fromUtf8("ExamWindow"));
        ExamWindow->resize(800, 600);
        centralwidget = new QWidget(ExamWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(16);
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        textBrowser_que = new QTextBrowser(centralwidget);
        textBrowser_que->setObjectName(QString::fromUtf8("textBrowser_que"));
        QFont font1;
        font1.setPointSize(14);
        textBrowser_que->setFont(font1);
        textBrowser_que->setReadOnly(true);

        verticalLayout->addWidget(textBrowser_que);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout->addWidget(label_7);

        textBrowser_solve = new QTextBrowser(centralwidget);
        textBrowser_solve->setObjectName(QString::fromUtf8("textBrowser_solve"));
        textBrowser_solve->setFont(font1);
        textBrowser_solve->setReadOnly(false);

        verticalLayout->addWidget(textBrowser_solve);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pgupBt = new QPushButton(centralwidget);
        pgupBt->setObjectName(QString::fromUtf8("pgupBt"));
        pgupBt->setFont(font1);

        horizontalLayout_4->addWidget(pgupBt);

        pgdnBt = new QPushButton(centralwidget);
        pgdnBt->setObjectName(QString::fromUtf8("pgdnBt"));
        pgdnBt->setFont(font1);

        horizontalLayout_4->addWidget(pgdnBt);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        verticalLayout_5->addWidget(label_8);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        hardcBox = new QComboBox(centralwidget);
        hardcBox->addItem(QString());
        hardcBox->addItem(QString());
        hardcBox->addItem(QString());
        hardcBox->addItem(QString());
        hardcBox->setObjectName(QString::fromUtf8("hardcBox"));
        QFont font2;
        font2.setPointSize(12);
        font2.setKerning(true);
        hardcBox->setFont(font2);

        verticalLayout_3->addWidget(hardcBox);

        qscBox = new QComboBox(centralwidget);
        qscBox->addItem(QString());
        qscBox->addItem(QString());
        qscBox->addItem(QString());
        qscBox->setObjectName(QString::fromUtf8("qscBox"));
        QFont font3;
        font3.setPointSize(12);
        qscBox->setFont(font3);

        verticalLayout_3->addWidget(qscBox);

        chapter_lineEdit = new QLineEdit(centralwidget);
        chapter_lineEdit->setObjectName(QString::fromUtf8("chapter_lineEdit"));
        chapter_lineEdit->setFont(font1);

        verticalLayout_3->addWidget(chapter_lineEdit);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_4->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        filtrateBt = new QPushButton(centralwidget);
        filtrateBt->setObjectName(QString::fromUtf8("filtrateBt"));
        filtrateBt->setFont(font);

        horizontalLayout_2->addWidget(filtrateBt);

        analysisBt = new QPushButton(centralwidget);
        analysisBt->setObjectName(QString::fromUtf8("analysisBt"));
        analysisBt->setFont(font);

        horizontalLayout_2->addWidget(analysisBt);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        horizontalLayout_5->addWidget(label_9);

        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(100, 40));
        QFont font4;
        font4.setPointSize(20);
        lcdNumber->setFont(font4);
        lcdNumber->setLineWidth(1);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(8);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        lcdNumber->setProperty("intValue", QVariant(0));

        horizontalLayout_5->addWidget(lcdNumber);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        verticalLayout_5->addWidget(label_6);

        textBrowser_ans = new QTextBrowser(centralwidget);
        textBrowser_ans->setObjectName(QString::fromUtf8("textBrowser_ans"));
        textBrowser_ans->setFont(font1);

        verticalLayout_5->addWidget(textBrowser_ans);


        horizontalLayout_3->addLayout(verticalLayout_5);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        ExamWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ExamWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        ExamWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ExamWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ExamWindow->setStatusBar(statusbar);

        retranslateUi(ExamWindow);

        QMetaObject::connectSlotsByName(ExamWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ExamWindow)
    {
        ExamWindow->setWindowTitle(QApplication::translate("ExamWindow", "\345\255\246\347\224\237\347\273\203\344\271\240\347\225\214\351\235\242", nullptr));
#ifndef QT_NO_TOOLTIP
        ExamWindow->setToolTip(QApplication::translate("ExamWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("ExamWindow", "\351\227\256\351\242\230\345\214\272", nullptr));
        label_7->setText(QApplication::translate("ExamWindow", "\350\247\243\347\255\224\345\214\272", nullptr));
        pgupBt->setText(QApplication::translate("ExamWindow", "\344\270\212\344\270\200\351\242\230", nullptr));
        pgdnBt->setText(QApplication::translate("ExamWindow", "\344\270\213\344\270\200\351\242\230", nullptr));
        label_8->setText(QApplication::translate("ExamWindow", "\350\256\276\347\275\256\345\214\272", nullptr));
        label->setText(QApplication::translate("ExamWindow", "\351\232\276\345\272\246", nullptr));
        label_2->setText(QApplication::translate("ExamWindow", "\351\242\230\345\236\213", nullptr));
        label_3->setText(QApplication::translate("ExamWindow", "\347\253\240\350\212\202", nullptr));
        hardcBox->setItemText(0, QApplication::translate("ExamWindow", "\351\232\217\346\234\272", nullptr));
        hardcBox->setItemText(1, QApplication::translate("ExamWindow", "\351\232\276\345\272\246\344\270\200", nullptr));
        hardcBox->setItemText(2, QApplication::translate("ExamWindow", "\351\232\276\345\272\246\344\272\214", nullptr));
        hardcBox->setItemText(3, QApplication::translate("ExamWindow", "\351\232\276\345\272\246\344\270\211", nullptr));

        qscBox->setItemText(0, QApplication::translate("ExamWindow", "\351\200\211\346\213\251\351\242\230", nullptr));
        qscBox->setItemText(1, QApplication::translate("ExamWindow", "\345\241\253\347\251\272\351\242\230", nullptr));
        qscBox->setItemText(2, QApplication::translate("ExamWindow", "\345\256\242\350\247\202\351\242\230", nullptr));

        label_4->setText(QApplication::translate("ExamWindow", "\346\240\274\345\274\217:1-3\346\210\2261,2,3", nullptr));
        filtrateBt->setText(QApplication::translate("ExamWindow", "\347\255\233\351\200\211", nullptr));
        analysisBt->setText(QApplication::translate("ExamWindow", "\350\247\243\346\236\220", nullptr));
        label_9->setText(QApplication::translate("ExamWindow", "\346\227\266\351\227\264", nullptr));
        label_6->setText(QApplication::translate("ExamWindow", "\347\255\224\346\241\210\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamWindow: public Ui_ExamWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMWINDOW_H
