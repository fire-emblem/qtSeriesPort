/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *edtSendText;
    QGroupBox *groupBox;
    QPushButton *butOpenSerialPort;
    QLabel *label;
    QComboBox *cmbSerialPortName;
    QSplitter *splitter_2;
    QLabel *label_2;
    QComboBox *cmbBaudRate;
    QSplitter *splitter_3;
    QLabel *label_3;
    QComboBox *cmbDatabit;
    QSplitter *splitter_4;
    QLabel *label_4;
    QComboBox *cmbVeritybit;
    QSplitter *splitter_5;
    QLabel *label_5;
    QComboBox *cmbStopbit;
    QGroupBox *groupBox_2;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *lblSerialPortStatus;
    QLabel *lblSendNum;
    QLabel *lblReceiveNum;
    QPushButton *butClearNum;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *edtSendCycle;
    QCheckBox *chkAutoSend;
    QPushButton *butClearSendText;
    QPushButton *butSendData;
    QCheckBox *chkSendHex;
    QFrame *line1;
    QPushButton *butAbout;
    QPushButton *butExit;
    QPushButton *butDataresolve;
    QPushButton *butDatashow;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_3;
    QComboBox *cmbCircle;
    QComboBox *cmbPI;
    QLineEdit *edtNum;
    QLabel *label_15;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *butControl;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_40;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_41;
    QLineEdit *edtShowPp;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_42;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_43;
    QLineEdit *edtShowVp;
    QLabel *label_46;
    QLineEdit *edtShowVi;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_44;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_45;
    QLineEdit *edtShowIp;
    QLabel *label_47;
    QLineEdit *edtShowIi;
    QWidget *tab_2;
    QGroupBox *groupBox_5;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLineEdit *edtEsoalf1;
    QLineEdit *edtEsoalf2;
    QLineEdit *edtEsoalf3;
    QLineEdit *edtEsobeta1;
    QLineEdit *edtEsobeta2;
    QLineEdit *edtEsobeta3;
    QGroupBox *groupBox_4;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *edtR;
    QLineEdit *edtT;
    QLineEdit *edtH;
    QLineEdit *edtD;
    QLineEdit *edtB;
    QPushButton *butADRCcontrol;
    QGroupBox *groupBox_6;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLineEdit *edtNLSEF_alfa1;
    QLineEdit *edtNLSEF_alfa2;
    QLineEdit *edtNLSEF_beta1;
    QLineEdit *edtNLSEF_beta2;
    QLabel *label_23;
    QScrollBar *horizontalScrollBar;
    QFrame *line1_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_39;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_34;
    QPushButton *butMoveOn;
    QPushButton *butMoveClose;
    QLineEdit *edtShowMove;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_22;
    QPushButton *butPID;
    QPushButton *butADRC;
    QLineEdit *edtShowcontrol;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_21;
    QPushButton *butSeriOn;
    QPushButton *butSeriClose;
    QLineEdit *edtShowseri;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_36;
    QLineEdit *edtShowWZ;
    QLabel *label_35;
    QLineEdit *edtShowSD;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_37;
    QLineEdit *edtShowId;
    QLabel *label_38;
    QLineEdit *edtShowIq;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(962, 529);
        QIcon icon;
        icon.addFile(QStringLiteral(":/files/image/19.ICO"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setAnimated(true);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        edtSendText = new QTextEdit(centralWidget);
        edtSendText->setObjectName(QStringLiteral("edtSendText"));
        edtSendText->setGeometry(QRect(180, 40, 361, 131));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 141, 201));
        butOpenSerialPort = new QPushButton(groupBox);
        butOpenSerialPort->setObjectName(QStringLiteral("butOpenSerialPort"));
        butOpenSerialPort->setGeometry(QRect(40, 170, 75, 23));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 60, 16));
        cmbSerialPortName = new QComboBox(groupBox);
        cmbSerialPortName->setObjectName(QStringLiteral("cmbSerialPortName"));
        cmbSerialPortName->setGeometry(QRect(73, 20, 64, 20));
        splitter_2 = new QSplitter(groupBox);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(20, 50, 117, 20));
        splitter_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_2->addWidget(label_2);
        cmbBaudRate = new QComboBox(splitter_2);
        cmbBaudRate->setObjectName(QStringLiteral("cmbBaudRate"));
        splitter_2->addWidget(cmbBaudRate);
        splitter_3 = new QSplitter(groupBox);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(20, 80, 117, 20));
        splitter_3->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_3->addWidget(label_3);
        cmbDatabit = new QComboBox(splitter_3);
        cmbDatabit->setObjectName(QStringLiteral("cmbDatabit"));
        splitter_3->addWidget(cmbDatabit);
        splitter_4 = new QSplitter(groupBox);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setGeometry(QRect(20, 110, 117, 20));
        splitter_4->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_4->addWidget(label_4);
        cmbVeritybit = new QComboBox(splitter_4);
        cmbVeritybit->setObjectName(QStringLiteral("cmbVeritybit"));
        splitter_4->addWidget(cmbVeritybit);
        splitter_5 = new QSplitter(groupBox);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setGeometry(QRect(20, 140, 117, 20));
        splitter_5->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(splitter_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter_5->addWidget(label_5);
        cmbStopbit = new QComboBox(splitter_5);
        cmbStopbit->setObjectName(QStringLiteral("cmbStopbit"));
        splitter_5->addWidget(cmbStopbit);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 220, 151, 151));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 30, 54, 12));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 60, 54, 12));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 90, 54, 12));
        lblSerialPortStatus = new QLabel(groupBox_2);
        lblSerialPortStatus->setObjectName(QStringLiteral("lblSerialPortStatus"));
        lblSerialPortStatus->setGeometry(QRect(80, 30, 54, 12));
        lblSendNum = new QLabel(groupBox_2);
        lblSendNum->setObjectName(QStringLiteral("lblSendNum"));
        lblSendNum->setGeometry(QRect(80, 60, 54, 12));
        lblReceiveNum = new QLabel(groupBox_2);
        lblReceiveNum->setObjectName(QStringLiteral("lblReceiveNum"));
        lblReceiveNum->setGeometry(QRect(80, 90, 54, 12));
        butClearNum = new QPushButton(groupBox_2);
        butClearNum->setObjectName(QStringLiteral("butClearNum"));
        butClearNum->setGeometry(QRect(14, 120, 121, 23));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(180, 10, 60, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(370, 10, 48, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(490, 10, 24, 16));
        edtSendCycle = new QLineEdit(centralWidget);
        edtSendCycle->setObjectName(QStringLiteral("edtSendCycle"));
        edtSendCycle->setEnabled(true);
        edtSendCycle->setGeometry(QRect(424, 10, 61, 20));
        edtSendCycle->setAlignment(Qt::AlignCenter);
        chkAutoSend = new QCheckBox(centralWidget);
        chkAutoSend->setObjectName(QStringLiteral("chkAutoSend"));
        chkAutoSend->setGeometry(QRect(245, 10, 71, 16));
        butClearSendText = new QPushButton(centralWidget);
        butClearSendText->setObjectName(QStringLiteral("butClearSendText"));
        butClearSendText->setGeometry(QRect(350, 180, 75, 23));
        butSendData = new QPushButton(centralWidget);
        butSendData->setObjectName(QStringLiteral("butSendData"));
        butSendData->setGeometry(QRect(450, 180, 75, 23));
        chkSendHex = new QCheckBox(centralWidget);
        chkSendHex->setObjectName(QStringLiteral("chkSendHex"));
        chkSendHex->setGeometry(QRect(180, 180, 71, 16));
        line1 = new QFrame(centralWidget);
        line1->setObjectName(QStringLiteral("line1"));
        line1->setGeometry(QRect(170, 200, 371, 31));
        line1->setFrameShape(QFrame::HLine);
        line1->setFrameShadow(QFrame::Sunken);
        butAbout = new QPushButton(centralWidget);
        butAbout->setObjectName(QStringLiteral("butAbout"));
        butAbout->setGeometry(QRect(10, 380, 61, 23));
        butExit = new QPushButton(centralWidget);
        butExit->setObjectName(QStringLiteral("butExit"));
        butExit->setGeometry(QRect(100, 380, 61, 23));
        butDataresolve = new QPushButton(centralWidget);
        butDataresolve->setObjectName(QStringLiteral("butDataresolve"));
        butDataresolve->setGeometry(QRect(230, 410, 91, 21));
        butDatashow = new QPushButton(centralWidget);
        butDatashow->setObjectName(QStringLiteral("butDatashow"));
        butDatashow->setGeometry(QRect(340, 410, 101, 23));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(560, 20, 401, 391));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QLatin1String("background-color:rgb(176,196,222);\n"
"color:red;\n"
"\n"
""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 20, 151, 151));
        cmbCircle = new QComboBox(groupBox_3);
        cmbCircle->setObjectName(QStringLiteral("cmbCircle"));
        cmbCircle->setGeometry(QRect(60, 30, 71, 20));
        cmbPI = new QComboBox(groupBox_3);
        cmbPI->setObjectName(QStringLiteral("cmbPI"));
        cmbPI->setGeometry(QRect(60, 60, 71, 20));
        edtNum = new QLineEdit(groupBox_3);
        edtNum->setObjectName(QStringLiteral("edtNum"));
        edtNum->setGeometry(QRect(60, 90, 71, 20));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 30, 41, 16));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 60, 41, 16));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 90, 41, 16));
        butControl = new QPushButton(groupBox_3);
        butControl->setObjectName(QStringLiteral("butControl"));
        butControl->setGeometry(QRect(30, 120, 101, 23));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 30, 175, 170));
        verticalLayout_8 = new QVBoxLayout(layoutWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_40 = new QLabel(layoutWidget);
        label_40->setObjectName(QStringLiteral("label_40"));

        horizontalLayout_8->addWidget(label_40);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_41 = new QLabel(layoutWidget);
        label_41->setObjectName(QStringLiteral("label_41"));

        horizontalLayout_9->addWidget(label_41);

        edtShowPp = new QLineEdit(layoutWidget);
        edtShowPp->setObjectName(QStringLiteral("edtShowPp"));

        horizontalLayout_9->addWidget(edtShowPp);

        horizontalSpacer_4 = new QSpacerItem(90, 17, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_9);


        verticalLayout_8->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_42 = new QLabel(layoutWidget);
        label_42->setObjectName(QStringLiteral("label_42"));

        horizontalLayout_10->addWidget(label_42);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_43 = new QLabel(layoutWidget);
        label_43->setObjectName(QStringLiteral("label_43"));

        horizontalLayout_11->addWidget(label_43);

        edtShowVp = new QLineEdit(layoutWidget);
        edtShowVp->setObjectName(QStringLiteral("edtShowVp"));

        horizontalLayout_11->addWidget(edtShowVp);

        label_46 = new QLabel(layoutWidget);
        label_46->setObjectName(QStringLiteral("label_46"));

        horizontalLayout_11->addWidget(label_46);

        edtShowVi = new QLineEdit(layoutWidget);
        edtShowVi->setObjectName(QStringLiteral("edtShowVi"));

        horizontalLayout_11->addWidget(edtShowVi);


        verticalLayout_6->addLayout(horizontalLayout_11);


        verticalLayout_8->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_44 = new QLabel(layoutWidget);
        label_44->setObjectName(QStringLiteral("label_44"));

        horizontalLayout_12->addWidget(label_44);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_3);


        verticalLayout_7->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_45 = new QLabel(layoutWidget);
        label_45->setObjectName(QStringLiteral("label_45"));

        horizontalLayout_13->addWidget(label_45);

        edtShowIp = new QLineEdit(layoutWidget);
        edtShowIp->setObjectName(QStringLiteral("edtShowIp"));

        horizontalLayout_13->addWidget(edtShowIp);

        label_47 = new QLabel(layoutWidget);
        label_47->setObjectName(QStringLiteral("label_47"));

        horizontalLayout_13->addWidget(label_47);

        edtShowIi = new QLineEdit(layoutWidget);
        edtShowIi->setObjectName(QStringLiteral("edtShowIi"));

        horizontalLayout_13->addWidget(edtShowIi);


        verticalLayout_7->addLayout(horizontalLayout_13);


        verticalLayout_8->addLayout(verticalLayout_7);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(200, 10, 201, 211));
        label_24 = new QLabel(groupBox_5);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 20, 61, 16));
        label_25 = new QLabel(groupBox_5);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(10, 50, 61, 16));
        label_26 = new QLabel(groupBox_5);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(10, 80, 61, 16));
        label_27 = new QLabel(groupBox_5);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(10, 110, 61, 16));
        label_28 = new QLabel(groupBox_5);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(10, 140, 61, 16));
        label_29 = new QLabel(groupBox_5);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(10, 170, 61, 16));
        edtEsoalf1 = new QLineEdit(groupBox_5);
        edtEsoalf1->setObjectName(QStringLiteral("edtEsoalf1"));
        edtEsoalf1->setGeometry(QRect(80, 20, 91, 20));
        edtEsoalf2 = new QLineEdit(groupBox_5);
        edtEsoalf2->setObjectName(QStringLiteral("edtEsoalf2"));
        edtEsoalf2->setGeometry(QRect(80, 50, 91, 20));
        edtEsoalf3 = new QLineEdit(groupBox_5);
        edtEsoalf3->setObjectName(QStringLiteral("edtEsoalf3"));
        edtEsoalf3->setGeometry(QRect(80, 80, 91, 20));
        edtEsobeta1 = new QLineEdit(groupBox_5);
        edtEsobeta1->setObjectName(QStringLiteral("edtEsobeta1"));
        edtEsobeta1->setGeometry(QRect(80, 110, 91, 20));
        edtEsobeta2 = new QLineEdit(groupBox_5);
        edtEsobeta2->setObjectName(QStringLiteral("edtEsobeta2"));
        edtEsobeta2->setGeometry(QRect(80, 140, 91, 20));
        edtEsobeta3 = new QLineEdit(groupBox_5);
        edtEsobeta3->setObjectName(QStringLiteral("edtEsobeta3"));
        edtEsobeta3->setGeometry(QRect(80, 170, 91, 20));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 10, 201, 211));
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 20, 61, 16));
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 50, 61, 16));
        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 80, 61, 16));
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 110, 61, 16));
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(10, 140, 61, 16));
        edtR = new QLineEdit(groupBox_4);
        edtR->setObjectName(QStringLiteral("edtR"));
        edtR->setGeometry(QRect(80, 20, 91, 20));
        edtT = new QLineEdit(groupBox_4);
        edtT->setObjectName(QStringLiteral("edtT"));
        edtT->setGeometry(QRect(80, 50, 91, 20));
        edtH = new QLineEdit(groupBox_4);
        edtH->setObjectName(QStringLiteral("edtH"));
        edtH->setGeometry(QRect(80, 80, 91, 20));
        edtD = new QLineEdit(groupBox_4);
        edtD->setObjectName(QStringLiteral("edtD"));
        edtD->setGeometry(QRect(80, 110, 91, 20));
        edtB = new QLineEdit(groupBox_4);
        edtB->setObjectName(QStringLiteral("edtB"));
        edtB->setGeometry(QRect(80, 140, 91, 20));
        butADRCcontrol = new QPushButton(groupBox_4);
        butADRCcontrol->setObjectName(QStringLiteral("butADRCcontrol"));
        butADRCcontrol->setGeometry(QRect(50, 180, 111, 23));
        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 230, 201, 131));
        label_30 = new QLabel(groupBox_6);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(10, 20, 71, 16));
        label_31 = new QLabel(groupBox_6);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(10, 50, 71, 16));
        label_32 = new QLabel(groupBox_6);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(10, 80, 71, 16));
        label_33 = new QLabel(groupBox_6);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(10, 110, 71, 16));
        edtNLSEF_alfa1 = new QLineEdit(groupBox_6);
        edtNLSEF_alfa1->setObjectName(QStringLiteral("edtNLSEF_alfa1"));
        edtNLSEF_alfa1->setGeometry(QRect(90, 20, 91, 20));
        edtNLSEF_alfa2 = new QLineEdit(groupBox_6);
        edtNLSEF_alfa2->setObjectName(QStringLiteral("edtNLSEF_alfa2"));
        edtNLSEF_alfa2->setGeometry(QRect(90, 50, 91, 20));
        edtNLSEF_beta1 = new QLineEdit(groupBox_6);
        edtNLSEF_beta1->setObjectName(QStringLiteral("edtNLSEF_beta1"));
        edtNLSEF_beta1->setGeometry(QRect(90, 80, 91, 20));
        edtNLSEF_beta2 = new QLineEdit(groupBox_6);
        edtNLSEF_beta2->setObjectName(QStringLiteral("edtNLSEF_beta2"));
        edtNLSEF_beta2->setGeometry(QRect(90, 110, 91, 20));
        tabWidget->addTab(tab_2, QString());
        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(260, 370, 61, 31));
        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(330, 380, 121, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        line1_2 = new QFrame(centralWidget);
        line1_2->setObjectName(QStringLiteral("line1_2"));
        line1_2->setGeometry(QRect(170, 270, 371, 31));
        line1_2->setFrameShape(QFrame::HLine);
        line1_2->setFrameShadow(QFrame::Sunken);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(170, 290, 381, 91));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_39 = new QLabel(layoutWidget1);
        label_39->setObjectName(QStringLiteral("label_39"));

        verticalLayout_2->addWidget(label_39);

        verticalSpacer = new QSpacerItem(20, 55, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_34 = new QLabel(layoutWidget1);
        label_34->setObjectName(QStringLiteral("label_34"));

        horizontalLayout->addWidget(label_34);

        butMoveOn = new QPushButton(layoutWidget1);
        butMoveOn->setObjectName(QStringLiteral("butMoveOn"));

        horizontalLayout->addWidget(butMoveOn);

        butMoveClose = new QPushButton(layoutWidget1);
        butMoveClose->setObjectName(QStringLiteral("butMoveClose"));

        horizontalLayout->addWidget(butMoveClose);

        edtShowMove = new QLineEdit(layoutWidget1);
        edtShowMove->setObjectName(QStringLiteral("edtShowMove"));

        horizontalLayout->addWidget(edtShowMove);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_22 = new QLabel(layoutWidget1);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_2->addWidget(label_22);

        butPID = new QPushButton(layoutWidget1);
        butPID->setObjectName(QStringLiteral("butPID"));

        horizontalLayout_2->addWidget(butPID);

        butADRC = new QPushButton(layoutWidget1);
        butADRC->setObjectName(QStringLiteral("butADRC"));

        horizontalLayout_2->addWidget(butADRC);

        edtShowcontrol = new QLineEdit(layoutWidget1);
        edtShowcontrol->setObjectName(QStringLiteral("edtShowcontrol"));

        horizontalLayout_2->addWidget(edtShowcontrol);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_21 = new QLabel(layoutWidget1);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_3->addWidget(label_21);

        butSeriOn = new QPushButton(layoutWidget1);
        butSeriOn->setObjectName(QStringLiteral("butSeriOn"));

        horizontalLayout_3->addWidget(butSeriOn);

        butSeriClose = new QPushButton(layoutWidget1);
        butSeriClose->setObjectName(QStringLiteral("butSeriClose"));

        horizontalLayout_3->addWidget(butSeriClose);

        edtShowseri = new QLineEdit(layoutWidget1);
        edtShowseri->setObjectName(QStringLiteral("edtShowseri"));

        horizontalLayout_3->addWidget(edtShowseri);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(170, 220, 381, 67));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QStringLiteral("label_9"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(label_9);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_7->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_36 = new QLabel(layoutWidget2);
        label_36->setObjectName(QStringLiteral("label_36"));

        horizontalLayout_4->addWidget(label_36);

        edtShowWZ = new QLineEdit(layoutWidget2);
        edtShowWZ->setObjectName(QStringLiteral("edtShowWZ"));

        horizontalLayout_4->addWidget(edtShowWZ);

        label_35 = new QLabel(layoutWidget2);
        label_35->setObjectName(QStringLiteral("label_35"));

        horizontalLayout_4->addWidget(label_35);

        edtShowSD = new QLineEdit(layoutWidget2);
        edtShowSD->setObjectName(QStringLiteral("edtShowSD"));

        horizontalLayout_4->addWidget(edtShowSD);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(7, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        label_37 = new QLabel(layoutWidget2);
        label_37->setObjectName(QStringLiteral("label_37"));

        horizontalLayout_5->addWidget(label_37);

        edtShowId = new QLineEdit(layoutWidget2);
        edtShowId->setObjectName(QStringLiteral("edtShowId"));

        horizontalLayout_5->addWidget(edtShowId);

        label_38 = new QLabel(layoutWidget2);
        label_38->setObjectName(QStringLiteral("label_38"));

        horizontalLayout_5->addWidget(label_38);

        edtShowIq = new QLineEdit(layoutWidget2);
        edtShowIq->setObjectName(QStringLiteral("edtShowIq"));

        horizontalLayout_5->addWidget(edtShowIq);


        verticalLayout_4->addLayout(horizontalLayout_5);


        horizontalLayout_7->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 962, 23));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\220\214\346\265\216\345\244\247\345\255\246\347\224\265\346\234\272\350\260\203\350\257\225", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        butOpenSerialPort->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        label->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\344\270\262\345\217\243\357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", 0));
        label_5->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\351\200\232\350\256\257\347\212\266\346\200\201", 0));
        label_10->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\347\212\266\346\200\201\357\274\232", 0));
        label_11->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\255\227\350\212\202\357\274\232", 0));
        label_12->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\345\255\227\350\212\202\357\274\232", 0));
        lblSerialPortStatus->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        lblSendNum->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        lblReceiveNum->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        butClearNum->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\350\256\241\346\225\260(\346\226\207\344\273\266)", 0));
        label_6->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\255\227\347\254\246\357\274\232", 0));
        label_7->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\221\250\346\234\237", 0));
        label_8->setText(QApplication::translate("MainWindow", "\346\257\253\347\247\222", 0));
        edtSendCycle->setText(QString());
        chkAutoSend->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\217\221\351\200\201", 0));
        butClearSendText->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\346\230\276\347\244\272", 0));
        butSendData->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\345\217\221\351\200\201", 0));
        chkSendHex->setText(QApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266", 0));
        butAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
        butExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        butDataresolve->setText(QApplication::translate("MainWindow", "\346\225\260 \346\215\256 \345\244\204 \347\220\206", 0));
        butDatashow->setText(QApplication::translate("MainWindow", "\345\233\276\345\275\242\346\230\276\347\244\272", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\347\224\265\346\234\272\346\216\247\345\210\266", 0));
        edtNum->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "   \347\216\257\357\274\232", 0));
        label_13->setText(QApplication::translate("MainWindow", "   PI\357\274\232", 0));
        label_14->setText(QApplication::translate("MainWindow", "   \345\200\274\357\274\232", 0));
        butControl->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220PI\346\216\247\345\210\266\345\255\227", 0));
        label_40->setText(QApplication::translate("MainWindow", "\344\275\215\347\275\256\347\216\257\357\274\232", 0));
        label_41->setText(QApplication::translate("MainWindow", "P\357\274\232", 0));
        label_42->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246\347\216\257\357\274\232", 0));
        label_43->setText(QApplication::translate("MainWindow", "P\357\274\232", 0));
        label_46->setText(QApplication::translate("MainWindow", "I\357\274\232", 0));
        label_44->setText(QApplication::translate("MainWindow", "\347\224\265\346\265\201\347\216\257\357\274\232", 0));
        label_45->setText(QApplication::translate("MainWindow", "P\357\274\232", 0));
        label_47->setText(QApplication::translate("MainWindow", "I\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "PI", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "ESO", 0));
        label_24->setText(QApplication::translate("MainWindow", "ESO_alfa1\357\274\232", 0));
        label_25->setText(QApplication::translate("MainWindow", "ESO_alfa2\357\274\232", 0));
        label_26->setText(QApplication::translate("MainWindow", "ESO_alfa3\357\274\232", 0));
        label_27->setText(QApplication::translate("MainWindow", "ESO_beta1\357\274\232", 0));
        label_28->setText(QApplication::translate("MainWindow", "ESO_beta2\357\274\232", 0));
        label_29->setText(QApplication::translate("MainWindow", "ESO_beta3\357\274\232", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\350\207\252\346\212\227\346\211\260", 0));
        label_16->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\345\260\272\345\272\246r\357\274\232", 0));
        label_17->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\345\270\270\346\225\260T\357\274\232", 0));
        label_18->setText(QApplication::translate("MainWindow", "\346\255\245\351\225\277h\357\274\232", 0));
        label_19->setText(QApplication::translate("MainWindow", "\347\272\277\346\200\247\345\214\272\351\227\264d\357\274\232", 0));
        label_20->setText(QApplication::translate("MainWindow", "\345\242\236\347\233\212b\357\274\232", 0));
        butADRCcontrol->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\350\207\252\346\212\227\346\211\260\346\216\247\345\210\266\345\255\227", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "NLSEF", 0));
        label_30->setText(QApplication::translate("MainWindow", "NLSEF_alfa1", 0));
        label_31->setText(QApplication::translate("MainWindow", "NLSEF_alfa2", 0));
        label_32->setText(QApplication::translate("MainWindow", "NLSEF_beta1", 0));
        label_33->setText(QApplication::translate("MainWindow", "NLSEF_beta2", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "ADRC", 0));
        label_23->setText(QApplication::translate("MainWindow", "\350\277\220\345\212\250\351\200\237\345\272\246\357\274\232", 0));
        label_39->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\350\277\220\350\241\214\346\216\247\345\210\266\357\274\232</span></p></body></html>", 0));
        label_34->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\350\277\220\345\212\250\357\274\232", 0));
        butMoveOn->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250", 0));
        butMoveClose->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0));
        label_22->setText(QApplication::translate("MainWindow", "\346\216\247\345\210\266\346\250\241\345\274\217\357\274\232", 0));
        butPID->setText(QApplication::translate("MainWindow", "PID", 0));
        butADRC->setText(QApplication::translate("MainWindow", "ADRC", 0));
        label_21->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\344\275\277\350\203\275\357\274\232", 0));
        butSeriOn->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250", 0));
        butSeriClose->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\347\224\265\346\234\272\347\212\266\346\200\201\357\274\232</span></p></body></html>", 0));
        label_36->setText(QApplication::translate("MainWindow", "\344\275\215\347\275\256\357\274\232", 0));
        label_35->setText(QApplication::translate("MainWindow", "\350\275\254\351\200\237\357\274\232", 0));
        label_37->setText(QApplication::translate("MainWindow", " Id\357\274\232", 0));
        label_38->setText(QApplication::translate("MainWindow", "  Iq\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
