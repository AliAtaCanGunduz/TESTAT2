#include "Stateroad.h"
#include <qpen.h>
#include <QGraphicsTextItem>
/**
 * @brief Konstruktor für Landesstraße.
 */
Stateroad::Stateroad(City* start, City* end) :Street(start, end) {}
/**
 * @brief Zeichnet mit gestrichelter grüner Linie.
 */
void Stateroad::draw(QGraphicsScene& scene)const {
    if (redLineItem) {
        scene.removeItem(redLineItem);
        delete redLineItem;
        redLineItem = nullptr;
    }
    int x1 = getStart()->getX() + 5;
    int y1 = getStart()->getY() + 5;
    int x2 = getEnd()->getX() + 5;
    int y2 = getEnd()->getY() + 5;

    QPen bluePen(Qt::blue);
    bluePen.setWidth(3);

    scene.addLine(x1, y1, x2, y2, bluePen);

    double len = getLength();
    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;

    QString label = QString::number(len, 'f', 1);
    QGraphicsTextItem* text = scene.addText(label);
    text->setPos(midX + 5, midY - 15); 
    QFont font;
    font.setPointSize(7);
    text->setFont(font);
}