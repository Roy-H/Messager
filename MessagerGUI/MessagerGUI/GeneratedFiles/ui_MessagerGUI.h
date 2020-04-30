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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessagerGUIClass
{
public:
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *com_input;
    QComboBox *comboBox;
    QPushButton *com_send_btn;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *tcp_input;
    QPushButton *tcp_send_btn;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *websock_data_input;
    QPushButton *websock_server_setup;
    QPushButton *websock_send_btn;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *udp_input;
    QPushButton *udp_send_btn;
    QGroupBox *groupBox_info;

    void setupUi(QWidget *MessagerGUIClass)
    {
        if (MessagerGUIClass->objectName().isEmpty())
            MessagerGUIClass->setObjectName(QString::fromUtf8("MessagerGUIClass"));
        MessagerGUIClass->resize(919, 603);
        groupBox_5 = new QGroupBox(MessagerGUIClass);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(9, 9, 785, 332));
        horizontalLayout = new QHBoxLayout(groupBox_5);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(groupBox_5);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
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


        horizontalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(groupBox_5);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
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


        horizontalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        websock_data_input = new QTextEdit(groupBox_4);
        websock_data_input->setObjectName(QString::fromUtf8("websock_data_input"));

        verticalLayout_4->addWidget(websock_data_input);

        websock_server_setup = new QPushButton(groupBox_4);
        websock_server_setup->setObjectName(QString::fromUtf8("websock_server_setup"));

        verticalLayout_4->addWidget(websock_server_setup);

        websock_send_btn = new QPushButton(groupBox_4);
        websock_send_btn->setObjectName(QString::fromUtf8("websock_send_btn"));

        verticalLayout_4->addWidget(websock_send_btn);


        horizontalLayout->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(groupBox_5);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
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


        horizontalLayout->addWidget(groupBox_2);

        groupBox_info = new QGroupBox(MessagerGUIClass);
        groupBox_info->setObjectName(QString::fromUtf8("groupBox_info"));
        groupBox_info->setGeometry(QRect(9, 363, 901, 231));
        groupBox_info->setMinimumSize(QSize(0, 16));

        retranslateUi(MessagerGUIClass);

        QMetaObject::connectSlotsByName(MessagerGUIClass);
    } // setupUi

    void retranslateUi(QWidget *MessagerGUIClass)
    {
        MessagerGUIClass->setWindowTitle(QApplication::translate("MessagerGUIClass", "MessagerGUI", nullptr));
        groupBox_5->setTitle(QApplication::translate("MessagerGUIClass", "GroupBox", nullptr));
        groupBox->setTitle(QApplication::translate("MessagerGUIClass", "serial port", nullptr));
        comboBox->setItemText(0, QApplication::translate("MessagerGUIClass", "COM1", nullptr));
        comboBox->setItemText(1, QApplication::translate("MessagerGUIClass", "COM2", nullptr));
        comboBox->setItemText(2, QApplication::translate("MessagerGUIClass", "COM3", nullptr));
        comboBox->setItemText(3, QApplication::translate("MessagerGUIClass", "COM4", nullptr));

        com_send_btn->setText(QApplication::translate("MessagerGUIClass", "\345\217\221\351\200\201", nullptr));
        groupBox_3->setTitle(QApplication::translate("MessagerGUIClass", "tcp", nullptr));
        tcp_send_btn->setText(QApplication::translate("MessagerGUIClass", "send", nullptr));
        groupBox_4->setTitle(QApplication::translate("MessagerGUIClass", "websocket", nullptr));
        websock_data_input->setDocumentTitle(QString());
        websock_data_input->setPlaceholderText(QApplication::translate("MessagerGUIClass", "input data here", nullptr));
        websock_server_setup->setText(QApplication::translate("MessagerGUIClass", "setup", nullptr));
        websock_send_btn->setText(QApplication::translate("MessagerGUIClass", "send", nullptr));
        groupBox_2->setTitle(QApplication::translate("MessagerGUIClass", "udp", nullptr));
        udp_send_btn->setText(QApplication::translate("MessagerGUIClass", "send", nullptr));
        groupBox_info->setTitle(QApplication::translate("MessagerGUIClass", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessagerGUIClass: public Ui_MessagerGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGERGUI_H
