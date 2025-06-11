#ifndef MOTORWAY_H
#define MOTORWAY_H
#include "Street.h"
/**
 * @class Motorway
 * @brief Repräsentiert eine Autobahn.
 */
class Motorway :public Street {

public:
	/**
* @brief Konstruktor für Motorway.
*/
	Motorway(City* start, City* end);
	/**
  * @brief Zeichnet die Autobahn auf der Szene.
  */
	void draw(QGraphicsScene& scene)const override;
	/**
	* @brief Zeichnet die Autobahn in Rot.
	 */
		


};
#endif
