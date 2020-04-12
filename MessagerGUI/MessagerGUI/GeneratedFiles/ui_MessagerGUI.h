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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessagerGUIClass
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QComboBox *comboBox;

    void setupUi(QWidget *MessagerGUIClass)
    {
        if (MessagerGUIClass->objectName().isEmpty())
            MessagerGUIClass->setObjectName(QString::fromUtf8("MessagerGUIClass"));
        MessagerGUIClass->resize(600, 400);
        lineEdit = new QLineEdit(MessagerGUIClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(230, 100, 113, 22));
        pushButton = new QPushButton(MessagerGUIClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 320, 93, 28));
        comboBox = new QComboBox(MessagerGUIClass);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(250, 210, 73, 22));

        retranslateUi(MessagerGUIClass);

        QMetaObject::connectSlotsByName(MessagerGUIClass);
    } // setupUi

    void retranslateUi(QWidget *MessagerGUIClass)
    {
        MessagerGUIClass->setWindowTitle(QApplication::translate("MessagerGUIClass", "MessagerGUI", nullptr));
        pushButton->setText(QApplication::translate("MessagerGUIClass", "\345\217\221\351\200\201", nullptr));
        comboBox->setItemText(0, QApplication::translate("MessagerGUIClass", "COM1", nullptr));
        comboBox->setItemText(1, QApplication::translate("MessagerGUIClass", "COM2", nullptr));
        comboBox->setItemText(2, QApplication::translate("MessagerGUIClass", "COM3", nullptr));
        comboBox->setItemText(3, QApplication::translate("MessagerGUIClass", "COM4", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MessagerGUIClass: public Ui_MessagerGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGERGUI_H
