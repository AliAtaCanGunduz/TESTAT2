#ifndef STATEROAD_H
#define STATEROAD_H
#include "Street.h"
/**
 * @class Stateroad
 * @brief Repr�sentiert eine Landesstra�e.
 */
class Stateroad :public Street {
public:
	/**
 * @brief Konstruktor f�r Stateroad.
 */
	Stateroad(City* start, City* end);
	/**
 * @brief Zeichnet die Stra�e.
 */
	void draw(QGraphicsScene& scene)const override;
};
#endif
