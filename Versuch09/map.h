#ifndef MAP_H
#define MAP_H
#include "abstractmap.h"
/**
 * @class Map
 * @brief Erweiterung von AbstractMap, bietet Methoden zum Zeichnen und Verwalten einer Karte.
 */


class Map :public AbstractMap {
public:
	/**
	* @brief Fügt eine Stadt zur Karte hinzu.
	* @param city Zeiger auf die hinzuzufügende Stadt.
	* 
	*/
	void addCity(City*)override;
	/**
  * @brief Fügt eine Straße zur Karte hinzu.
  * @param street Zeiger auf die hinzuzufügende Straße.
  * @return true, wenn die Straße erfolgreich hinzugefügt wurde.
  */
	bool addStreet(Street*)override;
	/**
 * @brief Sucht eine Stadt anhand ihres Namens.
 * @param cityName Der Name der gesuchten Stadt.
 * @return Zeiger auf die gefundene Stadt oder nullptr, falls nicht gefunden.
 */
	City* findCity(const QString cityName)const override;
	/**
 * @brief Gibt alle Straßen zurück, die mit der angegebenen Stadt verbunden sind.
 * @param city Zeiger auf die Stadt.
 * @return Liste der zugehörigen Straßen.
 */
	QVector<Street*> getStreetList(const City* city)const override;
	/**
 * @brief Gibt die gegenüberliegende Stadt einer Straße zurück.
 * @param street Zeiger auf die Straße.
 * @param city Zeiger auf eine der beiden Städte.
 * @return Zeiger auf die gegenüberliegende Stadt oder nullptr.
 */
	City* getOppositeCity(const Street* street, const City* city)const override;
	/**
 * @brief Berechnet die Länge einer Straße.
 * @param street Zeiger auf die Straße.
 * @return Länge der Straße als double.
 */
	double getLength(const Street* street)const override;
	/**
 * @brief Zeichnet die gesamte Karte auf die übergebene Szene.
 * @param scene Zeiger auf die QGraphicsScene, auf die gezeichnet werden soll.
 */
	void draw(QGraphicsScene& scene) const;

	/**
	 * @brief Gibt die Liste aller Städte zurück.
	 * @return QVector mit Zeigern auf alle Städte.
	 */
	QVector<City*>getCities()const;
	/**
 * @brief Gibt die Liste aller Straßen zurück.
 * @return QVector mit Zeigern auf alle Straßen.
 */
	QVector<Street*> getStreets() const;

private:
	QVector<City*> cities;/**< Liste aller Städte */
	QVector<Street*> streets;/**< Liste aller Straßen */




};
#endif
