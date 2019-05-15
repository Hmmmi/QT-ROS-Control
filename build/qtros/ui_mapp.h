/********************************************************************************
** Form generated from reading UI file 'mapp.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPP_H
#define UI_MAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MAPP
{
public:
    QGroupBox *groupBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *map_button;
    QSpacerItem *horizontalSpacer;
    QPushButton *quit_button;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget2;
    QGridLayout *gridLayout_3;
    QPushButton *back_button;
    QPushButton *stop_button;
    QPushButton *forward_button;
    QPushButton *left_button;
    QPushButton *right_button;

    void setupUi(QWidget *MAPP)
    {
        if (MAPP->objectName().isEmpty())
            MAPP->setObjectName(QStringLiteral("MAPP"));
        MAPP->resize(827, 611);
        groupBox = new QGroupBox(MAPP);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 781, 581));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 520, 731, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        map_button = new QPushButton(widget);
        map_button->setObjectName(QStringLiteral("map_button"));

        horizontalLayout->addWidget(map_button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        quit_button = new QPushButton(widget);
        quit_button->setObjectName(QStringLiteral("quit_button"));

        horizontalLayout->addWidget(quit_button);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 40, 491, 467));
        verticalLayout_5 = new QVBoxLayout(widget1);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget2 = new QWidget(groupBox);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(540, 140, 211, 281));
        gridLayout_3 = new QGridLayout(widget2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        back_button = new QPushButton(widget2);
        back_button->setObjectName(QStringLiteral("back_button"));

        gridLayout_3->addWidget(back_button, 2, 1, 1, 1);

        stop_button = new QPushButton(widget2);
        stop_button->setObjectName(QStringLiteral("stop_button"));

        gridLayout_3->addWidget(stop_button, 1, 1, 1, 1);

        forward_button = new QPushButton(widget2);
        forward_button->setObjectName(QStringLiteral("forward_button"));

        gridLayout_3->addWidget(forward_button, 0, 1, 1, 1);

        left_button = new QPushButton(widget2);
        left_button->setObjectName(QStringLiteral("left_button"));

        gridLayout_3->addWidget(left_button, 1, 0, 1, 1);

        right_button = new QPushButton(widget2);
        right_button->setObjectName(QStringLiteral("right_button"));

        gridLayout_3->addWidget(right_button, 1, 2, 1, 1);

        groupBox->raise();

        retranslateUi(MAPP);

        QMetaObject::connectSlotsByName(MAPP);
    } // setupUi

    void retranslateUi(QWidget *MAPP)
    {
        MAPP->setWindowTitle(QApplication::translate("MAPP", "Form", 0));
        groupBox->setTitle(QApplication::translate("MAPP", "Mapping", 0));
        map_button->setText(QApplication::translate("MAPP", "MAPPING", 0));
        quit_button->setText(QApplication::translate("MAPP", "QUIT", 0));
        back_button->setText(QApplication::translate("MAPP", "BACK", 0));
        stop_button->setText(QApplication::translate("MAPP", "STOP", 0));
        forward_button->setText(QApplication::translate("MAPP", "FORWARD", 0));
        left_button->setText(QApplication::translate("MAPP", "LEFT", 0));
        right_button->setText(QApplication::translate("MAPP", "RIGHT", 0));
    } // retranslateUi

};

namespace Ui {
    class MAPP: public Ui_MAPP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPP_H
