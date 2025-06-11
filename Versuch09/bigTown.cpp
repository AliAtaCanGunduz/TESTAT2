#include "bigtown.h"
#include <qgraphicsitem.h>

/**
 * @brief Zeichnet die große Stadt mit größerem Kreis.
 */
void BigTown::draw(QGraphicsScene& scene, const AbstractMap* map) const {
    scene.addEllipse(x - 5, y - 5, 15, 15, QPen(Qt::black), QBrush(Qt::darkCyan));


    QGraphicsTextItem* text = scene.addText(name);


    text->setPos(x + 7, y - 7);
    text->setZValue(1);

    QFont font("Arial");
    font.setPointSize(8);
    text->setFont(font);

}