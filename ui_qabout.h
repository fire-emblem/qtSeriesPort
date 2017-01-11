/********************************************************************************
** Form generated from reading UI file 'qabout.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QABOUT_H
#define UI_QABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_qAbout
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *qAbout)
    {
        if (qAbout->objectName().isEmpty())
            qAbout->setObjectName(QStringLiteral("qAbout"));
        qAbout->setWindowModality(Qt::NonModal);
        qAbout->resize(233, 153);
        buttonBox = new QDialogButtonBox(qAbout);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(100, 110, 121, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        label = new QLabel(qAbout);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 20, 61, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(qAbout);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 111, 16));
        label_3 = new QLabel(qAbout);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 90, 121, 16));
        label_4 = new QLabel(qAbout);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 60, 161, 16));
        label_5 = new QLabel(qAbout);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 90, 111, 16));

        retranslateUi(qAbout);
        QObject::connect(buttonBox, SIGNAL(accepted()), qAbout, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), qAbout, SLOT(reject()));

        QMetaObject::connectSlotsByName(qAbout);
    } // setupUi

    void retranslateUi(QDialog *qAbout)
    {
        label->setText(QApplication::translate("qAbout", "\345\205\263\344\272\216", 0));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QApplication::translate("qAbout", "\345\220\214\346\265\216\345\244\247\345\255\246\347\224\265\345\255\220\344\270\216\344\277\241\346\201\257\345\267\245\347\250\213\345\255\246\351\231\242", 0));
        label_5->setText(QApplication::translate("qAbout", "\350\207\252\346\212\227\346\211\260\347\224\265\346\234\272\346\216\247\345\210\266", 0));
        Q_UNUSED(qAbout);
    } // retranslateUi

};

namespace Ui {
    class qAbout: public Ui_qAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QABOUT_H
