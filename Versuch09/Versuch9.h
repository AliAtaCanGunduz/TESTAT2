#ifndef VERSUCH9_H
#define VERSUCH9_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <qcombobox.h>
#include "ui_Versuch9.h"
#include <QMenu>
#include <QMenuBar>

QT_BEGIN_NAMESPACE
namespace Ui { class Versuch9; }
QT_END_NAMESPACE

class Versuch9 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Versuch9(QWidget* parent = nullptr);
    ~Versuch9();

private:
    Ui::Versuch9* ui;
    QGraphicsScene* scene;
    void loadAndDrawMap(const QString& cityFile, const QString& streetFile);
    void updateCityComboBoxes();
    void testAbstractMap();
    
    QComboBox* comboStart;
    QComboBox* comboZiel;

};

#endif // VERSUCH9_H
