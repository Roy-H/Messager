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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessagerGUIClass
{
public:

    void setupUi(QWidget *MessagerGUIClass)
    {
        if (MessagerGUIClass->objectName().isEmpty())
            MessagerGUIClass->setObjectName(QString::fromUtf8("MessagerGUIClass"));
        MessagerGUIClass->resize(600, 400);

        retranslateUi(MessagerGUIClass);

        QMetaObject::connectSlotsByName(MessagerGUIClass);
    } // setupUi

    void retranslateUi(QWidget *MessagerGUIClass)
    {
        MessagerGUIClass->setWindowTitle(QApplication::translate("MessagerGUIClass", "MessagerGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MessagerGUIClass: public Ui_MessagerGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGERGUI_H
