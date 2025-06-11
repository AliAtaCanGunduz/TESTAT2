#ifndef BIGTOWN_H
#define BIGTOWN_H
#include "city.h"
/**
 * @class BigTown
 * @brief Repr‰sentiert eine groﬂe Stadt mit erweiterter Darstellung.
 */
class BigTown :public City {
public:
    /**
 * @brief Konstruktor.
 * @param name Name der Stadt
 * @param x X-Koordinate
 * @param y Y-Koordinate
 */

	BigTown(QString name, int x, int y) : City(name, x, y) {}
	/**
  * @brief Zeichnet die Stadt als groﬂe Stadt auf die Szene.
  */
	void draw(QGraphicsScene& scene, const AbstractMap* map)const override;
};
#endif
