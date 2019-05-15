/********************************************************************************
** Form generated from reading UI file 'romap.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROMAP_H
#define UI_ROMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoMap
{
public:
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *display_button;
    QSpacerItem *horizontalSpacer;
    QPushButton *quit_button;

    void setupUi(QWidget *RoMap)
    {
        if (RoMap->objectName().isEmpty())
            RoMap->setObjectName(QStringLiteral("RoMap"));
        RoMap->resize(768, 517);
        groupBox = new QGroupBox(RoMap);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 721, 481));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 40, 681, 421));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        display_button = new QPushButton(verticalLayoutWidget);
        display_button->setObjectName(QStringLiteral("display_button"));

        horizontalLayout_2->addWidget(display_button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        quit_button = new QPushButton(verticalLayoutWidget);
        quit_button->setObjectName(QStringLiteral("quit_button"));

        horizontalLayout_2->addWidget(quit_button);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 7);
        verticalLayout->setStretch(1, 3);
        groupBox->raise();

        retranslateUi(RoMap);

        QMetaObject::connectSlotsByName(RoMap);
    } // setupUi

    void retranslateUi(QWidget *RoMap)
    {
        RoMap->setWindowTitle(QApplication::translate("RoMap", "Form", 0));
        groupBox->setTitle(QApplication::translate("RoMap", "GroupBox", 0));
        display_button->setText(QApplication::translate("RoMap", "DISPLAY", 0));
        quit_button->setText(QApplication::translate("RoMap", "QUIT", 0));
    } // retranslateUi

};

namespace Ui {
    class RoMap: public Ui_RoMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROMAP_H
