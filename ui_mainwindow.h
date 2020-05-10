/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *submit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_6;
    QLineEdit *holes_starting_address;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_7;
    QLineEdit *holes_size;
    QPushButton *pushButton_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QLineEdit *total_size;
    QPushButton *add_total_size;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        submit = new QPushButton(centralwidget);
        submit->setObjectName(QString::fromUtf8("submit"));
        submit->setGeometry(QRect(380, 350, 181, 31));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(320, 30, 301, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_2->addWidget(pushButton_6);

        holes_starting_address = new QLineEdit(layoutWidget);
        holes_starting_address->setObjectName(QString::fromUtf8("holes_starting_address"));

        horizontalLayout_2->addWidget(holes_starting_address);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_3->addWidget(pushButton_7);

        holes_size = new QLineEdit(layoutWidget);
        holes_size->setObjectName(QString::fromUtf8("holes_size"));

        horizontalLayout_3->addWidget(holes_size);


        verticalLayout->addLayout(horizontalLayout_3);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 40, 171, 211));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        total_size = new QLineEdit(layoutWidget1);
        total_size->setObjectName(QString::fromUtf8("total_size"));

        verticalLayout_3->addWidget(total_size);

        add_total_size = new QPushButton(layoutWidget1);
        add_total_size->setObjectName(QString::fromUtf8("add_total_size"));

        verticalLayout_3->addWidget(add_total_size);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        submit->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Holes", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Starting Address", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Total Memory Size", nullptr));
        add_total_size->setText(QCoreApplication::translate("MainWindow", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
