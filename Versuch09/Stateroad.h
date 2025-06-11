#ifndef STATEROAD_H
#define STATEROAD_H
#include "Street.h"
/**
 * @class Stateroad
 * @brief Repräsentiert eine Landesstraße.
 */
class Stateroad :public Street {
public:
	/**
 * @brief Konstruktor für Stateroad.
 */
	Stateroad(City* start, City* end);
	/**
 * @brief Zeichnet die Straße.
 */
	void draw(QGraphicsScene& scene)const override;
};
#endif
