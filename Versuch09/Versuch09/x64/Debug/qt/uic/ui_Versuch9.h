/********************************************************************************
** Form generated from reading UI file 'Versuch9.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSUCH9_H
#define UI_VERSUCH9_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Versuch9Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Versuch9Class)
    {
        if (Versuch9Class->objectName().isEmpty())
            Versuch9Class->setObjectName("Versuch9Class");
        Versuch9Class->resize(600, 400);
        centralWidget = new QWidget(Versuch9Class);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        Versuch9Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Versuch9Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        Versuch9Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Versuch9Class);
        mainToolBar->setObjectName("mainToolBar");
        Versuch9Class->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Versuch9Class);
        statusBar->setObjectName("statusBar");
        Versuch9Class->setStatusBar(statusBar);

        retranslateUi(Versuch9Class);

        QMetaObject::connectSlotsByName(Versuch9Class);
    } // setupUi

    void retranslateUi(QMainWindow *Versuch9Class)
    {
        Versuch9Class->setWindowTitle(QCoreApplication::translate("Versuch9Class", "Versuch9", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Versuch9Class: public Ui_Versuch9Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSUCH9_H
