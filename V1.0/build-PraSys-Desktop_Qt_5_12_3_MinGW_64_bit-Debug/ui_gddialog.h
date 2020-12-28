/********************************************************************************
** Form generated from reading UI file 'gddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GDDIALOG_H
#define UI_GDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GdDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_gd;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QTextEdit *tE_ans;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GdDialog)
    {
        if (GdDialog->objectName().isEmpty())
            GdDialog->setObjectName(QString::fromUtf8("GdDialog"));
        GdDialog->resize(456, 446);
        gridLayout_2 = new QGridLayout(GdDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(GdDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_gd = new QLabel(GdDialog);
        label_gd->setObjectName(QString::fromUtf8("label_gd"));
        QFont font1;
        font1.setPointSize(18);
        label_gd->setFont(font1);
        label_gd->setLayoutDirection(Qt::LeftToRight);
        label_gd->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_gd->setFrameShadow(QFrame::Plain);
        label_gd->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_gd);

        label_3 = new QLabel(GdDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setPointSize(20);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(GdDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout_2->addWidget(label_4);

        tE_ans = new QTextEdit(GdDialog);
        tE_ans->setObjectName(QString::fromUtf8("tE_ans"));
        QFont font3;
        font3.setPointSize(12);
        tE_ans->setFont(font3);

        verticalLayout_2->addWidget(tE_ans);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(GdDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(GdDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), GdDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GdDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GdDialog);
    } // setupUi

    void retranslateUi(QDialog *GdDialog)
    {
        GdDialog->setWindowTitle(QApplication::translate("GdDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("GdDialog", "\344\275\240\347\232\204\346\210\220\347\273\251", nullptr));
        label_gd->setText(QApplication::translate("GdDialog", "80\345\210\206", nullptr));
        label_3->setText(QApplication::translate("GdDialog", "\350\257\267\347\273\247\347\273\255\345\212\240\346\262\271\357\274\201\357\274\201\357\274\201", nullptr));
        label_4->setText(QApplication::translate("GdDialog", "\345\217\202\350\200\203\347\255\224\346\241\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GdDialog: public Ui_GdDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GDDIALOG_H
