/********************************************************************************
** Form generated from reading UI file 'manual_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUAL_DIALOG_H
#define UI_MANUAL_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_manualdialog
{
public:
    QPushButton *up;
    QPushButton *left;
    QPushButton *right;
    QPushButton *down;
    QPushButton *back;

    void setupUi(QDialog *manualdialog)
    {
        if (manualdialog->objectName().isEmpty())
            manualdialog->setObjectName(QStringLiteral("manualdialog"));
        manualdialog->resize(400, 300);
        up = new QPushButton(manualdialog);
        up->setObjectName(QStringLiteral("up"));
        up->setGeometry(QRect(160, 50, 80, 26));
        left = new QPushButton(manualdialog);
        left->setObjectName(QStringLiteral("left"));
        left->setGeometry(QRect(70, 90, 80, 26));
        right = new QPushButton(manualdialog);
        right->setObjectName(QStringLiteral("right"));
        right->setGeometry(QRect(250, 90, 80, 26));
        down = new QPushButton(manualdialog);
        down->setObjectName(QStringLiteral("down"));
        down->setGeometry(QRect(160, 130, 80, 26));
        back = new QPushButton(manualdialog);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(280, 250, 80, 26));

        retranslateUi(manualdialog);

        QMetaObject::connectSlotsByName(manualdialog);
    } // setupUi

    void retranslateUi(QDialog *manualdialog)
    {
        manualdialog->setWindowTitle(QApplication::translate("manualdialog", "Dialog", 0));
        up->setText(QApplication::translate("manualdialog", "UP", 0));
        left->setText(QApplication::translate("manualdialog", "LEFT", 0));
        right->setText(QApplication::translate("manualdialog", "RIGHT", 0));
        down->setText(QApplication::translate("manualdialog", "DOWN", 0));
        back->setText(QApplication::translate("manualdialog", "BACK", 0));
    } // retranslateUi

};

namespace Ui {
    class manualdialog: public Ui_manualdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUAL_DIALOG_H
