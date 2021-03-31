/********************************************************************************
** Form generated from reading UI file 'interfacewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACEWIDGET_H
#define UI_INTERFACEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceWidget
{
public:

    void setupUi(QWidget *InterfaceWidget)
    {
        if (InterfaceWidget->objectName().isEmpty())
            InterfaceWidget->setObjectName(QString::fromUtf8("InterfaceWidget"));
        InterfaceWidget->resize(300, 300);

        retranslateUi(InterfaceWidget);

        QMetaObject::connectSlotsByName(InterfaceWidget);
    } // setupUi

    void retranslateUi(QWidget *InterfaceWidget)
    {
        InterfaceWidget->setWindowTitle(QCoreApplication::translate("InterfaceWidget", "My program :)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InterfaceWidget: public Ui_InterfaceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACEWIDGET_H
