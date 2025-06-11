#ifndef SMALLTOWN_H
#define SMALLTOWN_H
#include "city.h"
/**
 * @class SmallTown
 * @brief Repräsentiert eine kleine Stadt, die von City erbt.
 */
class SmallTown :public City {
public:
    /**
 * @brief Konstruktor für SmallTown.
 * @param name Name der Stadt.
 * @param x X-Koordinate auf der Karte.
 * @param y Y-Koordinate auf der Karte.
 */    

	SmallTown(QString name, int x, int y) : City(name, x, y) {}
    /**
  * @brief Zeichnet die Stadt auf die übergebene Szene.
  * @param scene Die QGraphicsScene, auf die gezeichnet wird.
  * @param map Zeiger auf die zugehörige Karte.
  */
	void draw(QGraphicsScene& scene, const AbstractMap* map)const override;//draw to scene
};
#endif
