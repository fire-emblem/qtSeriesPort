/********************************************************************************
** Form generated from reading UI file 'wzsd.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WZSD_H
#define UI_WZSD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_WZSD
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *showwin;

    void setupUi(QDialog *WZSD)
    {
        if (WZSD->objectName().isEmpty())
            WZSD->setObjectName(QStringLiteral("WZSD"));
        WZSD->resize(669, 447);
        verticalLayout = new QVBoxLayout(WZSD);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        showwin = new QCustomPlot(WZSD);
        showwin->setObjectName(QStringLiteral("showwin"));

        verticalLayout->addWidget(showwin);


        retranslateUi(WZSD);

        QMetaObject::connectSlotsByName(WZSD);
    } // setupUi

    void retranslateUi(QDialog *WZSD)
    {
        WZSD->setWindowTitle(QApplication::translate("WZSD", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class WZSD: public Ui_WZSD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WZSD_H
