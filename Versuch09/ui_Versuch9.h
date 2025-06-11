/********************************************************************************
** Form generated from reading UI file 'Versuch9.ui'
**
** Created manually since uic could not be run directly.
********************************************************************************/

#ifndef UI_VERSUCH9_H
#define UI_VERSUCH9_H

#include <QtCore/QVariant>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

namespace Ui {
class Versuch9;
}

class Ui_Versuch9
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *Versuch9)
    {
        if (Versuch9->objectName().isEmpty())
            Versuch9->setObjectName("Versuch9");
        Versuch9->resize(800, 600);
        centralWidget = new QWidget(Versuch9);
        verticalLayout = new QVBoxLayout(centralWidget);
        graphicsView = new QGraphicsView(centralWidget);
        verticalLayout->addWidget(graphicsView);
        Versuch9->setCentralWidget(centralWidget);
    }
};

namespace Ui {
    class Versuch9: public Ui_Versuch9 {};
}

QT_END_NAMESPACE

#endif // UI_VERSUCH9_H
