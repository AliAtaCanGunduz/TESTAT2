#include "Street.h"
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
Street::Street(City* a, City* b) :a(a), b(b) {}
City*Street::getEnd()const {
	return a;
}
City* Street::getStart()const {
	return b;
}
double Street::getLength()const {
	int dx = a->getX() - b->getX();
    int dy = a->getY() - b->getY();
    return std::sqrt(dx * dx + dy * dy);
}
void Street::draw(QGraphicsScene& scene) const {
    if (redLineItem) {
        scene.removeItem(redLineItem);
        delete redLineItem;
        redLineItem = nullptr;
    }

	QPen pen(Qt::black);
    int x1 = a->getX() + 5;
    int y1 = a->getY() + 5;
    int x2 = b->getX() + 5;
    int y2 = b->getY() + 5;



    scene.addLine(x1, y1, x2, y2, pen);

    
    double len = getLength();
    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;
    QString label = QString::number(len, 'f', 1);

    QGraphicsTextItem* text = scene.addText(label);
    text->setPos(midX + 4, midY + 4);
}
void Street::drawRed(QGraphicsScene& scene) const {
    if (redLineItem) {
        scene.removeItem(redLineItem);
        delete redLineItem;
        redLineItem = nullptr;
    }

    QPen pen(Qt::red);
    pen.setWidth(4);
    redLineItem = scene.addLine(
        a->getX(), a->getY(),
        b->getX(), b->getY(), pen);

}