#ifndef CITY_H
#define CITY_H
#include <QString>
#include <QGraphicsScene>
class AbstractMap;
/**
 * @class City
 * @brief Repräsentiert eine Stadt mit Name und Koordinaten.
 */
class City {
public:
	/**
	 * @brief Konstruktor der Stadt.
	 * @param name Name der Stadt
	 * @param x X-Koordinate
	 * @param y Y-Koordinate
	 */
	City(QString name, int x, int y);//Konstruktor
	/**
 * @brief Zeichnet die Stadt in die Szene.
 */

	virtual void draw(QGraphicsScene& scene,const AbstractMap*map)const;//draw to scene
	/**
* @brief Gibt den Namen der Stadt zurück.
*/
	QString getname() const;
	/**
 * @brief Gibt die X-Koordinate zurück.
 */
	int getX() const;
	/**
   * @brief Gibt die Y-Koordinate zurück.
   */
	int getY()const;
	double operator-(const City& other) const;
protected:
	int x;
	int y;
	int dx;
	int dy;
	QString name;
private:
	mutable bool drawn = false;

};
#endif

