#ifndef STREET_H
#define STREET_H
#include "city.h"
/**
 * @class Street
 * @brief Repr�sentiert eine Stra�e zwischen zwei St�dten.
 */
class Street {
public:
	/**
 * @brief Konstruktor f�r eine Stra�e zwischen zwei St�dten.
 * @param a Zeiger auf die Startstadt.
 * @param b Zeiger auf die Zielstadt.
 */
	Street(City* a, City* b);
	/**
 * @brief Gibt die Startstadt zur�ck.
 * @return Zeiger auf die Startstadt.
 */
	City* getStart()const;
	/**
 * @brief Gibt die Zielstadt zur�ck.
 * @return Zeiger auf die Zielstadt.
 */
	City* getEnd()const;
	/**
	* @brief Zeichnet die Stra�e auf die �bergebene Szene.
	* @param scene Die QGraphicsScene, auf die gezeichnet wird.
	*/
	virtual void draw(QGraphicsScene& scene)const;
	/**
 * @brief Gibt die L�nge der Stra�e zur�ck.
 * @return L�nge als double.
 */
	double getLength()const;
	/**
	* @brief Zeichnet die Stra�e in Rot, z.B. f�r die Visualisierung von Pfaden.
	* @param scene Die QGraphicsScene, auf die gezeichnet wird.
	*/
	virtual void drawRed(QGraphicsScene& scene) const;
protected:
	City* a;
	City* b;
	mutable QGraphicsLineItem* redLineItem = nullptr;  // red �izim i�in
	
};

#endif

