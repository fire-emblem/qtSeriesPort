/********************************************************************************
** Form generated from reading UI file 'mtdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MTDLG_H
#define UI_MTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_mtDlg
{
public:
    QHBoxLayout *horizontalLayout;
    QCustomPlot *qCustomPlot;
    QWidget *widget;
    QFormLayout *formLayout;
    QPushButton *butShowWZSD;
    QPushButton *pushButton;
    QPushButton *butShowIaIb;

    void setupUi(QDialog *mtDlg)
    {
        if (mtDlg->objectName().isEmpty())
            mtDlg->setObjectName(QStringLiteral("mtDlg"));
        mtDlg->resize(907, 474);
        horizontalLayout = new QHBoxLayout(mtDlg);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        qCustomPlot = new QCustomPlot(mtDlg);
        qCustomPlot->setObjectName(QStringLiteral("qCustomPlot"));
        widget = new QWidget(qCustomPlot);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(670, 10, 83, 95));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        butShowWZSD = new QPushButton(widget);
        butShowWZSD->setObjectName(QStringLiteral("butShowWZSD"));

        formLayout->setWidget(0, QFormLayout::LabelRole, butShowWZSD);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(3, QFormLayout::LabelRole, pushButton);

        butShowIaIb = new QPushButton(widget);
        butShowIaIb->setObjectName(QStringLiteral("butShowIaIb"));

        formLayout->setWidget(2, QFormLayout::LabelRole, butShowIaIb);


        horizontalLayout->addWidget(qCustomPlot);


        retranslateUi(mtDlg);

        QMetaObject::connectSlotsByName(mtDlg);
    } // setupUi

    void retranslateUi(QDialog *mtDlg)
    {
        mtDlg->setWindowTitle(QApplication::translate("mtDlg", "Dialog", 0));
        butShowWZSD->setText(QApplication::translate("mtDlg", "\344\275\215\347\275\256/\351\200\237\345\272\246", 0));
        pushButton->setText(QApplication::translate("mtDlg", "\345\201\234\346\255\242", 0));
        butShowIaIb->setText(QApplication::translate("mtDlg", "Ia/Ib", 0));
    } // retranslateUi

};

namespace Ui {
    class mtDlg: public Ui_mtDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MTDLG_H
