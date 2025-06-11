#include "city.h"
#include "Street.h"          
#include "abstractmap.h"     
#include <cmath>
#include <QRandomGenerator>
#include<QGraphicsEllipseItem>
#include<QGraphicsTextItem>
/**
 * @brief Konstruktor für City.
 */
City::City(QString name, int x, int y) :name(name), x(x), y(y) {};//Konstruktor
/**
 * @brief Zeichnet die Stadt als Kreis mit Text.
 */
void City::draw(QGraphicsScene& scene, const AbstractMap* map) const {
    scene.addEllipse(x - 5, y - 5, 10, 10, QPen(Qt::black),QBrush(Qt::white));

    
    QGraphicsTextItem* text = scene.addText(name);

    
    text->setPos(x + 7, y - 7); 
    text->setZValue(1); 

    QFont font("Arial");
    font.setPointSize(8);
    text->setFont(font);

}
/**
 * @brief Gibt die X-Koordinate zurück.
 */
int City::getX()const {
	return x;

}
/**
 * @brief Gibt die Y-Koordinate zurück.
 */
int City :: getY()const {
	return y;
}
/**
 * @brief Gibt den Namen zurück.
 */
QString City::getname()const {
	return name;
}
double City::operator-(const City& other) const {
    int dx = x - other.getX();
    int dy = y - other.getY();
    return std::sqrt(dx * dx + dy * dy);
}
