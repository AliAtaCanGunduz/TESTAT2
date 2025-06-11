#include "smalltown.h"
#include <qgraphicsitem.h>
void SmallTown::draw(QGraphicsScene& scene, const AbstractMap* map) const {
    scene.addEllipse(x - 5, y - 5, 10, 10, QPen(Qt::black), QBrush(Qt::darkYellow));


    QGraphicsTextItem* text = scene.addText(name);


    text->setPos(x + 7, y - 7);
    text->setZValue(1);

    QFont font("Arial");
    font.setPointSize(8);
    text->setFont(font);

}