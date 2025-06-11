#ifndef STREET_H
#define STREET_H
#include "city.h"
/**
 * @class Street
 * @brief Repräsentiert eine Straße zwischen zwei Städten.
 */
class Street {
public:
	/**
 * @brief Konstruktor für eine Straße zwischen zwei Städten.
 * @param a Zeiger auf die Startstadt.
 * @param b Zeiger auf die Zielstadt.
 */
	Street(City* a, City* b);
	/**
 * @brief Gibt die Startstadt zurück.
 * @return Zeiger auf die Startstadt.
 */
	City* getStart()const;
	/**
 * @brief Gibt die Zielstadt zurück.
 * @return Zeiger auf die Zielstadt.
 */
	City* getEnd()const;
	/**
	* @brief Zeichnet die Straße auf die übergebene Szene.
	* @param scene Die QGraphicsScene, auf die gezeichnet wird.
	*/
	virtual void draw(QGraphicsScene& scene)const;
	/**
 * @brief Gibt die Länge der Straße zurück.
 * @return Länge als double.
 */
	double getLength()const;
	/**
	* @brief Zeichnet die Straße in Rot, z.B. für die Visualisierung von Pfaden.
	* @param scene Die QGraphicsScene, auf die gezeichnet wird.
	*/
	virtual void drawRed(QGraphicsScene& scene) const;
protected:
	City* a;
	City* b;
	mutable QGraphicsLineItem* redLineItem = nullptr;  // red çizim için
	
};

#endif

