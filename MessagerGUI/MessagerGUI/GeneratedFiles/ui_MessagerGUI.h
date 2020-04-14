/********************************************************************************
** Form generated from reading UI file 'MessagerGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGERGUI_H
#define UI_MESSAGERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessagerGUIClass
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *com_input;
    QComboBox *comboBox;
    QPushButton *com_send_btn;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *udp_input;
    QPushButton *udp_send_btn;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *tcp_input;
    QPushButton *tcp_send_btn;

    void setupUi(QWidget *MessagerGUIClass)
    {
        if (MessagerGUIClass->objectName().isEmpty())
            MessagerGUIClass->setObjectName(QString::fromUtf8("MessagerGUIClass"));
        MessagerGUIClass->resize(600, 400);
        groupBox = new QGroupBox(MessagerGUIClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 157, 120));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        com_input = new QLineEdit(groupBox);
        com_input->setObjectName(QString::fromUtf8("com_input"));

        verticalLayout->addWidget(com_input);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        com_send_btn = new QPushButton(groupBox);
        com_send_btn->setObjectName(QString::fromUtf8("com_send_btn"));

        verticalLayout->addWidget(com_send_btn);

        groupBox_2 = new QGroupBox(MessagerGUIClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(220, 30, 221, 101));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        udp_input = new QLineEdit(groupBox_2);
        udp_input->setObjectName(QString::fromUtf8("udp_input"));

        verticalLayout_2->addWidget(udp_input);

        udp_send_btn = new QPushButton(groupBox_2);
        udp_send_btn->setObjectName(QString::fromUtf8("udp_send_btn"));

        verticalLayout_2->addWidget(udp_send_btn);

        groupBox_3 = new QGroupBox(MessagerGUIClass);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 190, 191, 111));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tcp_input = new QLineEdit(groupBox_3);
        tcp_input->setObjectName(QString::fromUtf8("tcp_input"));

        verticalLayout_3->addWidget(tcp_input);

        tcp_send_btn = new QPushButton(groupBox_3);
        tcp_send_btn->setObjectName(QString::fromUtf8("tcp_send_btn"));

        verticalLayout_3->addWidget(tcp_send_btn);


        retranslateUi(MessagerGUIClass);

        QMetaObject::connectSlotsByName(MessagerGUIClass);
    } // setupUi

    void retranslateUi(QWidget *MessagerGUIClass)
    {
        MessagerGUIClass->setWindowTitle(QApplication::translate("MessagerGUIClass", "MessagerGUI", nullptr));
        groupBox->setTitle(QApplication::translate("MessagerGUIClass", "serial port", nullptr));
        comboBox->setItemText(0, QApplication::translate("MessagerGUIClass", "COM1", nullptr));
        comboBox->setItemText(1, QApplication::translate("MessagerGUIClass", "COM2", nullptr));
        comboBox->setItemText(2, QApplication::translate("MessagerGUIClass", "COM3", nullptr));
        comboBox->setItemText(3, QApplication::translate("MessagerGUIClass", "COM4", nullptr));

        com_send_btn->setText(QApplication::translate("MessagerGUIClass", "\345\217\221\351\200\201", nullptr));
        groupBox_2->setTitle(QApplication::translate("MessagerGUIClass", "udp", nullptr));
        udp_send_btn->setText(QApplication::translate("MessagerGUIClass", "send", nullptr));
        groupBox_3->setTitle(QApplication::translate("MessagerGUIClass", "tcp", nullptr));
        tcp_send_btn->setText(QApplication::translate("MessagerGUIClass", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessagerGUIClass: public Ui_MessagerGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGERGUI_H
