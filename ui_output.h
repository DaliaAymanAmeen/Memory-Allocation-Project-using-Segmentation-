/********************************************************************************
** Form generated from reading UI file 'output.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUT_H
#define UI_OUTPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_output
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *add_process;
    QRadioButton *Best_Fit;
    QRadioButton *first_fit;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *add_seg;
    QLineEdit *process_name;
    QLineEdit *seg_number;
    QLineEdit *segment_name;
    QLineEdit *seg_size;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QDialog *output)
    {
        if (output->objectName().isEmpty())
            output->setObjectName(QString::fromUtf8("output"));
        output->resize(1200, 680);
        groupBox = new QGroupBox(output);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 351, 411));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 100, 131, 41));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 170, 161, 16));
        add_process = new QPushButton(groupBox);
        add_process->setObjectName(QString::fromUtf8("add_process"));
        add_process->setGeometry(QRect(180, 360, 141, 28));
        Best_Fit = new QRadioButton(groupBox);
        Best_Fit->setObjectName(QString::fromUtf8("Best_Fit"));
        Best_Fit->setGeometry(QRect(20, 40, 95, 20));
        first_fit = new QRadioButton(groupBox);
        first_fit->setObjectName(QString::fromUtf8("first_fit"));
        first_fit->setGeometry(QRect(190, 40, 95, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 230, 111, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 270, 131, 20));
        add_seg = new QPushButton(groupBox);
        add_seg->setObjectName(QString::fromUtf8("add_seg"));
        add_seg->setGeometry(QRect(20, 310, 93, 28));
        process_name = new QLineEdit(groupBox);
        process_name->setObjectName(QString::fromUtf8("process_name"));
        process_name->setGeometry(QRect(190, 101, 113, 31));
        seg_number = new QLineEdit(groupBox);
        seg_number->setObjectName(QString::fromUtf8("seg_number"));
        seg_number->setGeometry(QRect(190, 160, 113, 31));
        segment_name = new QLineEdit(groupBox);
        segment_name->setObjectName(QString::fromUtf8("segment_name"));
        segment_name->setGeometry(QRect(190, 220, 113, 31));
        seg_size = new QLineEdit(groupBox);
        seg_size->setObjectName(QString::fromUtf8("seg_size"));
        seg_size->setGeometry(QRect(190, 270, 113, 41));
        widget = new QWidget(output);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 500, 351, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(output);

        QMetaObject::connectSlotsByName(output);
    } // setupUi

    void retranslateUi(QDialog *output)
    {
        output->setWindowTitle(QCoreApplication::translate("output", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("output", "Allocation", nullptr));
        label->setText(QCoreApplication::translate("output", "Process Name", nullptr));
        label_2->setText(QCoreApplication::translate("output", "Number of  Segmentations", nullptr));
        add_process->setText(QCoreApplication::translate("output", "Add Process", nullptr));
        Best_Fit->setText(QCoreApplication::translate("output", "Best_Fit", nullptr));
        first_fit->setText(QCoreApplication::translate("output", "First_Fit", nullptr));
        label_3->setText(QCoreApplication::translate("output", "Segment name", nullptr));
        label_4->setText(QCoreApplication::translate("output", "Size of Segment", nullptr));
        add_seg->setText(QCoreApplication::translate("output", "Add", nullptr));
        pushButton->setText(QCoreApplication::translate("output", "De_allocate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class output: public Ui_output {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUT_H
