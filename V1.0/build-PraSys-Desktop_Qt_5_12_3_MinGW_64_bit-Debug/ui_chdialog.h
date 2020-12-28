/********************************************************************************
** Form generated from reading UI file 'chdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHDIALOG_H
#define UI_CHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChDialog
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *exBt;
    QPushButton *papBt;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *ChDialog)
    {
        if (ChDialog->objectName().isEmpty())
            ChDialog->setObjectName(QString::fromUtf8("ChDialog"));
        ChDialog->resize(636, 452);
        gridLayout_2 = new QGridLayout(ChDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        exBt = new QPushButton(ChDialog);
        exBt->setObjectName(QString::fromUtf8("exBt"));
        exBt->setMinimumSize(QSize(300, 120));
        exBt->setMaximumSize(QSize(300, 120));
        QFont font;
        font.setPointSize(26);
        exBt->setFont(font);

        gridLayout->addWidget(exBt, 0, 1, 1, 1);

        papBt = new QPushButton(ChDialog);
        papBt->setObjectName(QString::fromUtf8("papBt"));
        papBt->setMinimumSize(QSize(300, 120));
        papBt->setMaximumSize(QSize(300, 120));
        papBt->setFont(font);

        gridLayout->addWidget(papBt, 3, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ChDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(ChDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        label_2 = new QLabel(ChDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        gridLayout->addLayout(verticalLayout, 3, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::FieldRole, gridLayout);


        gridLayout_2->addLayout(formLayout, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 1, 1, 1);


        retranslateUi(ChDialog);

        QMetaObject::connectSlotsByName(ChDialog);
    } // setupUi

    void retranslateUi(QDialog *ChDialog)
    {
        ChDialog->setWindowTitle(QApplication::translate("ChDialog", "\347\263\273\347\273\237\351\200\211\346\213\251", nullptr));
        exBt->setText(QApplication::translate("ChDialog", "\347\273\203\344\271\240\347\263\273\347\273\237", nullptr));
        papBt->setText(QApplication::translate("ChDialog", "\350\200\203\350\257\225\347\263\273\347\273\237", nullptr));
        label->setText(QApplication::translate("ChDialog", "\350\257\267\350\276\223\345\205\245\347\253\240\350\212\202", nullptr));
        label_2->setText(QApplication::translate("ChDialog", "1,2,3 \346\210\226 1-3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChDialog: public Ui_ChDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHDIALOG_H
