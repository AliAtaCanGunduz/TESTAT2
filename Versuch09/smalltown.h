#ifndef SMALLTOWN_H
#define SMALLTOWN_H
#include "city.h"
/**
 * @class SmallTown
 * @brief Repr�sentiert eine kleine Stadt, die von City erbt.
 */
class SmallTown :public City {
public:
    /**
 * @brief Konstruktor f�r SmallTown.
 * @param name Name der Stadt.
 * @param x X-Koordinate auf der Karte.
 * @param y Y-Koordinate auf der Karte.
 */    

	SmallTown(QString name, int x, int y) : City(name, x, y) {}
    /**
  * @brief Zeichnet die Stadt auf die �bergebene Szene.
  * @param scene Die QGraphicsScene, auf die gezeichnet wird.
  * @param map Zeiger auf die zugeh�rige Karte.
  */
	void draw(QGraphicsScene& scene, const AbstractMap* map)const override;//draw to scene
};
#endif
